import os
import pandas as pd
import json

def load_images_from_directory(directory):
    """지정된 디렉토리에서 이미지를 불러옴"""
    try:
        all_files = os.listdir(directory)
        print(f"All files in directory: {all_files}")
        image_files = sorted([f for f in all_files if f.endswith('.jpg')])
        print(f"Image files: {image_files}")
        return image_files
    except Exception as e:
        print(f"Error loading images: {e}")
        return []

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
    
def extract_frame_data(json_data, frame_filename):
    """특정 프레임의 객체 위치 정보를 추출"""
    frame_objects = []
    class_mapping = {}  # label_id에 따른 클래스 ID 매핑을 저장할 딕셔너리
    
    print(f"Processing frame: {frame_filename}")
   
    for data in json_data:
        info = data.get("info", {})
        image_id = info.get("image_id", "")
        filename = info.get("filename", "")
        
        if filename == frame_filename:
            print(f"Found matching frame for {frame_filename}")
            for annotation in data.get("annotations", []):
                if annotation.get("annotation_type") == "bbox":
                    bbox = annotation.get("annotation_info", [])
                    if bbox:
                        bbox_flat = [point for coord in bbox for point in coord]
                        label_id = annotation.get("label_id", "")
                        
                        # label_id에 대한 클래스 ID 매핑
                        if label_id not in class_mapping:
                            class_mapping[label_id] = len(class_mapping)  # 새로운 label_id가 나타날 때마다 클래스 ID 부여
                        
                        class_id = class_mapping[label_id]
                        
                        frame_object = {
                            'id': annotation.get("annotation_id", ""),
                            'bbox': bbox_flat,
                            'class': class_id
                        }
                        frame_objects.append(frame_object)
    
    df = pd.DataFrame(frame_objects)
    return df, class_mapping

# 이미지 파일 경로와 출력 디렉토리 설정
images_directory = r'D:\시각 장애인 사업 데이터셋\보행 안전 도로 시설물\원천데이터\TS1\01. Bollard_스테인리스\\1.bad'
json_files_directory = r'D:\시각 장애인 사업 데이터셋\보행 안전 도로 시설물\라벨링데이터\TL1\01. Bollard_스테인리스\\1.bad'
output_directory = r'D:\시각 장애인 사업 데이터셋\보행 안전 도로 시설물\원천데이터\TS1\01. Bollard_스테인리스\\1.bad'

# 출력 디렉토리가 없다면 생성
os.makedirs(output_directory, exist_ok=True)

# 디렉토리에서 이미지 파일 목록 불러오기
image_files = load_images_from_directory(images_directory)
total_frames = len(image_files)
print(f"Total frames found: {total_frames}")

# 디렉토리에서 JSON 파일 불러오기
json_data = load_json_files(json_files_directory)

# 각 프레임 번호에 대해 처리
for image_file in image_files:
    frame_filename = image_file  # 확장자를 포함한 이미지 파일 이름 사용
    print(f"Processing {frame_filename}")
    
    # JSON 파일에서 특정 프레임의 객체 위치 정보 추출
    all_frame_data, class_mapping = extract_frame_data(json_data, frame_filename)
    
    # 텍스트 파일로 저장 (이미지 이름과 동일하게)
    txt_filename = os.path.splitext(frame_filename)[0] + '.txt'
    txt_file_path = os.path.join(output_directory, txt_filename)  # 저장할 경로와 파일 이름 설정
    with open(txt_file_path, 'w', encoding='utf-8') as txt_file:
        if not all_frame_data.empty:
            for index, row in all_frame_data.iterrows():
                bbox_str = ' '.join(map(str, row['bbox']))  # bbox 값을 문자열로 변환
                txt_file.write(f"{int(row['class'])} {bbox_str}\n")
        else:
            txt_file.write("")

    print(f"Data saved to {txt_file_path}")
    print("Class mapping:")
    print(class_mapping)
