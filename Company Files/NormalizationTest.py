from PIL import Image, ImageDraw

def draw_bounding_boxes(image_path, img_width, img_height, bounding_boxes):
    """
    이미지에 YOLO 형식의 바운딩 박스를 그리고 출력.

    Parameters:
        image_path (str): 이미지 파일 경로
        img_width (int): 이미지 너비
        img_height (int): 이미지 높이
        bounding_boxes (list): YOLO 형식 바운딩 박스 데이터 [{"label": str, "x_center": float, "y_center": float, "width": float, "height": float}]
    """
    try:
        # 이미지 열기
        image = Image.open(image_path)
        draw = ImageDraw.Draw(image)

        for box in bounding_boxes:
            # YOLO 형식의 좌표를 픽셀 단위로 변환
            x_center = box["x_center"] * img_width
            y_center = box["y_center"] * img_height
            width = box["width"] * img_width
            height = box["height"] * img_height

            # 디버깅 출력
            print(f"정규화된 값: x_center: {box['x_center']}, y_center: {box['y_center']}, width: {box['width']}, height: {box['height']}")
            print(f"픽셀 좌표 변환: x_center: {x_center}, y_center: {y_center}, width: {width}, height: {height}")

            # 픽셀 단위 좌표 계산
            x_min = x_center - width / 2
            y_min = y_center - height / 2
            x_max = x_center + width / 2
            y_max = y_center + height / 2

            # 디버깅 출력
            print(f"계산된 좌표: x_min: {x_min}, y_min: {y_min}, x_max: {x_max}, y_max: {y_max}")

            # 이미지 경계 내로 제한
            x_min = max(0, min(img_width, x_min))
            y_min = max(0, min(img_height, y_min))
            x_max = max(0, min(img_width, x_max))
            y_max = max(0, min(img_height, y_max))

            # 디버깅 출력 (조정된 값)
            print(f"조정된 좌표: x_min: {x_min}, y_min: {y_min}, x_max: {x_max}, y_max: {y_max}")

            # 바운딩 박스 그리기
            draw.rectangle([(x_min, y_min), (x_max, y_max)], outline="yellow", width=3)
            draw.text((x_min, max(0, y_min - 10)), box["label"], fill="yellow")

        # 이미지 표시
        image.show()

    except Exception as e:
        print(f"에러 발생: {e}")

# 예제 입력
image_path = "D:\\시각 장애인 사업 데이터셋\\보행안전 도로 위험물\\image\\1_01_0_1_1_1_20210712_0000059650.jpg"  # 이미지 경로
img_width, img_height = 2592, 4608  # 이미지 크기
bounding_boxes = [
    {"label": "0", "x_center": 0.587549, "y_center": 0.589560, "width": 0.102066, "height": 0.208999}
]

# 함수 호출
draw_bounding_boxes(image_path, img_width, img_height, bounding_boxes)
