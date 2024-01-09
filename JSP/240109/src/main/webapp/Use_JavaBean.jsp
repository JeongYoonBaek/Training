<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <!--  com.javalec.ex 패키지 안에 있는 user 파일을 포함 -->
<%@ page import = "com.javalec.ex.user" %>
<!DOCTYPE html>

<!--  액션 태그 :: jsp 태그 중 일부 -->

<!--  jsp:useBean :: 객체 생성 -->
<!--  user.java를 통해서 user1 이라는 객체 생성 -->
<jsp:useBean id = "user1" 
	class="com.javalec.ex.user" scope = "page"/>

<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<!--  setProperty, getProperty  -->
	<%!	String id, pw, name, nickname; %> <!--  스크립트 선언문을 사용하여 String 선언 -->
	<%
		id = request.getParameter("id");	// 여기서는 변수명만 선언해도 됨
		pw = request.getParameter("pw");
		name = request.getParameter("name");
		nickname = request.getParameter("nick");
	%>
	
		<!--  setProperty(멤버값 설정), getProperty(멤버값 반환)  -->
		<jsp:setProperty name = "user1" property = "id" value = "<%=id %>" />
		<jsp:setProperty name = "user1" property = "password" value = "<%=pw %>" />
		<jsp:setProperty name = "user1" property = "name" value = "<%=name %>" />
		<jsp:setProperty name = "user1" property = "nickname" value = "<%=nickname %>" />
		
		<h3>계정 생성이 완료되었습니다.</h3>
		아이디 :: <jsp:getProperty name = "user1" property = "id" /> <br>
		비밀번호 :: <jsp:getProperty name = "user1" property = "password" /> <br>
		닉네임 :: <jsp:getProperty name = "user1" property = "nickname" /> <br>
		이름 :: <jsp:getProperty name = "user1" property = "name" /> <br>
		
		<form action = "input_user.html">
			<input type = "submit" value = "회원가입 폼으로 돌아가기" />
		</form>
</body>
</html>