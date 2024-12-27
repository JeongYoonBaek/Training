def replace_object_name(input_txt_path, output_txt_path, old_name, new_name):
    # 파일을 읽고 객체명을 변경
    with open(input_txt_path, 'r', encoding='utf-8') as infile:
        lines = infile.readlines()

    # 객체명을 변경
    modified_lines = []
    for line in lines:
        modified_line = line.replace(old_name, new_name)  # old_name을 new_name으로 변경
        modified_lines.append(modified_line)

    # 변경된 내용을 새 파일에 저장
    with open(output_txt_path, 'w', encoding='utf-8') as outfile:
        outfile.writelines(modified_lines)

    print(f"Replaced '{old_name}' with '{new_name}' in '{output_txt_path}'.")

# 예시 실행
input_txt_path = "C:/Users/kiot/Yolo V5/yolov5/DataSetSample/Bbox_0012/MP_SEL_001578.txt"  # 입력 파일 경로
output_txt_path = "C:/Users/kiot/Yolo V5/yolov5/DataSetSample/Bbox_0012/MP_SEL_001578.txt"  # 출력 파일 경로
old_name = 'tree_trunk2'  # 변경할 객체명
new_name = 'tree_trunk'  # 새로운 객체명

replace_object_name(input_txt_path, output_txt_path, old_name, new_name)
