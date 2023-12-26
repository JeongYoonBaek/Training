import csv # csv 파일 읽는 라이브러리 호출
import pymysql # python 코드를 이용하여 mysql에 접근

# f = 파일을 처리하는 함수
# open 함수를 통해 읽어들인 파일에 대한 내용을 저장
f = open('mydata.csv', 'r')

rdr = csv.reader(f) # 파일 데이터를 읽음

mydatas = [] # 리스트 선언 c#의 list나 java의 arraylist처럼 선언했다고 보면 됨

isStart = True
for line in rdr: # rdr에 있는 걸 한줄 씩 읽을 것.

    # 실습문제
    # 1. 연번, 상호명 등 (맨 첫번째 내용) 이건 안나오게 출력하기 (if와 pass 키워드 이용)
    if isStart:
        isStart = False
        pass
    else:
        mydatas.append(line)
f.close()

sql = 'insert into apitable(name, hp, menu) '
sql = sql + "values('%s', '%s', '%s')" # 3개의 값을 필요로 하는 변수를 만듦

for item in mydatas: # db와 연결하는 정보
    conn = pymysql.connect(
        host = 'localhost',
        user = 'root',
        password = '1234',
        db = 'apidb',
        charset = 'utf8'
    )
    # with : db 연결 후에 다 되면 자동으로 연결 끊어줌 
    # strip() : 양옆 공백 제거 
    # replace() : 특정 문자를 다른 문자로 대체함
    with conn:
        with conn.cursor() as cur: # db 안에 실제 명령 수행하는 것 cursor을 cur로 줄임
            cur.execute(sql % (item[1], item[3], item[4])) # 컬럼의 2, 4, 5번째 정보를 가져옴
            conn.commit() # conn을 저장해줌
# 커밋 여러번 함 안정성이 높아지지만 코드 보기가 불편함