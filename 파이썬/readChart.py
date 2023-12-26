import csv
import matplotlib.pyplot as plt

# 파일 열기
with open('myrain.csv', 'r') as file:
    # CSV 파일 읽기
    csv_reader = csv.reader(file)

    # 첫 행 스킵
    next(csv_reader)

    # 데이터 저장을 위한 리스트 초기화
    x_values = []
    y_values = []

    # 데이터 읽기
    for row in csv_reader:
        x_values.append(row[0])  # 0번째 열을 x 값으로 추가
        y_values.append(float(row[1]))  # 1번째 열을 float으로 변환하여 y 값으로 추가

# 막대 그래프 그리기
#plt.bar(x_values, y_values)
plt.plot(x_values, y_values,'bo-' )
# 그래프에 제목과 레이블 추가
plt.title('Monthly Rainfall Data in 2022')
plt.xlabel('Month')
plt.ylabel('Rainfall (mm)')

# 그래프 표시
plt.show()