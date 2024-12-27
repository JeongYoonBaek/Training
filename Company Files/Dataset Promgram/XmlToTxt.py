import os
import xml.etree.ElementTree as ET

# XML 파일 경로
xml_file_path = "C:/Users/kiot/Yolo V5/yolov5/DataSetSample/Bbox_0012/0619_08.xml"

# 텍스트 파일을 저장할 폴더 경로
output_folder = "C:/Users/kiot/Yolo V5/yolov5/DataSetSample/Bbox_0012"
os.makedirs(output_folder, exist_ok=True)

# XML 파일 파싱
tree = ET.parse(xml_file_path)
root = tree.getroot()

# 모든 <image> 태그를 순회
for image in root.findall('image'):
    filename = image.get('name')  # 이미지 이름을 가져옵니다.

    if filename is None:
        print("Error: 'filename' is None.")
        continue

    # 텍스트 파일 경로
    txt_file_path = os.path.join(output_folder, f"{os.path.splitext(filename)[0]}.txt")

    # 텍스트 파일 작성
    with open(txt_file_path, 'w') as txt_file:
        # 각 <box> 태그를 순회하며 객체 정보 추출
        for box in image.findall('box'):
            label = box.get('label')
            xtl = float(box.get('xtl'))
            ytl = float(box.get('ytl'))
            xbr = float(box.get('xbr'))
            ybr = float(box.get('ybr'))

            # 라벨링 정보를 텍스트 파일에 기록
            txt_file.write(f"{label} {xtl} {ytl} {xbr} {ybr}\n")

    print(f"Labels for {filename} saved to {txt_file_path}")
