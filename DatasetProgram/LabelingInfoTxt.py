# 라벨링 이미지들을 불러와서 라벨링 정보들이 담긴 TXT 추출하는 코드
import os
import pandas as pd
import json

# Label과 class id 매핑 정의
LABEL_TO_CLASS_ID = {
    "벽": 0,
    # 다른 Label에 대한 class id 추가
}

def load_images_from_directory(directory):
    """지정된 디렉토리에서 이미지를 불러옴"""
    image_files = sorted([f for f in os.listdir(directory) if f.endswith(('.jpg', '.png'))])
    return image_files

def load_json_files(directory):
    """지정된 디렉토리에서 JSON 파일을 모두 불러와서 파이썬 딕셔너리로 변환"""
    json_files = [os.path.join(directory, f) for f in os.listdir(directory) if f.endswith('.json')]
    data = []
    for file_path in json_files:
        try:
            with open(file_path, 'r', encoding='utf-8') as file:
                data.append(json.load(file))
        except json.JSONDecodeError as e:
            print(f"Error decoding JSON from {file_path}: {e}")
        except Exception as e:
            print(f"Error reading {file_path}: {e}")
    return data

def extract_frame_data(json_data, image_file):
    """특정 이미지의 객체 위치 정보를 추출"""
    frame_objects = []
    
    for data in json_data:
        image_info = data.get("Image_Info", {})
        if image_info.get("ImageFileName") != image_file:
            continue
        
        seg_info = image_info.get("Seg_Info", [])
        for seg in seg_info:
            label = seg.get("Label", "")
            points = seg.get("Point", [])
            if not points:
                continue
            
            # Label에 따른 class id 설정
            class_id = LABEL_TO_CLASS_ID.get(label, -1)  # 매핑에 없는 Label은 class id -1로 설정
            if class_id == -1:
                continue  # 정의되지 않은 Label은 무시
 
            bbox = [points[0][0], points[0][1], points[-1][0], points[-1][1]]  # 좌표를 바운딩 박스로 변환
            
            frame_object = {
                'class': class_id,
                'bbox': bbox
            }
            frame_objects.append(frame_object)
    
    df = pd.DataFrame(frame_objects)
    return df  

# 이미지 파일 경로와 출력 디렉토리 설정
images_directory = r'D:\\Crowd DataSet\\139.일상생활 작업 및 명령 수행 데이터(공간)\\Open Data\\Data\\Training\\Source Data\\TS\\CC301S009\\RGB'
json_files_directory = r'D:\\Crowd DataSet\\139.일상생활 작업 및 명령 수행 데이터(공간)\\Open Data\\Data\\Training\\Labeling Data\\TL\\CC301S009'
output_directory = r'D:\\Crowd DataSet\\139.일상생활 작업 및 명령 수행 데이터(공간)\\Open Data\\Data\\Training\\Source Data\\TS\\CC301S009\\RGB'

# 출력 디렉토리가 없다면 생성
os.makedirs(output_directory, exist_ok=True)

# 디렉토리에서 이미지 파일 목록 불러오기 
image_files = load_images_from_directory(images_directory)
total_images = len(image_files)
print(f"Total images found: {total_images}")

# 디렉토리에서 JSON 파일 불러오기
json_data = load_json_files(json_files_directory)

# 각 이미지 파일에 대해 처리
for image_file in image_files:
    all_frame_data = extract_frame_data(json_data, image_file)
    
    # 텍스트 파일로 저장
    image_id = os.path.splitext(image_file)[0]  # 확장자를 제거한 이미지 파일명 사용
    txt_file_path = os.path.join(output_directory, f'{image_id}.txt')
    with open(txt_file_path, 'w', encoding='utf-8') as txt_file:
        for index, row in all_frame_data.iterrows():
            bbox_str = ' '.join(map(str, row['bbox']))  # bbox 값을 문자열로 변환
            txt_file.write(f"{int(row['class'])} {bbox_str}\n")

    print(f"Data saved to {txt_file_path}")
