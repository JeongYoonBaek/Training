import os
from PIL import Image
import numpy as np

input_dir = "D:\\SIMPAC METAL\\test\\obj_train_data"  # 이미지 파일이 있는 디렉터리
output_dir = "D:\\SIMPAC METAL\\test\\obj_train_data"  # 필터링된 이미지를 저장할 디렉터리
os.makedirs(output_dir, exist_ok=True)

# 이미지 파일 확장자 필터링
valid_extensions = (".jpg", ".jpeg", ".png", ".bmp", ".tiff")  # 지원하는 이미지 확장자

for img_file in os.listdir(input_dir):
    img_path = os.path.join(input_dir, img_file)
    # 파일 확장자를 확인하여 이미지 파일만 처리
    if img_file.lower().endswith(valid_extensions):
        try:
            img = Image.open(img_path).convert("L")  # 그레이스케일 변환
            avg_pixel_value = np.mean(np.array(img))  # 픽셀 평균값 계산
            if avg_pixel_value > 10:  # 빈 이미지 기준 (필요시 조정 가능)
                img.save(os.path.join(output_dir, img_file))  # 유효한 이미지만 저장
            else:
                print(f"Empty image detected: {img_file}")
        except Exception as e:
            print(f"Error processing {img_file}: {e}")
    else:
        print(f"Skipped non-image file: {img_file}")
