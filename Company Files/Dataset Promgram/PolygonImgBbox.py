from PIL import Image, ImageDraw
import matplotlib.pyplot as plt

# 이미지 불러오기
image_path = r'C:\Users\kiot\Yolo V5\yolov5\test\test2\video173-4\images\GwangAn-173_frame_3007.jpg'
image = Image.open(image_path)

# 원본 이미지 크기 (2304x1728)
original_width, original_height = 2304, 1728

# 현재 이미지 크기
image_width, image_height = image.size
print(f"Image size: {image_width}x{image_height}")

# 바운딩 박스 좌표 (원본 이미지 기준)
bounding_boxes = [
    {"label": "person", "xtl": 1788.6, "ytl": 433.48, "xbr": 1867.74, "ybr": 519.6}, # xbr와 ybr의 값이 올바르게 수정됨
    {"label": "person", "xtl": 1166.17, "ytl": 155.84, "xbr": 1194.2, "ybr": 185.9},
    {"label": "person", "xtl": 66.0, "ytl": 1296.4, "xbr": 130.0, "ybr": 1367.5}
]

# 이미지에 바운딩 박스 그리기
draw = ImageDraw.Draw(image)
for box in bounding_boxes:
    # 좌표가 원본 이미지 기준이므로 현재 이미지 크기에 맞게 스케일링
    scale_x = image_width / original_width
    scale_y = image_height / original_height
    
    xtl = box['xtl'] * scale_x
    ytl = box['ytl'] * scale_y
    xbr = box['xbr'] * scale_x
    ybr = box['ybr'] * scale_y
    
    # 좌표 정렬: x값과 y값이 올바르게 정렬되도록
    if xtl > xbr:
        xtl, xbr = xbr, xtl
    
    if ytl > ybr:
        ytl, ybr = ybr, ytl
    
    # 바운딩 박스 그리기
    draw.rectangle([(xtl, ytl), (xbr, ybr)], outline="yellow", width=3)

# 이미지 표시
plt.figure(figsize=(25, 12))
plt.imshow(image)
plt.axis('off')
plt.show()
