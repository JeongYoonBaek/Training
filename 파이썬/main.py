import requests, json #python에 필요한 (Scanner)과 비슷한 개념
from flask import Flask,request,jsonify,abort #python 전용 프레임워크
import sys
import urllib.request

application = Flask(__name__)



def kakaoRequestMsg(msg):
    mymsg = msg['userRequest']['utterance']  # 유저가 적은 메세지
    res = {
        "version" : "2.0",  # key와 각각의 값이 있어야 함
        "template": {
            "outputs": []
        }
    }
    result = {}  # 파이썬이나 자바스크립트 객체 특징임. 중간에 열고 닫으면 아무것도 없지만 이후에 키와 값을 넣어주면 자동으로 추가해줌. 배열과 다름
    result['res'] = res  # 유저가 적은 메세지를 담아줌
    result['msg'] = mymsg  # 이것들은 result = {'res': }  여기서부터 변수'version' : '2.0', 'template' : { 'outputs':[] }
    return result


def matjipList():
    myurl = 'https://api.odcloud.kr/api/3047940/v1/uddi:633f7dab-ffb5-4843-bc65-bd7f3b99dfa2?page=1&perPage=1000&serviceKey=9xBqP7CqYimcMjtI%2FC65UWk6z1HS%2FSoR6eGctgZYZiZekZxT4ueY7DWmlF9ERi9jD%2BWuZRkJ9KK%2FRqNdei%2Be7Q%3D%3D'
    response = urllib.request.urlopen(myurl)
    response = response.read().decode('utf8')
    data = json.loads(response)
    json_arr = data['data']
    result = ''
    for item in json_arr:
        result += f"식당명:{item['상호명']}, 대표메뉴:{item['주메뉴']}\n" # C#의 $같은 개념
    return result

def lottoInfo(num):
    url = 'https://www.dhlottery.co.kr/common.do?method=getLottoNumber&drwNo=' + num
    response = urllib.request.urlopen(url)
    response_msg = response.read().decode('utf8')
    jresponse = json.loads(response_msg)
    if jresponse['returnValue'] != 'success':
        return '잘못된 표기'
    else:
        lottoData = f"""
        {jresponse['drwtNo1']} {jresponse['drwtNo2']}
        {jresponse['drwtNo3']} {jresponse['drwtNo4']}
        {jresponse['drwtNo5']} {jresponse['drwtNo6']}
        보너스 : {jresponse['bnusNo']}
        """
    return lottoData

@application.route("/hellokakao", methods=["POST"])
def kakaochatbot():
    reqMsg = kakaoRequestMsg(request.get_json())  # 카톡에 고객이 뭐라 적었는데 json 문자형태로 날라오는데
    # 그걸 매개변수로 집어넣어서 약간의 내용을 추가해서 보내줌
    mymsg = reqMsg['msg']  # 카톡 메세지
    if mymsg == '맛집':
        resultMsg = matjipList()
    elif mymsg.split()[0] == '로또':  # split[0]은 공백을 기준해서 잘라줌 로또 < 얘가 0이고, 1< 얘는 1
        resultMsg = lottoInfo(mymsg.split()[1])  # 로또 번호 출력해줌
    txtResult = {}  # 비어있는 객체 생성
    txtResult['simpleText'] = {
        'text' : resultMsg # 객체 하나 만들고 텍스트라는 key가 있고 resultMsg라는 값을 넣어줌. 카카오에서 정해진 규격에 따라서 작성
    }
    reqMsg['res']['template']['outputs'].append(txtResult)  # txtResult에 res, template, outputs를 집어넣어줌
    return jsonify(reqMsg['res'])


if __name__ == "__main__" :
    application.run(host='0.0.0.0', port=5000)
