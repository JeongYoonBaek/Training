<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%! String name;  %>
<% name = "Baek JeongYoon";%>
<h2>스크립트릿으로 출력 </h2> 
<p>제 이름은 <%= "백정윤" %>입니다.</p>

<h2> EL 태그로 출력 </h2>
<p> 제 이름은 ${"백정윤"}입니다.</p>
<script>

	console.log(`100+100의 결과는 ${100+100}입니다.`);
</script>
</body>
</html>