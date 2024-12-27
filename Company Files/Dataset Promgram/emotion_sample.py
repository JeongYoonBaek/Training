import os
import json
import re

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
                data.extend(json.load(file))
        except json.JSONDecodeError as e:
            print(f"Error decoding JSON from {file_path}: {e}")
        except Exception as e:
            print(f"Error reading {file_path}: {e}")
    return data

def safe_filename(filename):
    """파일 이름을 안전하게 변환"""
    return re.sub(r'[\\/*?:"<>|]', "", filename)

def extract_and_save_data(json_data, output_directory):
    """JSON 데이터에서 필요한 정보를 추출하고 텍스트 파일로 저장"""
    for entry in json_data:
        filename = entry.get("filename", "")
        age = entry.get("age", "")
        
        # gender 속성 해석
        gender = entry.get("gender", "")
        if gender == "\ub0a8":
            gender_code = 0 
        elif gender == "\uc5ec":
            gender_code = 1
        else:
            gender_code = -1  # 예외 처리 등을 고려해 -1 또는 다른 처리를 할 수 있음
        
        # annot_A의 바운딩 박스 좌표 추출
        bbox = entry.get("annot_A", {}).get("boxes", {})
        minX = bbox.get("minX", "")
        minY = bbox.get("minY", "")
        maxX = bbox.get("maxX", "")
        maxY = bbox.get("maxY", "")
        
        # 파일 이름을 안전하게 변환
        safe_name = safe_filename(filename)
        
        # 텍스트 파일로 저장 (이미지 이름과 동일하게)
        txt_filename = safe_name + '.txt'
        txt_file_path = os.path.join(output_directory, txt_filename)
        
        with open(txt_file_path, 'w', encoding='utf-8') as txt_file:
            txt_file.write(f"{gender_code} {age} {minX} {minY} {maxX} {maxY}")
        
        print(f"Data saved to {txt_file_path}")
        
# 이미지 파일 경로와 출력 디렉토리 설정
images_directory = r'C:\\Users\\kiot\\Desktop\\Korean emotion\\Source Data\\EMOIMG_상처_SAMPLE'
json_files_directory = r'C:\\Users\\kiot\\Desktop\\Korean emotion\\Labeling Data\\EMOIMG_상처_SAMPLE'
output_directory = r'C:\\Users\\kiot\\Desktop\\Korean emotion\\Source Data\\EMOIMG_상처_SAMPLE'

# 출력 디렉토리가 없다면 생성
os.makedirs(output_directory, exist_ok=True)

# 디렉토리에서 이미지 파일 목록 불러오기
image_files = load_images_from_directory(images_directory)
total_frames = len(image_files)
print(f"Total frames found: {total_frames}")

# 디렉토리에서 JSON 파일 불러오기
json_data = load_json_files(json_files_directory)

# 필요한 정보를 추출하고 텍스트 파일로 저장
extract_and_save_data(json_data, output_directory)
