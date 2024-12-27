import os
import glob # 파일들의 리스트를 뽑을 때 사용

# 폴더 경로 
folder_path = 'C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test\\yolo_annotations'  

# 객체 번호 매핑 (기존 객체 번호 -> 새로운 객체 번호)
# 매핑이란 key역할을 하는 데이터 value를 일대일 대응시키는 과정. for문이나 기본 함수로 처리하는 것보다 훨씬 효율적. 
mapping = { 
    '1': '2',  # 키 : 값 쌍을 하나씩 표현  
} 
  
# 폴더 내 모든 텍스트 파일을 검색
txt_files = glob.glob(os.path.join(folder_path, '*.txt')) 

# 각 텍스트 파일 읽기(처리)
for file_path in txt_files:
    with open(file_path, 'r', encoding='utf-8') as file:
        lines = file.readlines()

    # 파일에 해당 객체 번호가 있는지 확인 
    contains_target_numbers = any(line.split()[0] in mapping for line in lines if line.split())

    if contains_target_numbers: 
        # 파일 내 객체 번호 변경
        updated_lines = []
        for line in lines:
            parts = line.split()
            if parts and parts[0] in mapping:  # 라인이 공백되어 있지 않은지 확인
                parts[0] = mapping[parts[0]]
            updated_line = ' '.join(parts)
            updated_lines.append(updated_line)

        # 변경된 내용은 파일로 저장 (w = 덮어쓰기)
        with open(file_path, 'w', encoding='utf-8') as file:
            file.write('\n'.join(updated_lines))

        print(f'{file_path} 파일의 객체번호가 변경되었습니다.')
