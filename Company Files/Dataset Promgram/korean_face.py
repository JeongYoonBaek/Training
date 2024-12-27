import os
import json
import re

def load_images_from_directory(directory):
    """지정된 디렉토리에서 이미지를 불러옴"""
    try:
        all_files = os.listdir(directory)
        print(f"All files in directory: {all_files}")
        image_files = sorted([f for f in all_files if f.endswith('.png')])
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

def safe_filename(filename):
    """파일 이름을 안전하게 변환"""
    return re.sub(r'[\\/*?:"<>|]', "", filename)

def convert_age(age):
    if age == "20s":
        return "20"
    elif age == "30s":
        return "30"
    elif age == "over40s":
        return "40"
    return age

def extract_and_save_data(json_data, image_files, output_directory):
    """JSON 데이터에서 필요한 정보를 추출하고 텍스트 파일로 저장"""
    for entry, image_file in zip(json_data, image_files):
        try:
            # 이미지 파일 이름에서 정보 추출
            filename = os.path.splitext(image_file)[0]
            filename_parts = filename.split('_')
            if len(filename_parts) < 4:
                print(f"Invalid filename format: {image_file}")
                continue
            
            # 필요한 정보 추출
            gender = filename_parts[2]
            gender_code = 0 if gender == "N" else 1
            
            age = entry.get("label_gt", {}).get("metadata", {}).get("age", "")
            age = convert_age 
            
            # annot_A의 바운딩 박스 좌표 추출
            bbox = entry.get("label_gt", {}).get("box", {})
            minX = bbox.get("x", "") 
            minY = bbox.get("y", "")
            maxX = minX + bbox.get("w", 0)  # x 좌표 + 너비
            maxY = minY + bbox.get("h", 0)  # y 좌표 + 높이
            
            # 파일 이름을 안전하게 변환
            safe_name = safe_filename(filename)
            
            # 텍스트 파일로 저장 (이미지 이름과 동일하게)
            txt_filename = safe_name + '.txt'
            txt_file_path = os.path.join(output_directory, txt_filename)
            
            with open(txt_file_path, 'w', encoding='utf-8') as txt_file:
                txt_file.write(f"{gender_code} {age} {minX} {minY} {maxX} {maxY}")
            
            print(f"Data saved to {txt_file_path}") 
        
        except Exception as e:
            print(f"Error processing entry: {e}")

# 이미지 파일 경로와 출력 디렉토리 설정
images_directory = r'C:\\Users\\kiot\\Desktop\\Korean face\\Source Data\\G'
json_files_directory = r'C:\\Users\\kiot\\Desktop\\Korean face\\Labeling Data\\G'
output_directory = r'C:\\Users\\kiot\\Desktop\\Korean face\\Source Data\\G'

# 출력 디렉토리가 없다면 생성
os.makedirs(output_directory, exist_ok=True)

# 디렉토리에서 이미지 파일 목록 불러오기
image_files = load_images_from_directory(images_directory)
total_frames = len(image_files)
print(f"Total frames found: {total_frames}")

# 디렉토리에서 JSON 파일 불러오기
json_data = load_json_files(json_files_directory)

# 필요한 정보를 추출하고 텍스트 파일로 저장
extract_and_save_data(json_data, image_files, output_directory)
