package com.javalec.ex.DTO;

	// MemberDTO -> MemberService
	// DTO, 자바빈 형태이고 (클래스 파일로 생성) 인터페이스 반환형 참조
	// DTO와 DAO는 모델형태임
	
public class MemberDTO {
	private String id;
	private String pw;
	private String name;
	
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getPw() {
		return pw;
	}
	public void setPw(String pw) {
		this.pw = pw;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
}
