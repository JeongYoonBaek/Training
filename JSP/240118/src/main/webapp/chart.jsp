<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import = "java.util.Arrays" %>
<!DOCTYPE html>
<html>
<head>
  <title>국영수 점수 차트</title>
  <script src="https://d3js.org/d3.v7.min.js"></script>
  <style>
  	rect{fill : royalblue;}
  </style>
</head>
<body>

<h1>국영수 점수 차트 표현</h1>
<svg id="myChart"></svg>

<%
// 사용자가 입력한 국영수 점수 배열 선언
int kor = Integer.parseInt(request.getParameter("kor")); 	// ${param.korean};
int eng = Integer.parseInt(request.getParameter("eng"));	// ${param.english};
int math = Integer.parseInt(request.getParameter("math"));	// ${param.math};
int avr = (kor+eng+math)/3;

// 차트로 표현할 데이터 구성
int[] scores = {kor, eng, math};	// let score [k, e, m];
%>

<script>
  // 국영수 평균을 구해서, data로 추가를 하고 
  // 평균값보다 낮은 값에 대해서는 차트 색상을 빨간색으로
  // 평균값보다 높은 값에 대해서는 차트 색상을 초록색으로

  // D3 코드
  let result = <%= Arrays.toString(scores) %>;
  let svg = d3.select('#myChart');
  svg.selectAll('rect')
    .data(result)
    .enter()	// html 요소 - data 연결 시도
    .append('rect')
    .attr('x', 0)
    .attr('y', (data, index) => { return index * 35 + 17; })
    .attr('height', 25)
    .attr('width', (data, index) => { return data; });
  	.attr("fill", (data, index) => {
  		if(index === 3) {return "royalblue";}	// 평균값일 때에는, 그냥 검은색
  		else{	// 초록인지 빨강인지 구분
  			if(data >= score[3]) {return "Green";}
  			else{return "Red";}
  		}
  	})
  	
  	// 텍스트 추가 (과목명, 데이터값 출력)
  	let subject = ["국어", "영어", "수학", "평균"];
  	d3.select("#myChart")
  	.selectAll("text")
  	.data(socre)
  	.enter()
  	.append("text")
  	.text((data, index) => {return  subject[index]+ ": "+ data})	// "국어" : 90" 형태로 출력
  	.attr("x", (data, index) => return data + 5;)
  	.attr("y", (data, index) => return {return index * 35 + 17;})
  	.attr("fill", "navy")
</script>

</body>
</html>