package com.javalec.ex.DAO;

import java.sql.*;
import javax.sql.DataSource;

import com.javalec.ex.DTO.MemberDTO;

import java.util.*;
import javax.naming.*;	// Context와 InitialContext();는 여기서 파생된다.

public class MemberDAO {
	private Connection conn = null;
	private Statement st = null;
	private ResultSet rs = null;
	private PreparedStatement ps = null;
	
	private DataSource ds = null;
	
	// MemberDAO 생성자 생성
	public MemberDAO() {
		try {
			// jdbc 드라이버 로드
			Context ctx = new InitialContext();
			ds = (DataSource)ctx.lookup("java:comp/env/jdbc/mysql");
		}catch(Exception e) {
			System.out.println("MemberDAO 생성자 에러");
			e.printStackTrace();
		}
	}
	
	// 회원추가 메소드
	public void MemberInsert(String id, String pw, String name) {
		conn = null;
		ps = null;
		// ds 초기화 해버리면 DB 접속에 문제가 생김.
		try {
			// DB 접속
			conn = ds.getConnection();
			
			// INSERT 구문 수행
			String query = "INSERT INTO member VALUES (?, ?, ?)";
			// ? 변수가 있으니 ps 객체 사용
			ps = conn.prepareStatement(query);
			ps.setString(1, id);
			ps.setString(2, pw);
			ps.setString(3, name);
			ps.executeUpdate();
		}catch (Exception e) {
			System.out.println("Insert 쿼리 수행 실패");
			e.printStackTrace();
		} finally {
			try { 	// 사용한 객체는 finally의 try문 안에 객체 닫기 실행
				ps.close();
				conn.close();
			} catch(Exception e2) {
				System.out.println("객체 닫기 실패");
				e2.printStackTrace();
			}
		}
	}
	
	// 회원 삭제 메소드
	public void MemberDelete(String id) {
		conn = null;
		ps = null;
		
		try {
			conn = ds.getConnection();
			String query = "DELETE FROM member WHERE id = ?";
			
			ps = conn.prepareStatement(query);
			ps.setString(1, id);
			ps.executeUpdate();
		} catch(Exception e) {
			System.out.println("Delete 쿼리 수행 실패");
			e.printStackTrace();
		} finally {
			try {
				ps.close();
				conn.close();
			} catch(Exception e2) {
				System.out.println("객체 닫기 실패");
				e2.printStackTrace();
			}
		}
	}
	
	// 로그인 테스트 메소드 
	public void MemberSelect(String id, String pw) {
		conn = null;
		ps = null;
		rs = null;
		
		try {
			conn = ds.getConnection();
			String query = "SELECT FROM member WHERE id = ? && passwd = ?";
			
			ps = conn.prepareStatement(query);
			ps.setNString(1, id);
			ps.setNString(2, pw);
			ps.executeUpdate();
		} catch(Exception e) {
			System.out.println("Select 쿼리 수행 실패");
			e.printStackTrace();
		} finally {
			try {
				ps.close();
				conn.close();	
				rs.close();
			} catch(Exception e2) {
				System.out.println("객체 닫기 실패");
				e2.printStackTrace();
			}
		}
	}
	
	// 회원정보 출력 메소드 
	public ArrayList<MemberDTO> MemberSel(){
		ArrayList<MemberDTO> result = new ArrayList<MemberDTO>();	// result라는 배열 생성
		conn = null;
		st = null;
		rs = null;
		
		try {
			conn = ds.getConnection();
			
			String query = "SELECT * FROM member";
			st = conn.createStatement();
			rs = st.executeQuery(query);
			
			while(rs.next()) {
				MemberDTO element = new MemberDTO();
				element.setId(rs.getString("id"));
				element.setPw(rs.getString("passwd"));
				element.setName(rs.getString("name"));
				// element 객체에 데이터 한 묶음씩 저장하기
				result.add(element);
			}
		}catch(Exception e){
			System.out.println("SELECT 전체 쿼리 수행실패");
			e.printStackTrace();
			}finally {
				try {
					conn.close();
					st.close();
					rs.close();		
			} catch(Exception e2) {
				System.out.println("객체 닫기 실패");
				e2.printStackTrace();
			}
		}
		
		return result;
	}
}


