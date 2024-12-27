import os
import pandas as pd
import json

# 경로 설정
images_directory = r'D:\시각 장애인 사업 데이터셋\보행안전 도로 위험물\image'
json_files_directory = r'D:\시각 장애인 사업 데이터셋\보행안전 도로 위험물\label2'
output_directory = r'D:\시각 장애인 사업 데이터셋\보행안전 도로 위험물\txt2'

# 클래스 ID 매핑
class_mapping = {
    '자동차진입 억제용 말뚝 (bollard)_스테인리스': 0,
    '자동차진입 억제용 말뚝 (bollard)_탄성고무': 1,
    'Bollard_대리석': 2,
    'Bollard_U자형': 3,
    '시선유도봉_2줄': 4,
    '시선유도봉_3줄': 5, 
    '보행자용 방호울타리': 6,
    '교량용 방호울타리': 7,
    '턱낮추기': 8,
    '경사로': 9,
    '점자블럭': 10,
    '(도로안내표지) 지주': 11,
    '보도(시멘트 콘크리트)': 12,
    '보도 블록': 13,
    '자전거 도로': 14,
    '연석': 15,
    '무단횡단 방지 울타리': 16,
    '맨홀': 17,
    '보행자 계단': 18,
    '현장 신호제어기': 19,
    '시각장애인용 음향신호기': 20,
    '과속방지턱': 21,
    '횡단보도': 22,
    '고원식횡단보도': 23,
    '통합표지': 24,
    '정주식,부착식 표지': 25,
    '(가로등) 지주': 26,
    '(전봇대) 빗금표시': 27,
    '소화전': 28,
    '주차멈춤턱_블럭형': 29,
}

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
        info = data.get("info", {})
        if info.get("filename") != image_file:
            continue
        
        annotations = data.get("annotations", [])
        for annotation in annotations:
            label_name = annotation.get("label_name", "")
            annotation_type = annotation.get("annotation_type", "")
            annotation_info = annotation.get("annotation_info", [])
            
            # 라벨 이름을 class id로 변환
            class_id = class_mapping.get(label_name, -1)
            if class_id == -1:
                continue  # 정의되지 않은 Label은 무시
            
            # bbox 정보 추출 (annotation_type이 bbox인 경우에만)
            if annotation_type == "bbox" and annotation_info:
                # bbox 좌표 변환
                bbox = annotation_info[0]  # bbox가 배열로 되어 있는 경우 첫번째 요소만 사용
                x_min, y_min, width, height = bbox
                x_max = x_min + width
                y_max = y_min + height
                bbox_coordinates = [x_min, y_min, x_max, y_max]

                frame_object = {
                    'class': class_id,
                    'bbox': bbox_coordinates
                }
                frame_objects.append(frame_object)
    
    df = pd.DataFrame(frame_objects)
    return df

# 출력 디렉토리가 없다면 생성
os.makedirs(output_directory, exist_ok=True)

# JSON 파일 불러오기
json_data = load_json_files(json_files_directory)

# 각 이미지 파일에 대해 처리
for data in json_data:
    image_file = data["info"]["filename"]
    all_frame_data = extract_frame_data(json_data, image_file)
    
    # 텍스트 파일로 저장
    image_id = os.path.splitext(image_file)[0]  # 확장자를 제거한 이미지 파일명 사용
    txt_file_path = os.path.join(output_directory, f'{image_id}.txt')
    with open(txt_file_path, 'w', encoding='utf-8') as txt_file:
        for index, row in all_frame_data.iterrows():
            bbox_str = ' '.join(map(str, row['bbox']))  # bbox 값을 문자열로 변환
            txt_file.write(f"{int(row['class'])} {bbox_str}\n")

    print(f"Data saved to {txt_file_path}")
