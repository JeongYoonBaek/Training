import xml.etree.ElementTree as ET
import json
import os

# XML 파일 경로
source_xml = "C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\Polygon_0302\\annotations\\P0921_10.xml"
output_json = "C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\Polygon_0302\\annotations\\instances_default.json"

# COCO JSON 기본 구조 초기화
coco_json = {
    "images": [],
    "annotations": [],
    "categories": []
}

# 라벨 ID 매핑 딕셔너리
label_to_id = {}

# XML 파싱
tree = ET.parse(source_xml)
root = tree.getroot()

annotation_id = 1  # Annotation ID 초기화
category_id = 1  # Category ID 초기화

for image in root.findall("image"):
    # 이미지 정보 가져오기
    file_name = image.get("name")
    width = int(image.get("width"))
    height = int(image.get("height"))
    image_id = len(coco_json["images"]) + 1  # 이미지 ID는 1부터 시작

    # COCO 이미지 정보 추가
    coco_json["images"].append({
        "id": image_id,
        "file_name": file_name,
        "width": width,
        "height": height
    })

    for polygon in image.findall("polygon"):
        # 라벨 및 폴리곤 좌표 가져오기
        label = polygon.get("label")
        points_str = polygon.get("points")
        points = [float(coord) for point in points_str.split(";") for coord in point.split(",")]

        # 라벨 ID 매핑
        if label not in label_to_id:
            label_to_id[label] = category_id
            coco_json["categories"].append({
                "id": category_id,
                "name": label
            })
            category_id += 1

        # 바운딩 박스 계산 (xmin, ymin, xmax, ymax → [x, y, width, height])
        x_coords = points[::2]
        y_coords = points[1::2]
        xmin = min(x_coords)
        ymin = min(y_coords)
        xmax = max(x_coords)
        ymax = max(y_coords)
        bbox = [xmin, ymin, xmax - xmin, ymax - ymin]

        # COCO annotation 추가
        coco_json["annotations"].append({
            "id": annotation_id,
            "image_id": image_id,
            "category_id": label_to_id[label],
            "segmentation": [points],
            "area": (xmax - xmin) * (ymax - ymin),
            "bbox": bbox,
            "iscrowd": 0
        })
        annotation_id += 1

# JSON 파일 저장
os.makedirs(os.path.dirname(output_json), exist_ok=True)
with open(output_json, "w", encoding="utf-8") as f:
    json.dump(coco_json, f, indent=4, ensure_ascii=False)

print(f"JSON 파일이 {output_json}에 저장되었습니다!")
