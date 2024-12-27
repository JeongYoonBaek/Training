# XML 바운딩 박스 라벨링 정보들을 Txt 파일로 추출  
import os
import xml.etree.ElementTree as ET

# CVAT XML 파일 경로
cvat_annotation_file = 'C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test2\\Bbox\\0617_01.xml'

# YOLO 포맷을 저장할 디렉토리
yolo_annotation_dir = 'C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test2\\yolo_annotations'

# 클래스 ID 매핑
class_mapping = {
    'person': 0,
    'car': 1,
    'bench': 2,
    'bollard': 3,
    'tree_trunk': 4,
    'kiosk': 5,
    'pole': 6, 
    'traffic_light': 7,
    'traffic_sign': 8,
    'movable_signage': 9,
    'truck': 10,
    'motorcycle': 11,
    'potted_plant': 12,
    'chair': 13,
    'stroller': 14,
    'wheelchair': 15,
    'barricade': 16,
    'bus': 17,
    'stop': 18,
    'table': 19,
    'scooter': 20,
    'parking_meter': 21,
    'fire_hydrant': 22,
    'dog': 23,
    'carrier': 24,
    'cat': 25,
    'bicycle': 26
}

def parse_cvat_annotation(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()
    
    annotations = {}
    
    for image in root.findall('image'):
        image_name = image.get('name')
        image_annotations = []
        
        for box in image.findall('box'):
            label = box.get('label')
            class_id = class_mapping.get(label)
            if class_id is None:
                continue
            
            xtl = float(box.get('xtl'))
            ytl = float(box.get('ytl'))
            xbr = float(box.get('xbr'))
            ybr = float(box.get('ybr'))
            
            image_annotations.append((class_id, xtl, ytl, xbr, ybr))
        
        annotations[image_name] = image_annotations
    
    return annotations

def save_yolo_annotations(annotations, output_dir):
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    
    for image_name, boxes in annotations.items():
        yolo_filename = os.path.join(output_dir, f'{os.path.splitext(image_name)[0]}.txt')
        
        with open(yolo_filename, 'w') as f:
            for class_id, xtl, ytl, xbr, ybr in boxes:
                f.write(f"{class_id} {xtl} {ytl} {xbr} {ybr}\n")
    
    print(f"XML이 TXT 형식으로 변환되었습니다. {output_dir}")

# CVAT 어노테이션 파싱
annotations = parse_cvat_annotation(cvat_annotation_file)

# YOLO 포맷으로 저장
save_yolo_annotations(annotations, yolo_annotation_dir)
