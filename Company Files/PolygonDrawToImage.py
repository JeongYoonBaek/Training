from PIL import Image, ImageDraw
from pathlib import Path

# TXT 파일 및 이미지 경로 설정
txt_file_folder = r'C:/Users/kiot/Yolo V5/yolov5/test/test/polygon_annotations/MP_TW_P003403.txt'
image_file_folder = r'C:/Users/kiot/Yolo V5/yolov5/test/test/Polygon_0301/MP_TW_P003403.jpg'
output_dir = r'C:/Users/kiot/Yolo V5/yolov5/test/test/output_image'

# TXT 파일에서 폴리곤 정보를 읽어 이미지에 그리기
def draw_polygons_from_txt(txt_file_folder, image_file_folder, output_dir):
    # 이미지 열기
    image = Image.open(image_file_folder)
    draw = ImageDraw.Draw(image)

    # TXT 파일에서 폴리곤 좌표 읽기
    with open(txt_file_folder, 'r') as f:
        lines = f.readlines()

    for line in lines:
        parts = line.strip().split()
        class_id = int(parts[0])  # 클래스 ID
        points_str = parts[1:]    # 좌표 정보

        # 폴리곤 좌표 변환
        polygon_points = []
        for point in points_str:
            if ',' in point:
                try:
                    x, y = map(float, point.split(','))
                    polygon_points.append((x, y))
                except ValueError:
                    print(f"Invalid coordinate format in: {point}")
                    continue

        # 좌표가 3개 이상일 때만 폴리곤 그리기
        if len(polygon_points) >= 3:
            draw.polygon(polygon_points, outline="yellow", width=3)
        else:
            print("Warning: Not enough coordinates to draw a polygon.")
    
    # 출력 디렉토리 생성 및 결과 저장
    Path.mkdir(rparents=True, exist_ok=True)
    output_path = output_dir / image_file_folder.name
    image.save(output_path)
    print(f"Saved annotated image: {output_path}")
 
# 실행
draw_polygons_from_txt(txt_file_folder, image_file_folder, output_dir)
