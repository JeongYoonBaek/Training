<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>MyInfo</title>
</head>
<body>
	<!--  
		(jsp 파일 3개 작성)
		이름과 나이를 입력받고
		나이가 20살 미만일 때, kid.jsp로
		아니라면 adult.jsp로 이동하게끔 하는 입력폼 작성
	 -->
	 
	 <%
	 	
	 	int a = Integer.parseInt(request.getParameter("age"));
	 	
	 	int age = 0;
	 	
	 	if(a<20){
	 		response.sendRedirect("kid.jsp");
	 	} else {
	 		response.sendRedirect("adult.jsp");
	 	}
	 %>
</body>
</html>