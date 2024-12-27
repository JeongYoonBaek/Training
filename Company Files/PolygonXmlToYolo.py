# XML 폴리곤 라벨링 정보들을 TXT 파일로 추출  
import os
import xml.etree.ElementTree as ET

cvat_annotations_file = 'C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test\\Polygon_0301\\P0921_09.xml'
yolo_annotations_dir = 'C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test\\polygon_annotations'

# 클래스 이름과 YOLO 클래스 ID 매핑
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
    'bicycle': 26,
    'traffic_light_controller': 27,
    'power_controller': 28
}

def parse_cvat_annotations(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()
    
    annotations = {}
    
    for image in root.findall('image'):
        image_name = image.get('name')
        image_annotations = []
        
        for polygon in image.findall('polygon'): 
            label = polygon.get('label')
            class_id = class_mapping.get(label)
            if class_id is None: 
                continue 
            
            # 폴리곤의 x, y 좌표들을 추가
            points = polygon.get('points').split(';')
            points = [point.strip() for point in points]  # 좌표 포맷 정리
            image_annotations.append((class_id, points))
                     
        annotations[image_name] = image_annotations
    
    return annotations

def save_yolo_annotations(annotations, output_dir):
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
        
    for image_name, polygons in annotations.items():
        yolo_filename = os.path.join(output_dir, f"{os.path.splitext(image_name)[0]}.txt")
        
        with open(yolo_filename, 'w') as f:
            for class_id, points in polygons:
                # 각 점을 YOLO 형식으로 기록
                points_str = ' '.join(points)
                f.write(f"{class_id} {points_str}\n")
                
    print(f"YOLO annotations saved in {output_dir}")

# XML 파일에서 폴리곤 라벨링 정보를 파싱하여 YOLO 형식으로 저장
annotations = parse_cvat_annotations(cvat_annotations_file)

save_yolo_annotations(annotations, yolo_annotations_dir)
