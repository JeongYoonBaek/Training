package com.javalec.ex;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class delete
 */
@WebServlet("/delete")
public class delete extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public delete() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doAction(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doAction(request, response);
	}
	
	// delete를 doAction으로 통해 이동
	protected void doAction (HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8"); // 세션 입력값
		
		// "어느 계정을 삭제할 것인가" -> 지금 활용할 수 있는건 세션에 있는 "id"값 뿐
		HttpSession session = request.getSession();
		String id = session.getAttribute("id").toString(); // object 객체이기 때문에 toString() 선언하고
													// 타입이 충돌하지 않게끔 설정
		// 세션에 있는 아이디 값은 받은 상태
		// "DB에 접속" (DAO)해서, id 변수의 값을 아이디 값으로 갖는 "데이터 삭제"
		employeeDAO dao = new employeeDAO();
		dao.deleteUser(id);
		session.invalidate(); // 저장되어있는 값은 무효화
		response.sendRedirect("input_login.html");
	}
		
		
		// request.setCharacterEncoding("UTF-8");
//		String id = request.getParameter("id");
//		String pw = request.getParameter("pw");
//		
//		employeeDAO dao = new employeeDAO();
//		HttpSession session = request.getSession();
//		
//		String did = session.getAttribute("did").toString();
//		String dpw = session.getAttribute("dpw").toString();


}
