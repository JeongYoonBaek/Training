import os
import glob # 파일들의 리스트를 뽑을 때 사용

# 폴더 경로
folder_path = 'D:\\SIMPAC METAL\\Slag\\08000707_0703\\obj_train_data'

# 이미지 파일 확장자 목록
image_ext = ['.jpg', '.png']

# 폴더 내 모든 텍스트 파일을 검색
# 주어진 패턴과 일치하는 모든 파일 경로를 리스트로 반환
txt_files = glob.glob(os.path.join(folder_path, '*.txt')) 

# 각 텍스트 파일 읽기 (처리)
for file_path in txt_files:
    with open(file_path, 'r', encoding='utf-8') as file:
        lines = file.readlines()

    # 파일이 비어 있거나 첫 번째 값이 객체 번호가 아니거나 공백이거나, 객체 번호만 있고 위치 좌표가 없는지 확인
    should_delete = not lines or any( #not lines은 파일이 비어있을 때 True로 평가됨 
        # len(line.split()) < 5는 라인을 공백으로 나눈 요소의 개수가 5보다 작을 때 True로 평가 
        not line.strip() or not line.split()[0].isdigit() or len(line.split()) < 5 for line in lines)
    
 # 이 조건들이 모두 포함된 'any'함수는 파일의 모든 라인 중 하나라도 조건을 만족하면 'True'로 반환하여 should_delete가 'True'인 경우 파일 삭제
    if should_delete:
        # 텍스트 파일 삭제
        os.remove(file_path)
        print(f'{file_path} 텍스트 파일이 삭제되었습니다.')
     
        # 동일한 이름의 이미지 파일 삭제
        same_name = os.path.splitext(file_path)[0]
        for ext in image_ext:
            image_file = same_name + ext
            if os.path.exists(image_file):
                os.remove(image_file)
                print(f'{image_file} 이미지 파일이 삭제되었습니다.')


# 파일 갯수 확인 
# filenames = os.listdir(file_path)
# print(len(filenames))

# labelinfo 폴더 생성  
# labelfile1=txt_files+'label1'
# labelfile2=txt_files+'label2'
# os.makedirs(labelfile1, exist_ok=True)
# os.makedirs(labelfile2, exist_ok=True)

