<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
		<!--  
		(���� jsp ���� �ۼ�) 
		���õ� ǥ �������� 
		�������� �ۼ��Ͽ���.
		(th, td �����ϴ� ���X)
		-->
		

	<table border = "1">
		<% String arr[] = {"x", "2", "3", "4", "5", "6", "7", "8", "9"}; %>
		<tr>	<!-- ������ ������� �ƴ϶�, ��������� ���������� ��� -->
			<% for(int i = 0; i < 9; i++){ %>
				<th><%=arr[i] %> </th>
			<%} %>
		</tr>
		<% for(int i = 1; i <= 9; i++){%>
		<tr>
			<% for(int j = 1; j <=9; j++){ %>
				<td> <%=i*j %>	</td>
			<%} %>
		</tr>
		<%}  %>
	</table>
</body>
</html>