import java.util.List;
import java.util.Map;

public class MapHashMap {
	
	public class HashMap{
	
	public static void main(String[] args) {
		
		Map<String, String> Students =
				new Students<String, String>();
		
		HashMap<String, String> Person = 
				new HashMap<String, String>();
		
		// 왼쪽은 키, 오른쪽은 벨류
		Students.put("001", "이동준");
		Students.put("002", "이동준");
		Students.put("003", "이상하"); // 001 이동준 덮어씀 
		Students.put("탈모여부", "없음");
		
		System.out.println(Students.get("001"));
		System.out.println(Students.get("002"));
		
		List<HashMap<String, String>> mystudents = 
				new ArrayList<HashMap<String, String>>();
		mystudents.add((HashMap<String, String>) Students;
		mystudnets.add(h.put("학번"))
	}
}
}