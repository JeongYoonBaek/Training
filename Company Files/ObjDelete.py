import os
import glob

# 원본 폴더 경로
source_folder_path = 'C:\\Users\\kiot\\Yolo V5\\yolov5\\test\\test\\yolo_annotations'

# 삭제할 객체 번호 리스트
del_obj_nums = {'3'}  # 삭제할 객체 번호 집합으로 설정

# 폴더 내 모든 텍스트 파일 검색
txt_files = glob.glob(os.path.join(source_folder_path, '*.txt'))

# 각 텍스트 파일 읽기 (처리 )
for file_path in txt_files:
    with open(file_path, 'r', encoding='utf-8') as file: 
        lines = file.readlines()

    # 삭제할 객체 번호가 포함된 라인 필터링
    # not in 연산자는 데이터 안에 찾고자 하는 것이 있는지 확인 하고, 데이터가 있으면 True, 없으면 False
    lines_to_keep = [line for line in lines if line.split()[0] not in del_obj_nums]

    if len(lines_to_keep) != len(lines):
        # 파일을 덮어쓰기 모드로 다시 열어 삭제 후 유지할 라인만 기록
        with open(file_path, 'w', encoding='utf-8') as file:
            file.writelines(lines_to_keep)
        
        print(f'{file_path} 텍스트 파일에서 객체 번호 {del_obj_nums}가 삭제되었습니다.')
    else:
        print(f'{file_path} 텍스트 파일에 객체 번호 {del_obj_nums}가 없습니다.')
