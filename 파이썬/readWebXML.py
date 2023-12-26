import xml.etree.ElementTree as elemTree # ElementTree를 elemTree로 줄여부름
import requests # python을 하게 되면 pip 키워드를 많이 사용하게 될거임. alt+f12 후 pip install requests
# c나 java는 파일을 다운 받고 실행 해야 하는데 python은 pip 명령어만 사용해도 설치 가능

myurl = 'https://api.odcloud.kr/api/3047940/v1/uddi:633f7dab-ffb5-4843-bc65-bd7f3b99dfa2?page=1&perPage=1000&returnType=XML&serviceKey=US2tgSP8p9PgyDSVUkkh%2F6tQyLyTovIa%2FXz3%2Bo7wWcK1IPfMszSOawcZ5ISfJM7N2FKDRbvhIkG6Y%2Byi3DqEaw%3D%3D'
response = requests.get(myurl) # url을 리스폰스로부터 갖고와서 응답하고
xmldatas = elemTree.fromstring(response.text) # 문자열을 가지고 xml 데이터로 변환해서 집어넣음
myresult = xmldatas.find('data').findall('item')

for item in myresult:
    print('식당명 : {}, 주메뉴 : {}, 전화번호 : {} '.format
          (item.find('./col[@name="상호명"]').text, # .text: 문자열로 변환시키는 별도의 작업
           item.find('./col[@name="주메뉴"]').text,
           item.find('./col[@name="전화번호"]').text))