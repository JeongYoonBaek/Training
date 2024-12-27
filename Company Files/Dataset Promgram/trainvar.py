import glob

input_dir='C:\\Users\\kiot\\Yolo V5\\yolov5\\TS6_sa-bt_2\\train'
f = open('C:\\Users\\kiot\\Yolo V5\\yolov5\\TS6_sa-bt_2\\train_list.txt', 'w')
input_file=glob.glob(input_dir+'*.txt')

for file in input_file:
    f.write(file[:15]+'images\\'+file[15:-4]+'.jpg \n')
f.close()


f = open('C:\\Users\\kiot\\Yolo V5\\yolov5\\TS6_sa-bt_2\\valid\\valid_list.txt', 'w')

for file in input_file:
    f.write(file[:15]+'images\\'+file[15:-4]+'.jpg \n')
f.close()

