import cv2
import os

def extract_frames(video_path, output_dir, fps):
    """비디오 파일에서 프레임을 추출하여 지정된 디렉토리에 저장"""
    cap = cv2.VideoCapture(video_path)
    if not cap.isOpened():
        print(f"Error: Could not open video file {video_path}")
        return 0

    # 비디오의 총 프레임 수와 실제 FPS 확인
    video_fps = cap.get(cv2.CAP_PROP_FPS)
    print(f"Video FPS: {video_fps}")

    # 프레임 추출 간격 설정: 원본 FPS에 맞춰 1초에 'fps' 프레임을 추출
    frame_interval = int(video_fps // fps)
    
    # 프레임 추출
    frame_count = 0
    saved_frame_count = 0
    success, frame = cap.read()

    while success:
        # 현재 프레임이 추출 간격에 해당하는 경우에만 저장
        if frame_count % frame_interval == 0:
            # 4자리 패딩을 사용한 파일명 생성
            frame_filename = os.path.join(output_dir, f"GwangAn-173_frame_{saved_frame_count:04d}.jpg")
            if cv2.imwrite(frame_filename, frame):
                print(f"Saved: {frame_filename}")
                saved_frame_count += 1
            else:
                print(f"Error: Could not save frame to {frame_filename}")

        success, frame = cap.read()
        frame_count += 1

    cap.release()
    print(f"Total {saved_frame_count} frames extracted")
    return saved_frame_count

# 비디오 파일 경로와 출력 디렉토리 설정
video_path = r'D:\\GwangAn Subway Video\\173.mp4'
frames_output_dir = r'D:\GwangAn Subway Video\image6'

# 출력 디렉토리가 없다면 생성
os.makedirs(frames_output_dir, exist_ok=True)

# 1초에 3 FPS씩 비디오가 끝날 때까지 프레임을 추출
fps = 3  # 1초당 추출할 프레임 수

# 비디오에서 프레임을 추출
frames_extracted = extract_frames(video_path, frames_output_dir, fps)
print(f"Total frames extracted: {frames_extracted}")
