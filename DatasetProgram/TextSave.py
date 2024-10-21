# JSON을 불러와서 라벨링 정보가 담긴 텍스트 파일 생성 (데이터셋 JSON 구조마다 코드를 수정해줘야 함)
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
        frame_filename = os.path.join(output_dir, f"frame_{count}.jpg")
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
    """특정 프레임의 객체 위치 정보를 추출"""
    data = load_json_file(json_file)
    
    annotations = data.get('annotations', [])  # 'annotations' 키에 해당하는 값이 없으면 빈 리스트 반환
    objects = data.get('objects', [])  # 'objects' 키에 해당하는 값이 없으면 빈 리스트 반환
    
    frame_objects = []
    
    # annotations에서 객체 정보 추출
    for annotation in annotations:
        if annotation.get('frame') == frame_number:  # frame 키가 없을 수 있으므로 get 메서드 사용
            object_id = annotation['id']
            
            # class_id 설정
            if object_id.startswith('person_'):
                class_id = 0
            else:
                continue  # person으로 시작하지 않으면 무시
            
            frame_object = {
                'id': object_id,
                'bbox': annotation['bbox'],
                'class': class_id
            }
            frame_objects.append(frame_object)
    
    # objects에서 객체 정보 추출 (예: car)
    for obj in objects:
        if obj.get('frame') == frame_number:  # frame 키가 없을 수 있으므로 get 메서드 사용
            object_id = obj['id']
            if object_id.startswith('car_'):
                class_id = 1
            else:
                continue  # car로 시작하지 않으면 무시
            
            frame_object = {
                'id': object_id,
                'bbox': obj['bbox'],
                'class': class_id
            }
            frame_objects.append(frame_object)
    
    df = pd.DataFrame(frame_objects)
    return df


# 비디오 파일 경로와 출력 디렉토리 설정
video_path = r'C:\Users\kiot\Yolo V5\yolov5\TS6_sa-bt_2\morning(9~12)\2021-09-08_09-51-00_wed_sunny_out_sa-bt_C0091.mp4'
frames_output_dir = r'C:\Users\kiot\Yolo V5\yolov5\TS6_sa-bt_2\frame1'
json_file_path = r'C:\Users\kiot\Yolo V5\yolov5\TL6_sa-bt_2\morning(9~12)\2021-09-08_09-51-00_wed_sunny_out_sa-bt_C0091.json'
output_directory = r'C:\Users\kiot\Yolo V5\yolov5\TS6_sa-bt_2\frame1\txt'

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
    txt_file_path = os.path.join(output_directory, f'frame_data_{frame_number}.txt')  # 저장할 경로와 파일 이름 설정
    with open(txt_file_path, 'w', encoding='utf-8') as txt_file:
        for index, row in all_frame_data.iterrows():
            bbox_str = ' '.join(map(str, row['bbox']))  # bbox 값을 문자열로 변환
            txt_file.write(f"{int(row['class'])} {bbox_str}\n")

    print(f"Data saved to {txt_file_path}")
