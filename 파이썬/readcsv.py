import csv # csv 파일 읽는 라이브러리 호출

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

    #print(item)
# ctrl + shift + f10 : 내가 현재 실행 중인 파일 코드 실행

# 2. 출력 양식을 아래와 같이 바꾸기
# 상호명 : ~~~, 전화번호 : ~~~~, 대표메뉴 : ~~~
for item in mydatas:
    print( ('상호명 : %s, 전화번호: %s, 대표메뉴 : %s') %
           (item[1], item[3], item[4]))