import os
import pandas as pd
import json

def load_images_from_directory(directory):
    """지정된 디렉토리에서 이미지를 불러옴"""
    try:
        image_files = sorted([f for f in os.listdir(directory) if f.endswith('.png')])
        return image_files
    except Exception as e:
        print(f"Error loading images: {e}")
        return []

def load_json_files(directory):
    """지정된 디렉토리에서 JSON 파일을 불러옴"""
    try:
        json_files = [os.path.join(directory, f) for f in os.listdir(directory) if f.endswith('.json')]
        data = []
        for file_path in json_files:
            with open(file_path, 'r', encoding='utf-8') as file: 
                data.append(json.load(file))
        return data
    except Exception as e: 
        print(f"Error loading JSON files: {e}")
        return []

def extract_frame_data(json_data, frame_suffix):
    """특정 프레임의 객체 위치 정보를 추출"""
    frame_objects = []
    category_mapping = {
        "f_i_26": 0,
        "f_i_35": 1,
        "f_i_49": 2,
        "f_i_50": 3
    }

    print(f"Processing frame suffix: {frame_suffix}")  # 디버깅 메시지 추가
    
    for data in json_data:
        for annotation in data.get("annotations", []):
            atch_org_file_name = annotation.get("atchOrgFileName", "")
            print(f"Comparing with JSON atchOrgFileName: {atch_org_file_name}")  # 디버깅 메시지 추가
             
            if atch_org_file_name == frame_suffix: 
                print(f"Found matching frame for {frame_suffix}") 
                boxes = annotation.get("box", [])
                print(f"Total boxes found: {len(boxes)}")  # 디버깅 메시지 추가
                for box_info in boxes: 
                    box = box_info.get('box', {})
                    print(f"Processing box: {box}")  # 디버깅 메시지 추가
                    category_id = box_info.get("category_id", "")
                    print(f"category_id: {category_id}")  # 디버깅 메시지 추가
                    class_id = category_mapping.get(category_id, -1)
                    print(f"Mapped class_id: {class_id}")  # 디버깅 메시지 추가
                    frame_object = { 
                        'bbox': [box.get('x', 0), box.get('y', 0), box.get('w', 0), box.get('h', 0)],
                        'class': class_id
                    }
                    frame_objects.append(frame_object)
                if frame_objects:
                    print(f"Frame objects: {frame_objects}")  # 디버깅 메시지 추가
                    return pd.DataFrame(frame_objects), category_mapping
    print("No matching frame found")  # 디버깅 메시지 추가
    return pd.DataFrame(), category_mapping
  
# 이미지 파일 경로와 출력 디렉토리 설정
images_directory = r'D:\시각 장애인 사업 데이터셋\\1인칭 보행 시점\BBOX\원천데이터\이미지\in\kitchen\Average_stature__in__kitchen__00068.mp4'
json_files_directory = r'D:\시각 장애인 사업 데이터셋\\1인칭 보행 시점\BBOX\라벨링데이터\라벨링데이터_0917_add\Average_stature\in\kitchen\Average_stature__in__kitchen__00068.mp4'
output_directory = r'D:\시각 장애인 사업 데이터셋\\1인칭 보행 시점\BBOX\원천데이터\이미지\in\kitchen\Average_stature__in__kitchen__00068.mp4\txt'

# 출력 디렉토리가 없다면 생성
os.makedirs(output_directory, exist_ok=True)

# 디렉토리에서 이미지 파일 목록 불러오기
image_files = load_images_from_directory(images_directory)
print(f"Total frames found: {len(image_files)}")

# 디렉토리에서 JSON 파일 불러오기
json_data = load_json_files(json_files_directory)

# 각 프레임 번호에 대해 처리 
for image_file in image_files: 
    frame_filename = os.path.basename(image_file)
    # 'Average_stature__in__kitchen__00068__scene00001.png'에서 'scene00001.png' 추출
    frame_suffix = frame_filename.split('__')[-1] 
    print(f"Processing {frame_filename}")
    
    # JSON 파일에서 특정 프레임의 객체 위치 정보 추출
    all_frame_data, category_mapping = extract_frame_data(json_data, frame_suffix)
    
    if all_frame_data.empty: 
        print(f"No data found for {frame_filename}")
    
    # 텍스트 파일로 저장
    txt_filename = os.path.splitext(frame_filename)[0] + '.txt'
    txt_file_path = os.path.join(output_directory, txt_filename)
    with open(txt_file_path, 'w', encoding='utf-8') as txt_file:
        for _, row in all_frame_data.iterrows():
            bbox_str = ' '.join(map(str, row['bbox']))
            txt_file.write(f"{int(row['class'])} {bbox_str}\n")
    
    print(f"Data saved to {txt_file_path}")
    print("Category mapping:")
    print(category_mapping)
