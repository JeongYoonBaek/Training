import cv2
import os

# 동영상 파일 경로
video_path = r'D:\Cycle\Osan-9\Video\MOV00075.AVI'

# 이미지 저장 경로
output_dir = r'D:\Cycle\Osan-9\Image2'
os.makedirs(output_dir, exist_ok=True)

# 비디오 캡처 객체 생성
cap = cv2.VideoCapture(video_path)

# 비디오 파일이 열렸는지 확인
if not cap.isOpened():
    print(f"동영상 파일을 열 수 없습니다. 경로를 확인하세요: {video_path}")
    exit()

# FPS 설정 (초당 10 프레임 저장)
desired_fps = 10

# 비디오 정보 가져오기
video_fps = cap.get(cv2.CAP_PROP_FPS)
if video_fps == 0:
    print("비디오 FPS 정보를 가져올 수 없습니다. 파일을 확인하세요.")
    exit()

frame_interval = int(video_fps / desired_fps)

# 총 프레임 수
total_frames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
print(f"총 프레임 수: {total_frames}, FPS: {video_fps}")

# 저장할 이미지 수 (5분간 저장할 경우)
max_images = 3000

# 프레임 저장 루프
frame_count = 0
image_count = 0

while cap.isOpened():
    ret, frame = cap.read()

    # 프레임 읽기가 성공했을 때만 실행
    if not ret:
        print("프레임을 읽을 수 없습니다. 동영상 파일이 끝났거나 오류가 발생했습니다.")
        break

    # 프레임이 유효한지 확인
    if frame is None:
        print(f"프레임을 제대로 읽지 못했습니다. frame_count: {frame_count}")
        continue

    # 프레임 크기 확인 (디버깅용)
    if frame_count % frame_interval == 0:
        print(f"프레임 크기: {frame.shape} (frame count: {frame_count})")

        # 프레임을 원하는 FPS로 저장 (필요한 프레임 간격마다 저장)
        image_path = os.path.join(output_dir, f'frame_{image_count:04d}.jpg')
        success = cv2.imwrite(image_path, frame)

        if success:
            print(f"이미지 저장 성공: {image_path}")
            image_count += 1
        else:
            print(f"이미지 저장 실패: {image_path}")

    frame_count += 1

    # 3000장 이상의 이미지 저장을 중단
    if image_count >= max_images:
        print(f"3000장의 이미지를 모두 저장했습니다.")
        break

# 캡처 객체와 창 닫기
cap.release()
cv2.destroyAllWindows()

print(f'총 {image_count}장의 이미지를 저장했습니다.')
