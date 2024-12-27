import os
import xml.etree.ElementTree as ET
import cv2
import matplotlib.pyplot as plt

# XML 파일 경로
xml_file_path = "C:/Users/kiot/Yolo V5/yolov5/DataSetSample/Bbox_0031/0621_05.xml"

# 이미지 폴더 경로
image_folder_path = "C:/Users/kiot/Yolo V5/yolov5/DataSetSample/Bbox_0031/"

# XML 파일 파싱
tree = ET.parse(xml_file_path)
root = tree.getroot()

# 모든 <image> 태그를 순회
for image in root.findall('image'):
    filename = image.get('name')

    if filename is None:
        print("Error: 'filename' is None.")
        continue

    image_path = os.path.join(image_folder_path, filename)

    if not os.path.exists(image_path):
        print(f"Image {filename} not found in {image_folder_path}")
        continue

    img = cv2.imread(image_path)
    if img is None:
        print(f"Failed to load image: {image_path}")
        continue

    print(f"Loaded image: {filename} with size {img.shape}")

    for box in image.findall('box'):
        label = box.get('label')
        xtl = float(box.get('xtl'))
        ytl = float(box.get('ytl'))
        xbr = float(box.get('xbr'))
        ybr = float(box.get('ybr'))

        print(f"Label: {label}, BBox: ({xtl}, {ytl}) to ({xbr}, {ybr})")

        cv2.rectangle(img, (int(xtl), int(ytl)), (int(xbr), int(ybr)), (0, 255, 0), 2)
        cv2.putText(img, label, (int(xtl), int(ytl) - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (36, 255, 12), 2)

    # Matplotlib을 사용하여 이미지 보여주기
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    plt.imshow(img_rgb)
    plt.axis('off')  # 축 표시 끄기
    plt.show()  # 이미지 표시
