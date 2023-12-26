import json
import urllib.request
import pymysql

myurl = 'https://api.odcloud.kr/api/3047940/v1/uddi:633f7dab-ffb5-4843-bc65-bd7f3b99dfa2?page=1&perPage=1000&serviceKey=US2tgSP8p9PgyDSVUkkh%2F6tQyLyTovIa%2FXz3%2Bo7wWcK1IPfMszSOawcZ5ISfJM7N2FKDRbvhIkG6Y%2Byi3DqEaw%3D%3D'
response = urllib.request.urlopen(myurl)  # url이라는 변수에 넣어줌
response = response.read().decode('utf8') # 이 코드는 필요할 수도 필요 없을 수도 있음
print(response)

# response 데이터를 json 형태로 바꿈
data = json.loads(response)
json_arr = data['data'] # key가 'data'인 것만 갖고 옴
# csv와는 다르게 열 이름(column 이름)을 직접 입력할 수 있음
# for item in json_arr:
# print(f"식당명 : {item['상호명']}, 대표메뉴 : {item['주메뉴']}")

conn = pymysql.connect(
    host='localhost',
    user='root',
    password='1234',
    db='apidb',
    charset='utf8'
)

sql = 'insert into apitable(name, hp, menu) '
sql = sql + "values('%s', '%s', '%s')" # 3개의 값을 필요로 하는 변수를 만듦
# 이번에는 커밋을 한번만 할 것임. 대신에, 안정성이 떨어지지만 코드 보기가 편함
cur = conn.cursor()
for item in json_arr:
    cur.execute(sql % (item['상호명'], item['전화번호'], item['주메뉴']))
conn.commit() # 데이터가 백개던 천개던 커밋을 한번만 수행함
conn.close() # with 코드가 없으므로 수동으로 닫아줘야 함
