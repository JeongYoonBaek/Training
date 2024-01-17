package com.javalec.ex.Command;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.javalec.ex.DAO.MemberDAO;
import com.javalec.ex.DTO.MemberDTO;

public class MemberServiceDelete implements MemberService {
		public ArrayList<MemberDTO> execute(HttpServletRequest request, HttpServletResponse response) {
			ArrayList<MemberDTO> dto = null;
			
			MemberDAO dao = new MemberDAO();
			String id = request.getParameter("id");
			dao.MemberDelete(id);
			
			return dto;
	}
}