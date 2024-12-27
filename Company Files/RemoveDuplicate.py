import os 
import pandas as pd
import re # regex 정규표현식

# 사진 목록 불러오기
photo_list = []

for f in os.listdir('c:\\users\\kiot\\Yolo v5\\yolov5\\이미지 중복'):
    if 'jpg' in f:
        photo_list.append(f)
        
# 사진의 크기 구하기 (os.path.getsize는 파일크기 구하기)
photo_size = list(map(lambda x: os.path.getsize('c:\\users\\kiot\\Yolo v5\\yolov5\\이미지 중복' + '/' + x), photo_list))

# 데이터 프레임으로 만들기
fsp = pd.DataFrame({'filename_raw' : photo_list, 'size':photo_size})

print('사진의 갯수 :', len(fsp))

# 숫자 제거하기
com = re.compile('\d')

fsp['filename'] = list(map(lambda x : com.sub('', x), photo_list))

#겹치는 파일명 / 파일크기 확인 
pvc = pd.DataFrame({'filename':fsp['filename'].value_counts().index, 'fn_counts':fsp['filename'].value_counts().values})
psvc = pd.DataFrame({'size':fsp['size'].value_counts().index, 'size_counts':fsp['size'].value_counts().values})

fsp = pd.merge(fsp, pvc, how = 'left', on = 'filename')
fsp = pd.merge(fsp, psvc, how = 'left', on = 'size')

fsp.sample(2)

# 이름은 같은데 크기가 다른거 찾기 
for i in range(len(fsp)):
   if (fsp['fn_counts'] [i] > 1) & (fsp['size_counts'] [i] == 1):
        print(i) 
        
# df.sort_values(['기준열']) : 정렬 
# df.drop_duplicates(['기준열]) : 중복제거
fsp_nsn = fsp.sort_values(['filename_raw'], ascending = False).drop_duplicates(['filename'], keep ='first') 

print('남은 사진의 갯수 : {}\n지워진 사진의 갯수 : {}'.format(len(fsp_nsn), len(fsp) - len(fsp_nsn))) 

pvc_nsn = pd.DataFrame({'filename' : fsp_nsn['filename'].value_counts().index, 'fn_counts_nsn':fsp_nsn['filename'].value_counts().values})
psvc_nsn = pd.DataFrame({'size' : fsp_nsn['size'].value_counts().index, 'size_counts_nsn' : fsp_nsn['size'].value_counts().values})

fsp_nsn = pd.merge(fsp_nsn, pvc_nsn, how = 'left', on = 'filename')
fsp_nsn = pd.merge(fsp_nsn, psvc_nsn, how = 'left', on = 'size')

fsp_nsn[fsp_nsn['fn_counts_nsn']!=1]

print('사이즈 겹치는 사진의 갯수 : ', len(fsp_nsn[fsp_nsn]['size_counts_nsn']!=1))
print('중복 사이즈의 갯수 :', len(psvc_nsn[psvc_nsn['suze_counts_nsn']]>1))


