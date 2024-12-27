#사용할 라이브러리 설치
# !pip install xmltodict

import os # 파일 읽고, 쓰고, 위치 지정
import json # json 라이브러리
import xmltodict # xml 읽는 라이브러리

#xml이 있는 위치 -> 이폴더 안에 xml 파일만 존재 해야함. 
xml_path="D:\시각 장애인 사업 데이터셋\어린이 보호구역 어린이 위험행동\라벨링데이터\CCTV\driveway_walk_1"
# \ 을 / 로 수정해서 작성
# json을 넣을 위치
json_path = "D:\시각 장애인 사업 데이터셋\어린이 보호구역 어린이 위험행동\라벨링데이터\CCTV\driveaway_walk_json"

# xml 파일을 읽어서 리스트에 이름 담는다.
file_list = os.listdir(xml_path) #주의 폴더 안에 xml 파일이 아닌 파일이 있으면 에러가 난다.

# 반복
for i in range(len(file_list)): 
  #처음 작업할 파일 이름 읽기
  temp_str = file_list[i]
  #그중 .xml 확장자를 지운다.
  name = temp_str.replace(".xml","")
  #최대 길이 80자 까지 가능하다.-> 코랩 기준
  name = name[:80] # 위의 작업으로 파일 이름 지정
  print(name) # 작업중인 파일의 이름 -> 멈출시 여기서 에러 발생

  #읽어오기
  with open(xml_path+'/'+file_list[i],'r',encoding='UTF8') as f:
    xmlString = f.read()
  jsonString = json.dumps(xmltodict.parse(xmlString), indent=3, ensure_ascii=False)
  
  #작성하기
  with open(os.path.join(json_path, f"{name}.json"), 'w',encoding='UTF8') as f:
    f.write(jsonString)