import cv2
import os
import pandas as pd
import json

def extract_frames(video_path, output_dir):
    """비디오 파일에서 프레임을 추출하여 지정된 디렉토리에 저장"""
    cap = cv2.VideoCapture(video_path)
    if not cap.isOpened():
        print(f"Error: Could not open video file {video_path}")
        return 0

    frame_count = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
    success, frame = cap.read()
    count = 0
    
    while success:
        frame_filename = os.path.join(output_dir, f"night_frame3_{count:04d}.jpg")
        try:
            cv2.imwrite(frame_filename, frame)  # 프레임을 이미지 파일로 저장
            if not os.path.exists(frame_filename):
                print(f"Error: Could not save frame to {frame_filename}")
        except Exception as e:
            print(f"Exception occurred while saving frame: {e}")
        success, frame = cap.read()
        count += 1
        if count % 100 == 0:
            print(f"{count} frames extracted")
    
    cap.release()
    print(f"Total {count} frames extracted")
    return count

def load_json_file(file_path):
    """JSON 파일을 불러와서 파이썬 딕셔너리로 변환"""
    with open(file_path, 'r', encoding='utf-8') as file:
        data = json.load(file)
    return data

def extract_frame_data(json_file, frame_number):
    """특정 프레임의 객체 위치 정보와 gender, age 정보를 추출"""
    data = load_json_file(json_file)
    
    annotations = data.get('annotations', [])  # 'annotations' 키에 해당하는 값이 없으면 빈 리스트 반환
    categories = data.get('categories', [])  # 'categories' 키에 해당하는 값이 없으면 빈 리스트 반환
    
    frame_objects = []
    
    # annotations에서 객체 정보 추출
    for annotation in annotations:
        if annotation.get('frame') == frame_number:  # frame 키가 없을 수 있으므로 get 메서드 사용
            bbox = annotation.get('bbox', [])
            object_id = annotation['id']
            
            frame_object = {
                'id': object_id,
                'bbox': bbox,
                'gender': '',  # 초기화한 후에 아래에서 categories에서 채워넣을 것임
                'age': ''      # 초기화한 후에 아래에서 categories에서 채워넣을 것임
            }
            frame_objects.append(frame_object)
    
    # categories에서 gender와 age 정보 추출
    for category in categories:
        object_id = category['id']
        gender = category.get('gender', '')
        age = category.get('age', '')
        
        # frame_objects에서 해당 객체의 gender와 age 정보를 업데이트
        for frame_object in frame_objects:
            if frame_object['id'] == object_id:  # id가 일치하는 경우
                # gender를 0 또는 1로 변환
                gender_numeric = 0 if gender == 'male' else 1
                
                # age를 숫자로 변환
                if age == 'child' or age == 'teenager':
                    age_numeric = 10
                elif age == 'adult':
                    age_numeric = 30
                elif age == 'senior':
                    age_numeric = 50
                else:
                    age_numeric = -1  # 알 수 없는 경우 -1로 설정
                
                frame_object['gender'] = gender_numeric
                frame_object['age'] = age_numeric
    
    df = pd.DataFrame(frame_objects)
    return df

# 비디오 파일 경로와 출력 디렉토리 설정
video_path = r'C:\Users\kiot\Desktop\Traffic\night(20~24)\video\2021-08-01_20-09-00_sun_sunny_out_ja-ma_C0041.mp4'
frames_output_dir = r'C:\Users\kiot\Desktop\Traffic\night(20~24)\frame3'
json_file_path = r'C:\Users\kiot\Desktop\Traffic\night(20~24)\json\2021-08-01_20-09-00_sun_sunny_out_ja-ma_C0041.json'
output_directory = r'C:\Users\kiot\Desktop\Traffic\night(20~24)\frame3'

# 출력 디렉토리가 없다면 생성
os.makedirs(frames_output_dir, exist_ok=True)
os.makedirs(output_directory, exist_ok=True)

# 비디오에서 프레임을 추출
total_frames = extract_frames(video_path, frames_output_dir)
print(f"Total frames extracted: {total_frames}")

# 각 프레임 번호에 대해 처리
for frame_number in range(total_frames):
    # JSON 파일에서 특정 프레임의 객체 위치 정보 추출
    all_frame_data = extract_frame_data(json_file_path, frame_number)
    
    # 텍스트 파일로 저장
    txt_file_path = os.path.join(output_directory, f'frame_{frame_number:04d}.txt')  # 저장할 경로와 파일 이름 설정
    with open(txt_file_path, 'w', encoding='utf-8') as txt_file:
        for index, row in all_frame_data.iterrows():
            bbox_str = ' '.join(map(str, row['bbox']))  # bbox 값을 문자열로 변환
            txt_file.write(f"{row['gender']} {row['age']} {bbox_str}\n")

    print(f"Data saved to {txt_file_path}")
