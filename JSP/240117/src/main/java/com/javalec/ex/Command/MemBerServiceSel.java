package com.javalec.ex.Command;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.javalec.ex.DAO.MemberDAO;
import com.javalec.ex.DTO.MemberDTO;

public class MemBerServiceSel implements MemberService{
	public ArrayList<MemberDTO> execute(HttpServletRequest request, HttpServletResponse response){
		ArrayList<MemberDTO> result = new ArrayList<MemberDTO>();
		
		// DB 연동
		MemberDAO dao = new MemberDAO();
		result = dao.MemberSel();
		
		request.setAttribute("list", result); 	// 결과값은 여기에 집어넣음
		
		return result;
	}
}
