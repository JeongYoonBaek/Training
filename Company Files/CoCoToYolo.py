import json
import os
from PIL import Image

def get_image_dimensions(image_folder):
    """
    폴더 내 모든 이미지 파일의 이름과 크기를 반환합니다.
    
    Args:
        image_folder (str): 이미지 파일이 위치한 폴더 경로.
    
    Returns:
        dict: {이미지 파일 이름: {"width": 너비, "height": 높이}}
    """
    image_dimensions = {}
    for file_name in os.listdir(image_folder):
        file_path = os.path.join(image_folder, file_name)
        if file_name.lower().endswith(('.jpg', '.jpeg', '.png')):
            with Image.open(file_path) as img:
                image_dimensions[file_name] = {"width": img.width, "height": img.height}
    return image_dimensions


def coco_to_yolo(coco_json_path, output_folder_path, image_dimensions, image_folder_path):
    # COCO JSON 파일 읽기
    try:
        with open(coco_json_path, 'r') as f:
            coco_data = json.load(f)
    except FileNotFoundError:
        print(f"Error: File not found - {coco_json_path}")
        return
    except json.JSONDecodeError:
        print(f"Error: Invalid JSON format in {coco_json_path}")
        return

    # 이미지 ID와 파일 이름 매핑 생성
    image_id_to_name = {}
    for image in coco_data['images']:
        # "images/" 접두사 제거
        file_name = image['file_name'].replace('images/', '')
        image_id_to_name[image['id']] = file_name

    os.makedirs(output_folder_path, exist_ok=True)

    for annotation in coco_data['annotations']:
        image_id = annotation.get('image_id')
        image_name = image_id_to_name.get(image_id)

        if not image_name:
            print(f"Warning: Image ID {image_id} not found in COCO 'images'. Skipping.")
            continue 

        # 이미지 파일 존재 여부 확인
        image_path = os.path.join(image_folder_path, image_name)
        if not os.path.exists(image_path):
            print(f"Skipping annotation for image ID {image_id} (Image file {image_name} not found in folder).")
            continue

        # 이미지 크기 가져오기
        if image_name not in image_dimensions:
            print(f"Skipping annotation for image ID {image_id} (Image file {image_name} not found in dimensions).")
            continue

        width = image_dimensions[image_name]["width"]
        height = image_dimensions[image_name]["height"]

        # 세그멘테이션 데이터 안전하게 처리
        if not annotation.get('segmentation') or not annotation['segmentation'][0]:
            continue

        segmentation = annotation['segmentation'][0]
        
        # x와 y 좌표 분리 (홀수/짝수 인덱스)
        x_coords = segmentation[0::2]
        y_coords = segmentation[1::2]

        # 실제 최소/최대 좌표 계산
        xmin = min(x_coords)
        xmax = max(x_coords)
        ymin = min(y_coords)
        ymax = max(y_coords)

        # 이미지 크기로 정규화
        x_center = (xmin + xmax) / (2 * width)
        y_center = (ymin + ymax) / (2 * height)
        box_width = abs(xmax - xmin) / width
        box_height = abs(ymax - ymin) / height

        # 좌표 유효성 검사 및 조정
        def validate_and_adjust_yolo_coordinates(x_center, y_center, width, height):
            """
            YOLO 좌표의 유효성을 검사하고 필요시 조정합니다.
            """
            # 절대값을 취해 너비와 높이의 순서 상관없이 처리
            width = abs(width)
            height = abs(height)

            # 중심점 좌표 유효성 확인
            x_center = max(0, min(x_center, 1))
            y_center = max(0, min(y_center, 1))

            return x_center, y_center, width, height

        x_center, y_center, box_width, box_height = validate_and_adjust_yolo_coordinates(
            x_center, y_center, box_width, box_height
        )

        # 저장 로직
        class_id = annotation['category_id'] - 1  # YOLO는 class_id를 0부터 시작
        yolo_line = f"{class_id} {x_center:.6f} {y_center:.6f} {box_width:.6f} {box_height:.6f}"

        # 이미지별 YOLO 라벨 파일 생성
        output_txt_path = os.path.join(output_folder_path, f"{os.path.splitext(image_name)[0]}.txt")
        with open(output_txt_path, 'a') as f:
            f.write(yolo_line + '\n')

    print(f"YOLO formatted data saved in {output_folder_path}")

# 사용 예시
coco_json_path = "C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test2\\bbox\\test.json"
image_folder_path = "C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test2\\bbox\\image"
output_folder_path = "C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test2\\bbox\\Yolo_labels"

# 이미지 크기 가져오기
image_dimensions = get_image_dimensions(image_folder_path)

# COCO 데이터를 YOLO 형식으로 변환
coco_to_yolo(coco_json_path, output_folder_path, image_dimensions, image_folder_path)
