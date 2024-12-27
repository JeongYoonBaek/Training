import json
import os

# JSON 파일 경로 설정
json_file_path = r'C://Users//kiot//Yolo V5//yolov5//test//test2//video173-11//annotations//instances_default.json'  # JSON 파일 경로를 지정하세요.
output_dir = r'C://Users//kiot//Yolo V5//yolov5//test//test2//video173-11//output'  # 변환된 데이터를 저장할 디렉토리
output_bbox_file_path = os.path.join(output_dir, 'annotations_with_bboxes.json')  # 결과를 저장할 JSON 파일 경로

# 출력 디렉토리 생성
os.makedirs(output_dir, exist_ok=True)

# JSON 파일 읽기
with open(json_file_path, 'r') as f:
    data = json.load(f)

# segmentation을 bbox로 변환
for annotation in data['annotations']:  # 'annotations'는 JSON 구조에 따라 수정할 수 있습니다.
    if isinstance(annotation['segmentation'], list) and len(annotation['segmentation']) > 0:
        for segmentation in annotation['segmentation']:
            # segmentation의 점들을 평탄화
            points = segmentation  # segmentation은 리스트 안에 리스트가 있을 수 있음

            # x, y 좌표 분리
            x_coords = points[0::2]  # 짝수 인덱스의 x 좌표
            y_coords = points[1::2]  # 홀수 인덱스의 y 좌표

            # bbox 계산
            xtl = min(x_coords)  # 왼쪽 상단 x좌표
            ytl = min(y_coords)  # 왼쪽 상단 y좌표
            xbr = max(x_coords)  # 오른쪽 하단 x좌표
            ybr = max(y_coords)  # 오른쪽 하단 y좌표

            # bbox를 annotation에 추가
            annotation['bbox'] = [xtl, ytl, xbr, ybr]  # [xtl, ytl, xbr, ybr] 형식으로 저장

# 변환된 데이터 저장
with open(output_bbox_file_path, 'w') as f:
    json.dump(data, f, indent=4)

print(f"Segmentation이 바운딩 박스로 변환되어 '{output_bbox_file_path}'에 저장되었습니다.")
