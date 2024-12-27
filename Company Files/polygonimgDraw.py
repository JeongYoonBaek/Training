from PIL import Image, ImageDraw
import matplotlib.pyplot as plt  

# 이미지 불러오기
image_path = r'C:\Users\kiot\Yolo V5\yolov5\test\test\test\images\default\images\MP_SEL_SUR_000087.jpg'
image = Image.open(image_path)
image_width, image_height = image.size  # 이미지 크기 가져오기
print(image_width, image_height)

# 바운딩 박스 좌표 (YOLO 형식: 정규화된 좌표)
bounding_boxes = [
    {"label": "sidewalk", "x_min": 0.407734, "y_min": 0.500000, "x_max": 0.815469, "y_max": 1.000000}
]
 
# 이미지에 바운딩 박스 그리기
draw = ImageDraw.Draw(image)
for box in bounding_boxes:
    # YOLO 좌표를 픽셀 단위로 변환
    x_min = box['x_min'] * image_width
    y_min = box['y_min'] * image_height
    x_max = box['x_max'] * image_width
    y_max = box['y_max'] * image_height

    # 좌표 확인
    print(f"Original YOLO box: {box}")
    print(f"Pixel box: ({x_min}, {y_min}, {x_max}, {y_max})")

    # 바운딩 박스 그리기
    draw.rectangle([(x_min, y_min), (x_max, y_max)], outline="yellow", width=3)
    
# 이미지 표시
plt.figure(figsize=(25, 12))
plt.imshow(image)
plt.axis('off')
plt.show()
