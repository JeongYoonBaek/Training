import os

def rename_files_with_padding(directory, prefix, extension):
    files = os.listdir(directory)
    frame_files = [f for f in files if f.startswith(prefix) and f.endswith(extension)]
    
    # 프레임 숫자만 추출하여 정렬
    frame_numbers = [int(f.replace(prefix, '').replace(extension, '')) for f in frame_files]
    frame_numbers.sort()

    # 파일명을 4자리로 패딩하여 변경
    for frame_number in frame_numbers:
        old_name = f"{directory}/{prefix}{frame_number}{extension}"
        new_name = f"{directory}/{prefix}{frame_number:04d}{extension}"  # 4자리 패딩
        os.rename(old_name, new_name)
        print(f"Renamed: {old_name} -> {new_name}")

# 파일이 있는 디렉토리와 파일명 패턴을 설정
directory = r'D:\GwangAn Subway Video\image1'  # 이미지가 있는 폴더 경로
prefix = 'frame'  # 파일명의 접두사
extension = '.jpg'  # 파일 확장자

rename_files_with_padding(directory, prefix, extension)
