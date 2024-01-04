<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h1>연산 결과</h1>
	<%
		request.setCharacterEncoding("EUC-KR");
	
		int num1 = Integer.parseInt(request.getParameter("num1"));
		int num2 = Integer.parseInt(request.getParameter("num2"));
		
		String operator = request.getParameter("oper");
		
	%>
	 <%
    if (operator.equals("+")) { %>
           <%=num1%> + <%=num2%> = <%=num1+num2 %>
       <%
        } else if (operator.equals("-")) { %>
            <%=num1%> - <%=num2%> = <%=num1-num2 %>
       <%
        }else if (operator.equals("*")){ %>
            <%=num1%> * <%=num2%> = <%=num1*num2 %>
       <%
        }else{    %>
            <%=num1%> / <%=num2%> = <%=num1/num2 %>
       <%
        }
        %>	
</body>
</html>