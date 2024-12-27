import cv2
vidcap = cv2.VideoCapture('C:\\Users\\kiot\\Yolo V5\\yolov5\\TS6_sa-bt_2\\afternoon(12~16)\\2021-09-06_14-03-00_mon_sunny_out_sa-bt_C0091.mp4')
 
count = 0
 
while(vidcap.isOpened()):
    ret, image = vidcap.read()
 
    if(int(vidcap.get(1)) % 1 == 0):
        print('Saved frame number : ' + str(int(vidcap.get(1))))
        cv2.imwrite("C:\\Users\\kiot\\Yolo V5\\yolov5\\TS6_sa-bt_2\\person2\\person_%d.jpg" % count, image)
        print('Saved frame%d.jpg' % count)
        count += 1

vidcap.release()
