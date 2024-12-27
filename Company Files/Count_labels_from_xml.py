import os
import xml.etree.ElementTree as ET
from collections import defaultdict

# XML 파일들이 있는 디렉토리 경로 (원시 문자열 사용)
xml_dir = r'C:\Users\kiot\Yolo V5\yolov5\test\test\test\annotations'

# 결과를 저장할 텍스트 파일
output_file = 'output_all.txt'

# 결과 저장을 위한 딕셔너리
all_label_counts = defaultdict(int)

# 디렉토리 내 모든 XML 파일 처리
for filename in os.listdir(xml_dir):
    if filename.endswith('.xml'):  # XML 파일만 처리
        xml_file = os.path.join(xml_dir, filename)
        
        try:
            # XML 파일 파싱
            tree = ET.parse(xml_file)
            root = tree.getroot()
            
            # 각 XML 파일 내 모든 'object' 태그에서 'name' 태그 값 카운트
            for obj in root.findall('.//object'):
                label = obj.find('name').text  # 'name' 태그의 텍스트 추출
                if label:
                    all_label_counts[label] += 1
        except ET.ParseError as e:
            print(f"파일 {filename} 파싱 중 오류 발생: {e}")
            continue
        except Exception as e:
            print(f"파일 {filename} 처리 중 오류 발생: {e}")
            continue

# 결과를 텍스트 파일로 저장
if all_label_counts:
    with open(output_file, 'w', encoding='utf-8') as f:
        for label, count in all_label_counts.items():
            f.write(f'{label}: {count}\n')
    print(f'모든 XML 파일의 결과가 {output_file} 파일에 저장되었습니다.')
else:
    print("모든 XML 파일에서 유효한 'name' 정보를 찾지 못했습니다.")
