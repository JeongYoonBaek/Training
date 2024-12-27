import xml.etree.ElementTree as ET
import os
import json

# 원본 XML 파일 경로
source_xml = "C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test\\Surface_002\\annotations\\16_SM0915_02.xml"
output_dir = "C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test\\Surface_002\\annotations"

# 출력 폴더 생성
os.makedirs(output_dir, exist_ok=True)

# COCO 포맷을 위한 초기 설정
coco_data = {
    "images": [],
    "annotations": [],
    "categories": []
}

# 라벨 카테고리 매핑 설정 (이 예시에서는 3개 라벨을 사용합니다)
label_mapping = {
    "caution_zone": 1,
    "roadway": 2,
    "braille_guide_blocks": 3,
    "alley" : 4,
    "sidewalk" : 5, 
    "bike_lane" : 6
}

annotation_id = 1  # 어노테이션 ID

# XML 읽기
tree = ET.parse(source_xml)
root = tree.getroot()

# 이미지 및 폴리곤 정보 처리
for image in root.findall("image"):
    # 이미지 이름 및 크기 가져오기
    filename = image.get("name")
    width = int(image.get("width"))
    height = int(image.get("height"))

    # COCO 포맷의 이미지 항목 추가
    image_info = {
        "id": int(image.get("id")),
        "file_name": filename,
        "width": width,
        "height": height
    }
    coco_data["images"].append(image_info)

    # 폴리곤 객체 정보 추가
    for polygon in image.findall("polygon"):
        label = polygon.get("label")
        points = polygon.get("points")
        # 좌표 변환 (points 문자열을 리스트로 변환)
        points_list = [list(map(float, point.split(','))) for point in points.split(';')]

        # 어노테이션 항목 추가
        annotation_info = {
            "id": annotation_id,
            "image_id": int(image.get("id")),
            "category_id": label_mapping.get(label, 0),  # 미정의된 라벨은 0으로 설정
            "segmentation": [sum(points_list, [])],  # COCO segmentation 형식에 맞춰 평탄화
            "iscrowd": 0  # 객체가 군중인 경우는 1로 설정, 그렇지 않으면 0
        }

        coco_data["annotations"].append(annotation_info)
        annotation_id += 1

# COCO 형식 JSON 파일 저장
json_output_path = os.path.join(output_dir, "instances_annotations_coco.json")
with open(json_output_path, "w") as json_file:
    json.dump(coco_data, json_file, indent=4)

print("XML을 COCO 포맷으로 변환하여 저장 완료!")
