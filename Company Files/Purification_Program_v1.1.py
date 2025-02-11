import os
import glob
import random
import tkinter as tk
from tkinter import filedialog

# Functions for selecting directories
def select_image_directory():
    global image_folder_path
    image_folder_path = filedialog.askdirectory(title="이미지 폴더 선택")
    if image_folder_path:
        image_dir_label.config(text=f"선택됨: {image_folder_path}", fg="green")
        image_dir_entry.delete(0, tk.END)
        image_dir_entry.insert(0, image_folder_path)  # Display path in the entry field
    else:
        image_dir_label.config(text="폴더가 선택되지 않았습니다.", fg="red")

def select_label_directory():
    global txt_folder_path
    txt_folder_path = filedialog.askdirectory(title="라벨링 폴더 선택")
    if txt_folder_path:
        label_dir_label.config(text=f"선택됨: {txt_folder_path}", fg="green")
        label_dir_entry.delete(0, tk.END)
        label_dir_entry.insert(0, txt_folder_path)  # Display path in the entry field
    else:
        label_dir_label.config(text="폴더가 선택되지 않았습니다.", fg="red")

def execute_cleanup():
    if not image_folder_path or not txt_folder_path:
        status_label.config(text="폴더를 모두 선택한 후 실행하세요.", fg="red")
        return

    # 이미지 파일 확장자
    image_ext = ['.jpg', '.png']

    # TXT 파일 이름(확장자 제외) 모음
    txt_files = glob.glob(os.path.join(txt_folder_path, '*.txt'))
    txt_file_names = {os.path.splitext(os.path.basename(txt))[0] for txt in txt_files}

    # 이미지 파일 목록
    image_files = [img for ext in image_ext for img in glob.glob(os.path.join(image_folder_path, f'*{ext}'))]

    # 삭제된 이미지 카운터 초기화
    deleted_image_count = 0

    # 이미지 파일 처리: 해당 이미지에 대응하는 TXT 파일이 없으면 삭제
    for image_file in image_files:
        image_name = os.path.splitext(os.path.basename(image_file))[0]
        if image_name not in txt_file_names:
            try:
                os.remove(image_file)
                deleted_image_count += 1
                print(f'{image_file} 이미지 파일이 삭제되었습니다.')
            except Exception as e:
                print(f'{image_file} 삭제 중 오류 발생: {e}')

    # TXT 파일 처리: 텍스트 파일 내용이 비어있거나 잘못된 형식이면 삭제하고, 연관 이미지도 삭제
    for txt_file in txt_files:
        with open(txt_file, 'r', encoding='utf-8') as file:
            lines = file.readlines()

        should_delete = not lines or any(
            not line.strip() or not line.split()[0].isdigit() or len(line.split()) < 5 for line in lines
        )

        if should_delete:
            try:
                os.remove(txt_file)
                print(f'{txt_file} 텍스트 파일이 삭제되었습니다.')

                same_name = os.path.splitext(txt_file)[0]
                for ext in image_ext:
                    image_file = os.path.join(image_folder_path, os.path.basename(same_name) + ext)
                    if os.path.exists(image_file):
                        os.remove(image_file)
                        deleted_image_count += 1
                        print(f'{image_file} 이미지 파일이 삭제되었습니다.')
            except Exception as e:
                print(f'{txt_file} 또는 {image_file} 삭제 중 오류 발생: {e}')

    status_label.config(text=f"정리 작업 완료! 삭제된 이미지 파일: {deleted_image_count}개", fg="green")

# 이미지와 라벨이 모두 존재하는 파일 이름들을 텍스트 파일에 저장하는 함수
def save_image_names_to_txt(image_directory, label_directory, txt_filename):
    # 이미 존재하는 txt_filename이 있다면 삭제
    if os.path.exists(txt_filename):
        try:
            os.remove(txt_filename)
            print(f"기존 파일 {txt_filename}을 삭제했습니다.")
        except Exception as e:
            print(f"{txt_filename} 삭제 중 오류 발생: {e}")
            return

    # 이미지 파일 목록 가져오기 (소문자 확장자 검사)
    image_files = [f for f in os.listdir(image_directory) if f.lower().endswith(('.jpg', '.png', '.jpeg'))]
    # 라벨 파일 목록 가져오기
    label_files = [f for f in os.listdir(label_directory) if f.lower().endswith('.txt')]
    
    try:
        with open(txt_filename, 'w', encoding='utf-8') as file:
            for image in image_files:
                label_name = os.path.splitext(image)[0] + '.txt'
                if label_name in label_files:
                    file.write(image + "\n")
        print(f"{txt_filename} 파일이 성공적으로 생성되었습니다.")
    except Exception as e:
        print(f"{txt_filename} 파일 작성 중 오류 발생: {e}")

