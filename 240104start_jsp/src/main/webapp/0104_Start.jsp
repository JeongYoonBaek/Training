<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<!--  실행 단축키 ctrl+ F11 -->
	<!--  jsp :: html 코드 안에서 java 코드를 작성할 수 있는 파일 -->
	<form method = "get" action = "0104_result.jsp">	<!-- action :: 어디 파일로 이동할 지 알려주는 것 -->
		<label>이름 :</label>
		<input type = "text" id = "name" />
		<input type = "submit" value = "제출" />
	</form>
</body>
</html>