import os
import glob

# 폴더 경로
image_dir = r'C:\Users\kiot\yolov8\Andong(10-1)\images\train'
txt_dir = r'C:\Users\kiot\yolov8\Andong(10-1)\labels\train'

# 이미지 파일 확장자 목록
image_ext = ['.jpg', '.png']

# 모든 텍스트 파일 경로 가져오기
txt_files = glob.glob(os.path.join(txt_dir, '*.txt'))

# 텍스트 파일 이름(확장자 제거)을 기준으로 셋 생성
txt_file_names = {os.path.splitext(os.path.basename(txt))[0] for txt in txt_files}

# 이미지 파일 경로 가져오기
image_files = []
for ext in image_ext:
    image_files.extend(glob.glob(os.path.join(image_dir, f'*{ext}')))

# 이미지 파일 처리
for image_path in image_files:
    # 이미지 파일 이름(확장자 제거)
    image_name = os.path.splitext(os.path.basename(image_path))[0]

    # 텍스트 파일과 이름이 일치하지 않는 이미지 삭제
    if image_name not in txt_file_names:
        os.remove(image_path)
        print(f'{image_path} 이미지 파일이 삭제되었습니다.')
