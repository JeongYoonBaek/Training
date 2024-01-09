<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="com.javalec.ex.studentDAO" %>
<%@ page import="java.util.ArrayList" %>


<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>StudentDAO</title>
</head>
<body>
	<h2>학생 정보 조회</h2>
	<table border="1" text-align : center; >
		<tr>
			<th>학번, 이름, 나이, 학년, 전공</th>
		</tr>
<%
studentDAO dao = new studentDAO();
ArrayList<String> studentList = dao.showAllStudent();

for(int i = 0; i <= 2; i++){
	String stu = studentList.get(i);

%>
	<tr>
	<td><%= stu%></td>
	</tr>
	<% } %>
	</table>

</body>
</html>