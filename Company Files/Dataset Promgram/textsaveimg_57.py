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
    class_mapping = {}  # obj_name에 따른 클래스 ID 매핑을 저장할 딕셔너리
    
    for data in json_data:
        for annotation in data.get("annotation", []):
            if annotation["image_id"] == frame_filename:
                bbox = annotation.get("bbox", [])
                if bbox:
                    bbox_flat = [point for coord in bbox for point in coord]
                    obj_name = annotation.get("obj_name", "")
                    
                    # obj_name에 대한 클래스 ID 매핑
                    if obj_name not in class_mapping:
                        class_mapping[obj_name] = len(class_mapping)  # 새로운 obj_name이 나타날 때마다 클래스 ID 부여
                    
                    class_id = class_mapping[obj_name]
                    
                    frame_object = {
                        'id': annotation.get("id", ""),
                        'bbox': bbox_flat,
                        'class': class_id
                    }
                    frame_objects.append(frame_object)
    
    df = pd.DataFrame(frame_objects)
    return df, class_mapping

# 이미지 파일 경로와 출력 디렉토리 설정
images_directory = r'D:\\Crowd DataSet\\057.Everyday Life Video\\Data\\Training\\Labeling Data\\viewpoint_1\\age1\\female\\02376'
json_files_directory = r'D:\\Crowd DataSet\\057.Everyday Life Video\\Data\\Training\\Labeling Data\\viewpoint_1\\age1\\female\\02376'
output_directory = r'D:\\Crowd DataSet\\057.Everyday Life Video\\Data\\Training\\Labeling Data\\viewpoint_1\\age1\\female\\02376'

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
    # JSON 파일에서 특정 프레임의 객체 위치 정보 추출
    all_frame_data, class_mapping = extract_frame_data(json_data, image_file)
    
    # 텍스트 파일로 저장 (이미지 이름과 동일하게)
    txt_filename = os.path.splitext(image_file)[0] + '.txt'
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
