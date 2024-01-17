package com.javalec.ex.Command;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.util.*;
import com.javalec.ex.DTO.MemberDTO;

	// Command 패턴 클래스의 틀을 작성하는 곳
	// 4개의 형태로 각각 다른 방식으로 저장

	// MemberService.java, MembreServiceInsert.java, CommandController.java는 컨트롤러 역할
public interface MemberService {
	// 인터페이스 :: 필드는 모두 상수, "메소드는 모두 추상메소드"
	
	// Execute 추상 메소드 만들기
	// Insert, Delete, "Select", login-test 기능
	public ArrayList<MemberDTO>execute(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;
		
	
}
