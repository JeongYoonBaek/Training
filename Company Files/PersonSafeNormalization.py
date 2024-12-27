import os

def normalize_bboxes(txt_folder, img_width, img_height):
    for txt_file in os.listdir(txt_folder):
        if txt_file.endswith(".txt"):
            txt_file_path = os.path.join(txt_folder, txt_file)
            
            with open(txt_file_path, 'r') as file:
                lines = file.readlines()

            normalized_lines = []

            for line in lines:
                parts = line.strip().split()

                try:
                    class_id = parts[0]
                    x_min = float(parts[1])
                    y_min = float(parts[2])
                    x_max = float(parts[3])
                    y_max = float(parts[4])

                    # 좌표 값 제한 (이미지 크기 내로)
                    x_min = max(0, min(x_min, img_width))
                    y_min = max(0, min(y_min, img_height))
                    x_max = max(0, min(x_max, img_width))
                    y_max = max(0, min(y_max, img_height))

                    # 잘못된 바운딩 박스 확인 및 건너뛰기
                    if x_min >= x_max or y_min >= y_max:
                        print(f"잘못된 바운딩 박스: x_min: {x_min}, y_min: {y_min}, x_max: {x_max}, y_max: {y_max}")
                        continue

                    # 정규화
                    x_min_norm = x_min / img_width
                    y_min_norm = y_min / img_height
                    x_max_norm = x_max / img_width
                    y_max_norm = y_max / img_height

                    # YOLO 포맷으로 변환
                    x_center = (x_min_norm + x_max_norm) / 2
                    y_center = (y_min_norm + y_max_norm) / 2
                    width = x_max_norm - x_min_norm
                    height = y_max_norm - y_min_norm

                    if width <= 0 or height <= 0:
                        print(f"너비 또는 높이가 0 이하: {width}, {height}")
                        continue

                    normalized_line = f"{class_id} {x_center:.6f} {y_center:.6f} {width:.6f} {height:.6f}\n"
                    normalized_lines.append(normalized_line)

                except ValueError as e:
                    print(f"오류 발생: {e} - 라인: {line.strip()}")
                    continue

            with open(txt_file_path, 'w') as file:
                file.writelines(normalized_lines)

            print(f"정규화 업데이트 :  {txt_file}")

# 이미지 크기
img_width = 2592
img_height = 4608

# 라벨링 파일들이 저장된 폴더 경로
txt_folder = "D:\\시각 장애인 사업 데이터셋\\보행안전 도로 위험물\\txt"

normalize_bboxes(txt_folder, img_width, img_height)
