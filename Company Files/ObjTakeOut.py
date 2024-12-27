import os
import glob
import shutil  # 파일을 복사 및 이동할 때 유용한 모듈

# 원본 폴더 경로
source_folder_path = 'C:\\Users\\kiot\Yolo V5\\yolov5\\test\\test\\yolo_annotations'
# 저장할 폴더 경로
save_folder_path = 'C:\\Users\\kiot\Yolo V5\\yolov5\\test\\test\\copy'

# 가져올 객체 번호
takeout_obj_nums = {'20'} # 여러 개의 객체 번호를 가져올 수 있으니 집합으로 설정

# 이미지 파일 확장자 목록
image_ext = ['.jpg', '.png']   

# 폴더 내 모든 텍스트 파일 검색
txt_files = glob.glob(os.path.join(source_folder_path, '*.txt'))

# 출력 폴더가 존재하지 않으면 생성
os.makedirs(save_folder_path, exist_ok=True)

# 각 텍스트 파일 처리
for file_path in txt_files:
    with open(file_path, 'r', encoding='utf-8') as file: 
        lines = file.readlines() 
    
    # 텍스트 파일에서 객체 번호 추출
    obj_nums_in_file = {line.split()[0] for line in lines if line.split()}
    # 파일 내 객체 번호가 지정된 객체 번호 집합과 정확히 일치하는지 확인
    if obj_nums_in_file == takeout_obj_nums: 
        shutil.copy(file_path, save_folder_path)
        print(f'{file_path} 텍스트 파일이 복사되었습니다.')
        
        # 동일한 이름의 이미지 파일 복사
        base_name =  os.path.splitext(os.path.basename(file_path))[0]
        for ext in image_ext:
            image_file = os.path.join(source_folder_path, base_name + ext)
            if os.path.exists(image_file):
                shutil.copy(image_file, save_folder_path)
                print(f'{image_file} 이미지 파일이 복사되었습니다')
                