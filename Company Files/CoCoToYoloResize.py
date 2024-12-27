import json
import os

def coco_to_yolo(coco_json_path, output_txt_path, image_width, image_height):
    # 파일 열기 및 JSON 로드 예외 처리
    try:
        with open(coco_json_path, 'r') as f:
            coco_data = json.load(f)
    except FileNotFoundError:
        print(f"Error: File not found - {coco_json_path}")
        return
    except json.JSONDecodeError:
        print(f"Error: Invalid JSON format in {coco_json_path}")
        return

    # COCO 데이터 유효성 검사
    if 'annotations' not in coco_data or 'categories' not in coco_data:
        print("Error: Missing required keys ('annotations', 'categories') in COCO JSON.")
        return

    # 출력 경로 디렉토리 확인 및 생성
    os.makedirs(os.path.dirname(output_txt_path), exist_ok=True)

    yolo_data = []

    for annotation in coco_data['annotations']:
        if not annotation.get('segmentation'):
            continue

        # segmentation이 리스트인지 확인
        if not isinstance(annotation['segmentation'], list) or not annotation['segmentation'][0]:
            print(f"Invalid segmentation format in annotation ID {annotation['id']}")
            continue

        # segmentation의 첫 번째 항목 가져오기
        segmentation = annotation['segmentation'][0]  # 폴리곤 좌표 (리스트 형식)

        # x와 y 좌표 분리
        x_coords = segmentation[0::2]
        y_coords = segmentation[1::2]

        # 최소 및 최대 좌표 계산
        xmin = min(x_coords)
        xmax = max(x_coords)
        ymin = min(y_coords)
        ymax = max(y_coords)

        # 바운딩 박스 계산 후 정규화
        x_center = (xmin + xmax) / 2 / image_width
        y_center = (ymin + ymax) / 2 / image_height
        width = (xmax - xmin) / image_width
        height = (ymax - ymin) / image_height

        # YOLO 형식으로 추가
        class_id = annotation['category_id'] - 1  # YOLO는 class_id를 0부터 시작
        yolo_data.append(f"{class_id} {x_center:.6f} {y_center:.6f} {width:.6f} {height:.6f}")
    
    # YOLO 형식으로 파일 저장
    try:
        with open(output_txt_path, 'w') as f:
            for line in yolo_data:
                f.write(line + '\n')
        print(f"YOLO formatted data saved to {output_txt_path}")
    except Exception as e:
        print(f"Error writing to file {output_txt_path}: {e}")

# 사용 예시
coco_json_path = "C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test\\test\\annotations\\instances_default.json"  # COCO JSON 파일 경로
output_txt_path = "C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test\\test\\Yolo_output.txt"       # YOLO 형식 결과 파일 경로
image_width = 1920                  # 이미지 가로 크기
image_height = 1080                 # 이미지 세로 크기

coco_to_yolo(coco_json_path, output_txt_path, image_width, image_height)
