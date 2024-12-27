import os

def normalize_bbox(x, y, w, h, img_width, img_height):
    """
    정규화된 바운딩 박스 계산
    x, y: 좌상단 좌표
    w, h: 너비와 높이
    """
    x_center = x + w / 2
    y_center = y + h / 2
    x_center_norm = x_center / img_width
    y_center_norm = y_center / img_height
    w_norm = w / img_width
    h_norm = h / img_height
    return x_center_norm, y_center_norm, w_norm, h_norm

def normalize_labels_in_folder(root_folder, img_width, img_height):
    """
    루트 폴더에서 모든 txt 파일을 찾아 정규화
    root_folder: 라벨링 정보가 담긴 폴더의 최상위 경로
    img_width, img_height: 이미지 크기
    """
    for subdir, _, files in os.walk(root_folder):
        for file in files:
            if file.endswith(".txt"):
                txt_path = os.path.join(subdir, file)
                normalized_lines = []

                # TXT 파일 읽기
                with open(txt_path, 'r') as f:
                    for line in f:
                        parts = line.strip().split()
                        class_id, x, y, w, h = int(parts[0]), float(parts[1]), float(parts[2]), float(parts[3]), float(parts[4])
                        x_norm, y_norm, w_norm, h_norm = normalize_bbox(x, y, w, h, img_width, img_height)
                        normalized_lines.append(f"{class_id} {x_norm:.6f} {y_norm:.6f} {w_norm:.6f} {h_norm:.6f}")

                # 원본 파일 덮어쓰기
                with open(txt_path, 'w') as f:
                    f.write("\n".join(normalized_lines))
                print(f"정규화 업데이트 완료: {txt_path}")

# 루트 폴더와 이미지 크기 정의
root_folder = "D:\\시각 장애인 사업 데이터셋\\15. 배송로봇 비도로 운행 데이터\\txt"  # 데이터셋 최상위 폴더
img_width = 2592  # 이미지의 너비
img_height = 2048  # 이미지의 높이

# 정규화 실행
normalize_labels_in_folder(root_folder, img_width, img_height)
