import xml.etree.ElementTree as ET

def count_bounding_boxes_in_xml(xml_file_path):
    # XML 파일을 파싱
    tree = ET.parse(xml_file_path)
    root = tree.getroot()

    # 'box' 태그를 모두 찾기 ('track' 안에 있는 태그)
    boxes = root.findall(".//track//box")

    # 바운딩 박스 갯수 반환
    return len(boxes)

# XML 파일 경로
xml_file_path = r'C:\Users\kiot\Yolo V5\yolov5\test\annotations.xml'

# 바운딩 박스 객체 갯수 계산
num_boxes = count_bounding_boxes_in_xml(xml_file_path)
print(f'총 바운딩 박스 객체 갯수: {num_boxes}')
