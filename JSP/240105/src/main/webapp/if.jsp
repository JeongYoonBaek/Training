<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
	<!--  jsp ���� 3�� �ʿ� :: kid.jsp, adult.jsp, if.jsp -->
	<!--  ������ ���� ����, ��� �������� �̵��Ұ����� ���⼭ ���� -->
	<%
		int age = Integer.parseInt(request.getParameter("age"));
	
		if(age < 20){ 	// kid.jsp�� �̵�
			// sendRedirect() :: form�� action ���� (response ��ü)
			response.sendRedirect("kid2.jsp");
		}
		else{	// adult.jsp�� �̵�
			response.sendRedirect("adult2.jsp");
		}
	%>
</body>
</html>