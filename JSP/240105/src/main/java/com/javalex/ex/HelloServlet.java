package com.javalex.ex;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class HelloServlet
 */
@WebServlet(name = "Hello", urlPatterns = { "/Hello" }) 
// 이 서블릿에 접근하기 위해서는, com.javalex.ex/HelloServlet.java
// 경로를 간결하게 하기 위해서, url 주소 일부(뒷부분)를 치환
// url 매핑 하는게 좋음
public class HelloServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public HelloServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// response.getWriter().append("Served at: ").append(request.getContextPath());
		response.setCharacterEncoding("UTF-8");
		// 여기에선, 브라우저 상에서 나타나게끔 설정 -> append()
		response.setContentType("text/html; charset = UTF-8");
		
		String name = request.getParameter("name");
		response.getWriter().append("<h3>"+ name + "님 환영합니다.</h3>");
		
		System.out.println("GET 메소드 실행하였습니다.");	// 이게 일종의 로그임.
		// 에러 내용이 생기면 아래 console 내용을 확인하여 어디에 에러가 생겼는지 파악하면 좋음 
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setCharacterEncoding("UTF-8");
		String name = request.getParameter("name");
		
		System.out.println(name+"님 환영합니다!!!");
		
		// POST가 GET 형식보다 보안에 강화되어있다.
	}

}
