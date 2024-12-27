import os
import json
import re

def load_images_from_directory(directory):
    """지정된 디렉토리에서 이미지를 불러옴"""
    try:
        all_files = os.listdir(directory)
        print(f"All files in directory: {all_files}")
        image_files = sorted([f for f in all_files if f.endswith('.JPG')])
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

def extract_and_save_data(json_data, output_directory):
    """JSON 데이터에서 필요한 정보를 추출하고 텍스트 파일로 저장"""
    for entry in json_data:
        filename = entry.get("filename", "")
        
        for member in entry.get("member", []):
            personal_id = member.get("personal_id", "")
            age = member.get("age", "")
            
            # personal_id를 1 또는 0으로 변환
            if personal_id in ["GF", "F", "S"]:
                personal_id_code = 0
            elif personal_id in ["GM", "M", "D"]:
                personal_id_code = 1
            else:
                personal_id_code = "unknown" 
        
            # regions에서 boundingbox 정보 추출
            for region in member.get("regions", []):
                boundingboxes = region.get("boundingbox", [])
                for bbox in boundingboxes:
                    if bbox.get("idx") == "0":  # idx가 "0"인 항목만 처리
                        minX = bbox.get("x", "0")
                        minY = bbox.get("y", "0")
                        maxX = bbox.get("w", "0")
                        maxY = bbox.get("h", "0")
                        
                        # 파일 이름을 안전하게 변환
                        safe_name = safe_filename(filename)
                        
                        # 텍스트 파일로 저장 (이미지 이름과 동일하게)
                        txt_filename = safe_name + '.txt'
                        txt_file_path = os.path.join(output_directory, txt_filename)
                        
                        with open(txt_file_path, 'a', encoding='utf-8') as txt_file:  # 'a' 모드를 사용하여 덧붙이기
                            txt_file.write(f"{personal_id_code} {age} {minX} {minY} {maxX} {maxY}\n")
                        
                        print(f"Data saved to {txt_file_path}")

# 이미지 파일 경로와 출력 디렉토리 설정
images_directory = r'D:\\Gender, Age DataSet\\045.가족 관계가 알려진 얼굴 이미지 데이터\\01.데이터\\1.Training\\원천데이터_0903_add\\TS0001to0020\\TS0006\A(친가)\\3.Age'
json_files_directory = r'D:\\Gender, Age DataSet\\045.가족 관계가 알려진 얼굴 이미지 데이터\\01.데이터\\1.Training\\라벨링데이터_0930_add\\TL0006\\A(친가)\\3.Age'
output_directory = r'D:\\Gender, Age DataSet\\045.가족 관계가 알려진 얼굴 이미지 데이터\\01.데이터\\1.Training\\원천데이터_0903_add\\TS0001to0020\\TS0006\A(친가)\\3.Age'

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
