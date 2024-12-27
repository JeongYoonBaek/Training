import cv2
import os

def extract_frames(video_path, output_dir):
    # 비디오 캡처 객체 생성
    cap = cv2.VideoCapture(video_path)
    
    # 출력 디렉토리가 없다면 생성
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    
    frame_count = 0
    
    while True:
        # 비디오에서 프레임을 읽음
        ret, frame = cap.read()
        
        if not ret:
            break
        
        # 프레임 저장
        frame_filename = os.path.join(output_dir, f"frame_{frame_count:04d}.jpg")
        cv2.imwrite(frame_filename, frame)
        
        frame_count += 1
    
    # 비디오 캡처 객체 해제
    cap.release()
    print(f"총 {frame_count}개의 프레임을 추출했습니다.")

# 비디오 파일 경로와 출력 디렉토리 경로 설정
video_path = r'C:\\Users\\kiot\\Yolo V5\\yolov5\\Traffic\\night(20~24)\\video\\2021-08-01_20-18-00_sun_sunny_out_ja-ma_C0041.mp4'
output_dir = r'C:\\Users\\kiot\Yolo V5\\yolov5\\Traffic\\night(20~24)\\frame5'

# 프레임 추출 함수 호출
extract_frames(video_path, output_dir)
