import cv2
import json

# 동영상 파일 경로
video_path = 'C:\\Users\\kiot\\Yolo V5\\yolov5\\TS6_sa-bt_2\\morning(9~12)\\2021-09-08_09-51-00_wed_sunny_out_sa-bt_C0091.mp4'

# 객체 인식 모델 초기화 (예시로 YOLOv5 사용)
model = cv2.dnn.readNetFromDarknet('yolov5.cfg', 'yolov5.weights')
model.setPreferableBackend(cv2.dnn.DNN_BACKEND_OPENCV)
model.setPreferableTarget(cv2.dnn.DNN_TARGET_CPU)  # GPU 사용 시 DNN_TARGET_CUDA

# 동영상 파일 열기
cap = cv2.VideoCapture(video_path)

# 객체 인식을 위한 함수 정의
def detect_objects(frame):
    blob = cv2.dnn.blobFromImage(frame, 1/255.0, (416, 416), swapRB=True, crop=False)
    model.setInput(blob)
    outputs = model.forward(model.getUnconnectedOutLayersNames())
    # outputs를 기반으로 객체 인식 결과 처리

# 프레임 단위로 처리
while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break
    
    # 여기서 frame에 객체 인식을 적용하고, 필요한 처리를 수행
    detect_objects(frame)
    
    # 예를 들어, 객체 인식 결과를 사용하여 텍스트 파일에 저장하거나 다른 작업 수행 가능

    # 결과 프레임을 화면에 출력하거나 저장할 때 사용할 코드 (예시)
    cv2.imshow('Frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):  # 'q' 키를 누르면 종료
        break

# 종료 작업
cap.release()
cv2.destroyAllWindows()
