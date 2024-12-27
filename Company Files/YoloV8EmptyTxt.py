import os

# 경로 설정
image_dir = r'C:\Users\kiot\yolov8\Andong(10-1)\images\train'  # 실제 이미지 폴더 경로
train_txt_path = r'C:\Users\kiot\yolov8\Andong(10-1)\train.txt'  # train.txt 경로

# 이미지 디렉토리 내 실제 파일 이름 가져오기
# 확장자를 포함한 이미지 파일 이름 집합 생성
existing_images = {os.path.basename(img) for img in os.listdir(image_dir) if img.endswith(('.jpg', '.png'))}

# train.txt 파일 읽기
with open(train_txt_path, 'r') as file:
    lines = file.readlines()

# train.txt에서 실제 존재하는 이미지 경로만 필터링
updated_lines = [
    line for line in lines
    if os.path.basename(line.strip()) in existing_images
]

# train.txt 업데이트
with open(train_txt_path, 'w') as file:
    file.writelines(updated_lines)

print(f"train.txt가 업데이트되었습니다. 총 {len(updated_lines)}개의 이미지 경로가 포함되었습니다.")