# 셔플을 위한 함수
def shuffle_image_names(txt_filename, shuffle_count):
    with open(txt_filename, 'r', encoding='utf-8') as file:
        image_names = [line.strip() for line in file if line.strip()]
    
    image_mapping = []
    used_numbers = set()
    
    # 각 이미지에 대해 고유의 임의 정수를 할당
    for image in image_names:
        while True:
            random_number = random.randint(1000, 9999)
            if random_number not in used_numbers:
                used_numbers.add(random_number)
                break
        image_mapping.append((image, random_number))
    
    # shuffle_count 만큼 섞기
    for _ in range(shuffle_count):
        random.shuffle(image_mapping)
    
    return image_mapping

# 이미지와 라벨 파일을 임시 이름을 거쳐 최종 이름으로 변경하는 함수 (두 단계 rename)
def rename_images(image_mapping, image_directory, label_directory, new_txt_filename, base_name):
    new_mapping = []

    # 1단계: 기존 이미지 파일과 라벨 파일을 임시 이름으로 변경하여 충돌 방지
    temp_image_names = {}  # {원래파일명: 임시파일명}
    for idx, (old_image, _) in enumerate(image_mapping):
        old_image_path = os.path.join(image_directory, old_image)
        temp_image_name = f"temp_{idx}_{old_image}"
        temp_image_path = os.path.join(image_directory, temp_image_name)
        if os.path.exists(old_image_path):
            os.rename(old_image_path, temp_image_path)
            temp_image_names[old_image] = temp_image_name
        else:
            print(f"이미지 파일이 존재하지 않습니다: {old_image_path}")

    temp_label_names = {}  # {원래라벨명: 임시라벨명}
    for idx, (old_image, _) in enumerate(image_mapping):
        old_label = os.path.splitext(old_image)[0] + '.txt'
        old_label_path = os.path.join(label_directory, old_label)
        if os.path.exists(old_label_path):
            temp_label_name = f"temp_{idx}_{old_label}"
            temp_label_path = os.path.join(label_directory, temp_label_name)
            os.rename(old_label_path, temp_label_path)
            temp_label_names[old_label] = temp_label_name

    # 2단계: 임시 이름을 최종 이름(새로운 규칙)으로 변경
    for idx, (old_image, _) in enumerate(image_mapping):
        new_image_name = f"{base_name}_{str(idx).zfill(6)}.jpg"
        temp_image_name = temp_image_names.get(old_image)
        if temp_image_name:
            temp_image_path = os.path.join(image_directory, temp_image_name)
            new_image_path = os.path.join(image_directory, new_image_name)
            os.rename(temp_image_path, new_image_path)
            new_mapping.append((old_image, new_image_name))
        else:
            print(f"임시 이미지 이름을 찾을 수 없습니다 for {old_image}")
        
        # 라벨 파일 처리
        old_label = os.path.splitext(old_image)[0] + '.txt'
        new_label_name = f"{base_name}_{str(idx).zfill(6)}.txt"
        temp_label_name = temp_label_names.get(old_label)
        if temp_label_name:
            temp_label_path = os.path.join(label_directory, temp_label_name)
            new_label_path = os.path.join(label_directory, new_label_name)
            os.rename(temp_label_path, new_label_path)
        else:
            print(f"임시 라벨 이름을 찾을 수 없습니다 for {old_label}")

    # 매핑 파일 기록 (이전 이름 -> 새 이름)
    try:
        if os.path.exists(new_txt_filename):
            os.remove(new_txt_filename)
        with open(new_txt_filename, 'w', encoding='utf-8') as file:
            for old_name, new_name in new_mapping:
                file.write(f"{old_name} -> {new_name}\n")
        print(f"새로운 매핑 파일 {new_txt_filename}이 생성되었습니다.")
    except Exception as e:
        print(f"새로운 텍스트 파일 작성 실패: {new_txt_filename}, 오류: {e}")

already_shuffle = False
execute_rename_shuffle_count = 0

