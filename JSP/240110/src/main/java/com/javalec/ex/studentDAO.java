package com.javalec.ex;
import java.sql.*;
import java.util.ArrayList;


public class studentDAO {

	// DAO :: DB와 관련된 처리를 자바빈으로 따로 만들어서 처리

	// jdbc :: DB와의 연결을 돕는 도구



	// 데이터베이스 접속에 필요한 정보를 필드로 초기화

	private String url = "jdbc:mysql://localhost:3306/apidb";

	private String id = "root";

	private String pw = "1234";



	// 데이터베이스 사용에 필요한 객체 3가지

	private Connection conn = null; // jdbc 연결 객체

	private Statement st = null; // SQL문 실행

	private ResultSet rs = null; // SQL문 실행 결과 담는 객체



	public studentDAO() {

		try {

			// jdbc 드라이버 여기로 불러오기

			Class.forName("com.mysql.jdbc.Driver");

		} catch (Exception e) {

			// 실행을 중단하고 catch문으로 옴

			System.out.println("JDBC 드라이버 연동 실패");

		}

	}



	// 메소드 :: DB연동이 필요한 기능들을 아래에 메소드 형태로 나누어 작성

	public ArrayList<String> showAllStudent() {

		ArrayList<String> result = new ArrayList<String>();



		try {



			conn = DriverManager.getConnection(url, id, pw); // 데이터베이스 접속 시도



			String query = "SELECT * FROM STUDENT";

			st = conn.createStatement();	// statement 객체 초기화

			rs = st.executeQuery(query);	// SQL 실행결과를 rs에 저장



			while(rs.next()) {	//데이터들을 하나하나 탐색하면서 반복문을 돌림

				// 테이블 표 한칸에 데이터의 모든 칼럼정보가 들어가기 때문에

				// 아예 문자열 형태로 만들어서, ArrayList에 하나씩 저장

				String r="";

				r += rs.getInt("hakbun");

				r += ",";

				r += rs.getString("name");

				r += ",";

				r += rs.getInt("age");

				r += ",";

				r += rs.getInt("grade");

				r += ",";

				r += rs.getString("major");

				//여기까지 오게 되면, 문자열 r 에는 5가지 칼럼의 저보가 모두 담기게 된다

				

				result.add(r);

			}

		} catch (Exception e) {

			System.out.println("showAllStudent Error 발생");

		}



		return result;

	}

}