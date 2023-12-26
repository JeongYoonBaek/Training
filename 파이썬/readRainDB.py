import json
import urllib.request
import pymysql
import matplotlib.pyplot as plt

myurl = 'https://api.odcloud.kr/api/15064727/v1/uddi:e8780f68-fb0a-411d-b241-833bc2b3f840?page=1&perPage=100&serviceKey=US2tgSP8p9PgyDSVUkkh%2F6tQyLyTovIa%2FXz3%2Bo7wWcK1IPfMszSOawcZ5ISfJM7N2FKDRbvhIkG6Y%2Byi3DqEaw%3D%3D'
response = urllib.request.urlopen(myurl)  # url이라는 변수에 넣어줌
response = response.read().decode('utf8')  # 이 코드는 필요할 수도 필요 없을 수도 있음

data = json.loads(response)
json_arr = data['data']  # key가 'data'인 것만 갖고 옴
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

sql = 'insert into rain(month, mm) '
sql = sql + "values('%s', '%s')"  # 3개의 값을 필요로 하는 변수를 만듦
# 이번에는 커밋을 한번만 할 것임. 대신에, 안정성이 떨어지지만 코드 보기가 편함
cur = conn.cursor()
for item in json_arr:
    cur.execute(sql % (item['측정연월'], item['강수량(mm)']))
conn.commit()  # 데이터가 백개던 천개던 커밋을 한번만 수행함
sql1 = 'select mm from rain'
sql2 = 'select month from rain'
cur.execute(sql1)
mm = cur.fetchall() # select 결과물을 여기에 다 넣음. 집어넣는 방식 특이함.
cur.execute(sql2)
mth=cur.fetchall()

conn.close()  # with 코드가 없으므로 수동으로 닫아줘야 함
plt.bar([mth[0] for mth in mth],[mm[0] for mm in mm])
plt.show()