# 셔플 및 이름 변경 실행 함수
def execute_rename_shuffle():
    global already_shuffle
    global execute_rename_shuffle_count

    image_directory = image_dir_entry.get()
    label_directory = label_dir_entry.get()
    base_name = base_name_entry.get().strip()
    if not base_name:
        status_label.config(text="새로운 이름 규칙(베이스 이름)을 입력하세요.", fg="red")
        return

    try:
        shuffle_count = int(shuffle_count_entry.get())
    except:
        shuffle_count = 1

    # 첫 실행과 이후 실행 시 텍스트 파일 이름을 다르게 하여 매핑 기록
    if not already_shuffle:
        txt_filename = os.path.join(image_directory, 'image_names.txt')
        new_txt_filename = os.path.join(image_directory, 'updated_image_names.txt')
    else:
        txt_filename = os.path.join(image_directory, f'image_names_{execute_rename_shuffle_count}.txt')
        new_txt_filename = os.path.join(image_directory, f'updated_image_names_{execute_rename_shuffle_count}.txt')
    
    # 이미지 목록 저장 (이미지와 라벨이 모두 있는 파일만)
    save_image_names_to_txt(image_directory, label_directory, txt_filename)
    # 셔플 실행
    image_mapping = shuffle_image_names(txt_filename, shuffle_count)
    # 임시 이름 사용한 안전한 rename
    rename_images(image_mapping, image_directory, label_directory, new_txt_filename, base_name)

    if not already_shuffle:
        status_label.config(text="첫 번째 셔플 완료!", fg="green")
        already_shuffle = True
    else:
        status_label.config(text=f"셔플 {execute_rename_shuffle_count + 1}회 완료!", fg="green")
    
    execute_rename_shuffle_count += 1

# Initialize the main window
root = tk.Tk()
root.title("셔플러")
root.geometry("650x700")
root.config(bg="#f4f6f9")

# Global variables
image_folder_path = ""
txt_folder_path = ""

# Frame for buttons and labels
frame = tk.Frame(root, bg="#f4f6f9")
frame.pack(pady=20)

# Help Text for Instructions
help_label = tk.Label(root, text="사용법: \n1. '이미지 폴더'와 '라벨링 폴더'를 선택하세요.\n2. '정리 작업 실행' 버튼을 통해 빈 이미지/잘못된 라벨 파일을 제거합니다.\n3. '셔플러 실행' 버튼을 통해 이미지와 라벨의 이름을 임의로 섞어 새 이름으로 변경합니다.\n   (여러 번 실행 시, 기존 파일과의 이름 충돌 없이 임시 이름을 이용하여 안전하게 변경됩니다.)", 
                      bg="#f4f6f9", font=("Arial", 12), justify="left")
help_label.pack(pady=10)

# Buttons and Labels for Image Directory
image_dir_button = tk.Button(frame, text="이미지 폴더 선택", command=select_image_directory, width=30, height=2, bg="#4CAF50", fg="white", font=("Arial", 12, "bold"))
image_dir_button.grid(row=0, column=0, padx=20, pady=10)

image_dir_entry = tk.Entry(frame, font=("Arial", 12), width=30, bd=2)
image_dir_entry.grid(row=0, column=1, padx=20)

image_dir_label = tk.Label(frame, text="폴더가 선택되지 않았습니다.", bg="#f4f6f9", font=("Arial", 12))
image_dir_label.grid(row=0, column=2, padx=20)

# Buttons and Labels for Label Directory
label_dir_button = tk.Button(frame, text="라벨링 TXT 폴더 선택", command=select_label_directory, width=30, height=2, bg="#4CAF50", fg="white", font=("Arial", 12, "bold"))
label_dir_button.grid(row=1, column=0, padx=20, pady=10)

label_dir_entry = tk.Entry(frame, font=("Arial", 12), width=30, bd=2)
label_dir_entry.grid(row=1, column=1, padx=20)

label_dir_label = tk.Label(frame, text="폴더가 선택되지 않았습니다.", bg="#f4f6f9", font=("Arial", 12))
label_dir_label.grid(row=1, column=2, padx=20)

# Input for base name
base_name_label = tk.Label(root, text="새로운 이름 규칙(베이스 이름):", bg="#f4f6f9", font=("Arial", 12))
base_name_label.pack(pady=10)

base_name_entry = tk.Entry(root, font=("Arial", 12), width=40, bd=2)
base_name_entry.pack(pady=10)

# Input for shuffle count
shuffle_count_label = tk.Label(root, text="셔플 횟수 (기본 1회):", bg="#f4f6f9", font=("Arial", 12))
shuffle_count_label.pack(pady=5)

shuffle_count_entry = tk.Entry(root, font=("Arial", 12), width=10, bd=2)
shuffle_count_entry.pack(pady=5)

# Execute Buttons
execute_button = tk.Button(root, text="정리 작업 실행", command=execute_cleanup, width=30, height=2, bg="#2196F3", fg="white", font=("Arial", 12, "bold"))
execute_button.pack(pady=10)

rename_shuffle_button = tk.Button(root, text="셔플러 실행", command=execute_rename_shuffle, width=30, height=2, bg="#FF5722", fg="white", font=("Arial", 12, "bold"))
rename_shuffle_button.pack(pady=10)

# Status label
status_label = tk.Label(root, text="상태: 대기 중", bg="#f4f6f9", font=("Arial", 12), fg="gray")
status_label.pack(pady=20)

# Start the Tkinter event loop
root.mainloop()
