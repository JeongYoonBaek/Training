# 객체명을 객체번호로 매핑하는 딕셔너리
object_to_number = {
    "car": 0,
    "chair": 1,
    "bollard": 2,
    "bicycle": 3,
    # 필요한 다른 객체들을 여기에 추가하세요
}

def convert_object_name_to_number(object_name):
    return object_to_number.get(object_name, -1)

def convert_txt_labels(input_txt_path, output_txt_path):
    with open(input_txt_path, 'r', encoding='utf-8') as infile, open(output_txt_path, 'w', encoding='utf-8') as outfile:
        for line in infile:
            print(f"Original line: {line.strip()}")  # 디버깅용 출력
            
            # 라인에서 필요한 정보만 추출
            parts = line.strip().split()
            if len(parts) > 1:  # parts가 최소 2개 이상인지 확인
                # parts[1]에서 객체명 추출
                label_part = parts[1]  # label="truck"
                object_name = label_part.split('=')[1].strip('"')  # label 속성에서 객체명 추출
                print(f"Extracted object name: '{object_name}'")  # 디버깅용 출력
                
                # 객체명을 번호로 변환
                object_number = convert_object_name_to_number(object_name)
                print(f"Converted object number: {object_number}")  # 디버깅용 출력
                
                if object_number != -1:
                    # 변환된 번호로 태그 내용 업데이트
                    parts[1] = f'label="{object_number}"'  # 객체번호로 업데이트
                    converted_line = ' '.join(parts)  # 줄을 다시 합침
                    print(f"Converted line: {converted_line}")  # 디버깅용 출력
                    outfile.write(converted_line + '\n')  # 결과를 파일에 기록
                else:
                    print(f"Object name '{object_name}' not found in mapping.")  # 매핑되지 않은 객체 경고
                    outfile.write(line)  # 매핑되지 않은 객체는 원래 라인 그대로 저장
            else:
                print("Line is empty or not valid.")  # 빈 라인 처리
                outfile.write(line)  # 빈 라인 처리

# 예시 실행
input_txt_path = "C:/Users/kiot/Yolo V5/yolov5/DataSetSample/Bbox_0012/MP_SEL_001546.txt"   # 변환할 텍스트 파일 경로
output_txt_path = "C:/Users/kiot/Yolo V5/yolov5/DataSetSample/Bbox_0012/MP_SEL_001546.txt"  # 결과를 저장할 텍스트 파일 경로

convert_txt_labels(input_txt_path, output_txt_path)
print(f"Object names have been converted to numbers and saved to '{output_txt_path}'.")
