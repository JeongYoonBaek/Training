import os
import pandas as pd
import json

def load_images_from_directory(directory):
    """지정된 디렉토리에서 이미지를 불러옴"""
    image_files = sorted([f for f in os.listdir(directory) if f.endswith('.jpg')])
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

def extract_question_data(json_data, image_id):
    """특정 이미지의 질문 데이터를 추출"""
    question_data = []
 
    for data in json_data:
        for question in data.get("question", []):
            if question["image_id"] == image_id:
                question_object = {
                    'question_id': question.get("question_id", ""),
                    'image_id': question.get("image_id", ""),
                    'question': question.get("question", ""),
                    'answer': question.get("answer", ""),
                    'answer_type': question.get("answer_type", "")
                }
                question_data.append(question_object)
    
    if not question_data:
        print(f"No question data found for image_id: {image_id}")

    df = pd.DataFrame(question_data)
    return df

def get_image_id_from_filename(filename, json_data):
    """이미지 파일명에서 image_id 추출"""
    for data in json_data:
        for image in data.get("images", []):
            if image["image"] == filename:
                return image["image_id"]
    return None

# 이미지 파일 경로와 출력 디렉토리 설정
images_directory = r'D:\\일상생활 작업 및 명령 수행 데이터 \\Training\\어린이 일상생활 이미지\\골목길'
json_files_directory = r'D:\\일상생활 작업 및 명령 수행 데이터 \\Training\\라벨.어린이 생활거주환경 이미지 수집\\골목길'
output_directory = r'D:\\일상생활 작업 및 명령 수행 데이터 \\Training\\어린이 일상생활 이미지\\골목길'

# 출력 디렉토리가 없다면 생성
os.makedirs(output_directory, exist_ok=True)

# 디렉토리에서 이미지 파일 목록 불러오기
image_files = load_images_from_directory(images_directory)
total_frames = len(image_files)
print(f"Total frames found: {total_frames}") 

# 디렉토리에서 JSON 파일 불러오기
json_data = load_json_files(json_files_directory)

# 각 이미지에 대해 질문 데이터 추출 및 저장
for image_file in image_files:
    image_id = get_image_id_from_filename(image_file, json_data)  # 이미지 파일명에서 image_id 추출

    if image_id is None:
        print(f"Warning: No image_id found for file {image_file}")
        continue
    
    # JSON 파일에서 해당 이미지의 질문 데이터 추출
    question_data = extract_question_data(json_data, image_id) 
    
    # 추출된 데이터 확인
    if question_data.empty:
        print(f"No data extracted for image ID: {image_id}")
    else:
        print(f"Data extracted for image ID: {image_id}")

    # 텍스트 파일로 저장 (이미지 이름과 동일하게)
    txt_filename = os.path.splitext(image_file)[0] + '.txt'
    txt_file_path = os.path.join(output_directory, txt_filename)  # 저장할 경로와 파일 이름 설정
    with open(txt_file_path, 'w', encoding='utf-8') as txt_file:
        for index, row in question_data.iterrows():
            txt_file.write(f"Question ID: {row['question_id']}\n")
            txt_file.write(f"Question: {row['question']}\n")
            txt_file.write(f"Answer: {row['answer']}\n")
            txt_file.write(f"Answer Type: {row['answer_type']}\n\n")

    print(f"Question data saved to {txt_file_path}")
