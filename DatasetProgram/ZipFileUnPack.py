# 압축된 이미지들을 해제하는 코드 

from PIL import Image, ImageDraw
import matplotlib.pyplot as plt

import zipfile
import os

# ZIP 파일 경로 설정
zip_file_path = r'C:\Users\kiot\Yolo V5\yolov5\DataSetSample\Bbox_1_new.zip'
extract_path = r'C:\Users\kiot\Yolo V5\yolov5\DataSetSample\images2'

# ZIP 파일 풀기
with zipfile.ZipFile(zip_file_path, 'r') as zip_ref:
    zip_ref.extractall(extract_path)

# 이미지 파일 경로 설정
image_path = os.path.join(extract_path, 'MP_SEL_000001.jpg')

# 이미지 파일이 존재하는지 확인
if os.path.exists(image_path):
    print(f"이미지가 존재합니다: {image_path}")
else:
    print("이미지가 존재하지 않습니다.")

import zipfile
import os
from PIL import Image
import matplotlib.pyplot as pltd

# ZIP 파일 경로 설정
zip_file_path = r'C:\Users\kiot\Yolo V5\yolov5\DataSetSample\Bbox_1_new.zip'
extract_path = r'C:\Users\kiot\Yolo V5\yolov5\DataSetSample\images2\Bbox_0001'

# ZIP 파일 풀기
with zipfile.ZipFile(zip_file_path, 'r') as zip_ref:
    zip_ref.extractall(extract_path)

# 이미지 파일 경로 설정
image_path = os.path.join(extract_path, 'MP_SEL_000001.jpg')

# 이미지 파일이 존재하는지 확인하고 불러오기
if os.path.exists(image_path):
    img = Image.open(image_path)
    
    # 이미지 출력
    plt.imshow(img)
    plt.axis('off')  # 축 제거
    plt.show()
else:
    print("이미지가 존재하지 않습니다.")

# 바운딩 박스 좌표
bounding_boxes = [
    {"label": "tree_trunk", "xtl": 1279.39, "ytl": 451.90, "xbr": 1331.40, "ybr": 670.79},
    {"label": "movable_signage", "xtl": 1082.78, "ytl":356.68, "xbr": 1147.89, "ybr": 491.46},
    {"label": "tree_trunk", "xtl": 1157.03, "ytl": 277.90, "xbr": 1210.30, "ybr": 565.71},
    {"label": "tree_trunk", "xtl": 1094.21, "ytl": 331.56, "xbr": 1131.90, "ybr": 493.75},
    {"label": "car", "xtl": 1672.90, "ytl": 382.30, "xbr": 1728.00, "ybr": 416.00},
    {"label": "traffic_sign", "xtl": 1851.90, "ytl": 346.60, "xbr": 1886.20, "ybr": 380.31},
    {"label": "car", "xtl": 1768.60, "ytl": 423.00, "xbr": 1914.00, "ybr": 499.00},
    {"label": "car", "xtl": 1634.90, "ytl": 499.70, "xbr": 1920.00, "ybr": 857.50},
    {"label": "car", "xtl": 1692.90, "ytl": 411.90, "xbr": 1814.00, "ybr": 478.00},
    {"label": "movables_signage", "xtl": 1692.20, "ytl": 411.90, "xbr": 1814.00, "ybr": 478.00}
]

# 이미지에 바운딩 박스 그리기
draw = ImageDraw.Draw(img)
for box in bounding_boxes:
    draw.rectangle([(box['xtl'], box['ytl']), (box['xbr'], box['ybr'])], outline="yellow", width=3)

# 이미지 표시
plt.figure(figsize=(25, 12))
plt.imshow(img)
plt.axis('off')
plt.show()
