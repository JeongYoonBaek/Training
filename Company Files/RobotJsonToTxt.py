import os
import pandas as pd
import json

# JSON 파일 경로
cvat_annotation_file = 'D:\\시각 장애인 사업 데이터셋\\15. 배송로봇 비도로 운행 데이터\\label'

# YOLO 포맷을 저장할 디렉토리
yolo_annotation_dir = 'D:\\시각 장애인 사업 데이터셋\\15. 배송로봇 비도로 운행 데이터\\txt'

# 클래스 ID 매핑
class_mapping = {
    'vehicle': 0,
    'motorcycle': 1,
    'bycle': 2,
    'twowheeler': 3,
    'pedestrian': 4,
    'bus': 5,
    'truck': 6, 
    'other_dynamic': 7,
    'other_static': 8,
    'trafficsign': 9,
    'trafficlight': 10,
    'road': 11,
    'sidewalk': 12,
    'crosswalk': 13,
    'wall': 14,
    'floor': 15,
    'stone': 16,
    'obstacle': 17,
    'buliding': 18,
    'vegetation': 19,
    'glasswall': 20,
    'void': 21
}

def load_json_files(dir):
    json_files = [os.path.join(dir, f) for f in os.listdir(dir) if f.endswith('.json')]
    data = []
    for file_path in json_files:
        try:
            with open(file_path, 'r', encoding='utf-8') as file:
                data.append(json.load(file))
        except json.JSONDecodeError as e:
            print(f"Error decoding JSON from {file_path} : {e}")
        except Exception as e:
            print(f"Error reading {file_path} : {e}")
    return data

def extract_frame_data(data):
    frame_objects = []

    info = data.get("info", {}) 
    image_file = info.get("filename", "")

    annotations = data.get("annotation", [])
    for annotation in annotations:
        class_type = annotation.get("class_type", "")
        class_id = class_mapping.get(class_type, -1)
        if class_id == -1:
            continue  # 정의되지 않은 Label은 무시

        # bbox 정보 추출
        box = annotation.get("box", {})
        x_min = box.get("left", 0)
        y_min = box.get("top", 0)
        x_max = x_min + box.get("width", 0)
        y_max = y_min + box.get("height", 0)
        bbox_coordinates = [x_min, y_min, x_max, y_max]

        frame_object = {
            'class_id': class_id,
            'box': bbox_coordinates
        }
        frame_objects.append(frame_object)

    df = pd.DataFrame(frame_objects)
    return df, image_file

# 출력 디렉토리가 없다면 생성
os.makedirs(yolo_annotation_dir, exist_ok=True)

# JSON 파일 불러오기
json_data = load_json_files(cvat_annotation_file)

# 각 이미지 파일에 대해 처리
for data in json_data:
    all_frame_data, image_file = extract_frame_data(data)
    
    if not image_file:  # 이미지 파일명이 없을 경우 다음으로 건너뜀
        continue

    # 텍스트 파일로 저장
    image_id = os.path.splitext(image_file)[0]  # 확장자를 제거한 이미지 파일명 사용
    txt_file_path = os.path.join(yolo_annotation_dir, f'{image_id}.txt')
    with open(txt_file_path, 'w', encoding='utf-8') as txt_file:
        for index, row in all_frame_data.iterrows():
            bbox_str = ' '.join(map(str, row['box']))  # bbox 값을 문자열로 변환
            txt_file.write(f"{int(row['class_id'])} {bbox_str}\n")

    print(f"Json이 txt 형식으로 변환되었습니다. {txt_file_path}")
