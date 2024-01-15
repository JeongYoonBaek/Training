<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import = "java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
	// 서버에 저장되어 있는 세션을 불러와서, 사용자 이름을 브라우저 출력
	 Enumeration e = session.getAttributeNames();
	 while(e.hasMoreElements()){
		 String key = e.nextElement().toString(); 	// 세션의 키 값(인덱스)을 가져옴
		 String value = session.getAttribute(key).toString();	// 객체 형태로 반환되기 때문에
		 //value에 사용자 이름이 담겨져 있는 상태				// 문자열 형태로 받아줘야함
		
		 out.println(value+"님!");
	 }
%>
<p>환영합니다~~~</p>
</body>
</html>




