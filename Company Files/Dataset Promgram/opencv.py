import cv2

def draw_bounding_boxes(image_path, txt_file_path):
    """이미지에 바운딩 박스를 그린 후 표시"""
    image = cv2.imread(image_path)
    height, width, _ = image.shape
    
    with open(txt_file_path, 'r', encoding='utf-8') as file:
        lines = file.readlines()
        
        for line in lines:
            parts = line.strip().split()
            class_id = int(parts[0])
            bbox = list(map(int, parts[1:]))
            
            # 바운딩 박스 그리기
            cv2.rectangle(image, (bbox[0], bbox[1]), (bbox[2], bbox[3]), (0, 255, 0), 2)
    
    cv2.imshow('Image with Bounding Boxes', image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# 예시 경로 설정
image_path = 'D:\\139.Daily Life Task and Command Execution Data_Space_2nd Year\\Open Data\\Data\\Training\\Source Data\\TS\\CB001S017\\RGB\\CB001S017_step0.camera.png'
txt_file_path = 'D:\\139.Daily Life Task and Command Execution Data_Space_2nd Year\\Open Data\\Data\\Training\\Source Data\\TS\\CB001S017\\RGB\\CB001S017_step0.camera.txt'

draw_bounding_boxes(image_path, txt_file_path)
