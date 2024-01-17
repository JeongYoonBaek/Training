package com.javalec.ex.Controller;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.javalec.ex.Command.MemBerServiceSel;
import com.javalec.ex.Command.MemberService;
import com.javalec.ex.Command.MemberServiceDelete;
import com.javalec.ex.Command.MemberServiceInsert;
import com.javalec.ex.Command.MemberServiceSelect;
import com.javalec.ex.DTO.MemberDTO;

/**
 * Servlet implementation class CommandController
 */
@WebServlet("*.do")
public class CommandController extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CommandController() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doAction(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doAction(request, response);
		
	}
	
	// 어느 명령어로 갈 지 작성하는 곳
	protected void doAction(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		String uri = request.getRequestURI();
			// 사용자가 불러온 링크를 반환 (ex) /240117/insert.do
		String conPath = request.getContextPath();	// 프로젝트명 반환
		String command = uri.substring(conPath.length());	
			// insert.do, delete.do ... 형식으로 command에 저장
		
		// View(jsp), Controller(프론트 컨트롤러, 커멘드)
		MemberService mService = null; 	// 인터페이스 자체는 객체 생성 불가, execute만 장착이 됨. 타입만 구성됨.
		if(command.equals("/insert.do")) {	
			// "회원 추가" 수행을 요청할 시
			System.out.println("<회원 추가>를 수행합니다.");
			mService = new MemberServiceInsert();
		}
		else if(command.equals("/delete.do")){
			System.out.println("<회원 삭제>를 수행합니다.");
			mService = new MemberServiceDelete();
		}
		else if(command.equals("/select.do")) {
			System.out.println("<로그인 테스트>를 수행합니다.");
			mService = new MemberServiceSelect();
		}
		else if(command.equals("/sel.do")) {
			System.out.println("<회원 전체 출력>을 수행합니다.");
			mService = new MemBerServiceSel();
		}
			
			// insert, delete, login-test 할 땐 execute() 실행만 됨 -> null값 반환
			// select 할 땐 result로 실질적인 값이 반환될 것
			ArrayList<MemberDTO> result = mService.execute(request, response);
			if(result != null) {
				// Controller 에서만 처리할 수 있는건 그냥 그렇게 하면 됨
				// 다만 View의 역할이 필요할 땐 RequestDispatcher를 사용
				//		다른 페이지에서 처리할 수 있도록 연결
				RequestDispatcher dis = request.getRequestDispatcher("/getList.jsp");
				dis.forward(request, response);
			}
			
		response.sendRedirect("admin_page.html");
	}
}
