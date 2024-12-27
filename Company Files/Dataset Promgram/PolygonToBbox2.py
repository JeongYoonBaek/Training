import json
import os

# JSON 파일 경로 설정
json_file_path = r'C:\Users\kiot\Yolo V5\yolov5\test\test2\video173-11\output\annotations_with_bboxes.json'  # JSON 파일 경로를 지정하세요.
output_dir = r'C:\Users\kiot\Yolo V5\yolov5\test\test2\video173-11\output_labels'  # 라벨링 정보를 저장할 디렉토리

# 출력 디렉토리 생성
os.makedirs(output_dir, exist_ok=True)

# JSON 파일 읽기
with open(json_file_path, 'r') as f:
    data = json.load(f)

# 각 이미지에 대해 라벨링 정보 추출
for image in data['images']:  # 'images'는 JSON 구조에 따라 수정할 수 있습니다.
    image_id = image['id']  # 이미지 ID
    image_file_name = image['file_name']  # 이미지 파일 이름

    # 해당 이미지에 대한 annotation 필터링
    image_annotations = [annotation for annotation in data['annotations'] if annotation['image_id'] == image_id]

    # 텍스트 파일 생성
    output_file_path = os.path.join(output_dir, f'{os.path.splitext(image_file_name)[0]}.txt')
    with open(output_file_path, 'w') as txt_file:
        for annotation in image_annotations:
            if 'bbox' in annotation:  # bbox 정보가 있는지 확인
                # bbox 포맷: [xtl, ytl, xbr, ybr]
                bbox = annotation['bbox']
                # 카테고리 ID와 바운딩 박스를 텍스트 파일에 작성
                line = f'{annotation["category_id"]} {bbox[0]} {bbox[1]} {bbox[2]} {bbox[3]}\n'  # xbr와 ybr 사용
                txt_file.write(line)

print(f"각 이미지의 라벨링 정보가 '{output_dir}'에 성공적으로 저장되었습니다.")
