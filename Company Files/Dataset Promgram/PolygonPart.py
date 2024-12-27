import xml.etree.ElementTree as ET
import os

# 원본 XML 파일 경로
source_xml = "C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\Polygon_0302\\annotations\\P0921_10.xml"
output_dir = "C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\Polygon_0302\\split_annotations"

# 출력 폴더 생성
os.makedirs(output_dir, exist_ok=True)

# XML 읽기
tree = ET.parse(source_xml)
root = tree.getroot()

# 여러 이미지의 annotation 분리
for image in root.findall("image"):
    # 이미지 이름 및 크기 가져오기
    filename = image.get("name")
    width = image.get("width")
    height = image.get("height")

    # 새로운 XML 루트 생성
    new_root = ET.Element("annotation")
    ET.SubElement(new_root, "filename").text = filename

    # 이미지 크기 정보 추가
    size = ET.SubElement(new_root, "size")
    ET.SubElement(size, "width").text = str(width)
    ET.SubElement(size, "height").text = str(height)
    ET.SubElement(size, "depth").text = "3"  # 기본 RGB 이미지를 가정

    # 객체 정보 추가
    for polygon in image.findall("polygon"):
        obj = ET.SubElement(new_root, "object")
        label = polygon.get("label")
        ET.SubElement(obj, "name").text = label

        # Occlusion, Difficult, Pose 추가
        ET.SubElement(obj, "pose").text = "Unspecified"
        ET.SubElement(obj, "difficult").text = "0"
        ET.SubElement(obj, "occlusion").text = polygon.get("occluded", "0")  # 기본값 0

        # 다각형 포인트 처리
        points_str = polygon.get("points")
        points = points_str.split(";")  # 포인트가 세미콜론으로 구분됨
        points_list = [(float(point.split(",")[0]), float(point.split(",")[1])) for point in points]

        # Bndbox 생성 (다각형을 포함하는 바운딩 박스를 계산)
        xmin = min(p[0] for p in points_list)
        ymin = min(p[1] for p in points_list)
        xmax = max(p[0] for p in points_list)
        ymax = max(p[1] for p in points_list)

        bndbox = ET.SubElement(obj, "bndbox")
        ET.SubElement(bndbox, "xmin").text = str(xmin)
        ET.SubElement(bndbox, "ymin").text = str(ymin)
        ET.SubElement(bndbox, "xmax").text = str(xmax)
        ET.SubElement(bndbox, "ymax").text = str(ymax)

        # (선택적으로) z_order 추가 (필요시 처리 가능)
        ET.SubElement(obj, "z_order").text = polygon.get("z_order", "0")

    # 분리된 XML 저장
    output_path = os.path.join(output_dir, f"{os.path.splitext(filename)[0]}.xml")
    tree = ET.ElementTree(new_root)
    tree.write(output_path, encoding="utf-8", xml_declaration=True)

print("XML 분리 및 저장 완료!")
