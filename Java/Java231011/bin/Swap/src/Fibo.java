
static Long Fibo(int num)
	{
		if(num<=0)
			return 0L;
		if(num==1)
			return 1L;
		if(memo.containsKey(num))
			return memo.get(num);
		else {
			Long answer = Fibo(num-2)+Fibo(num-1);
			memo.put(num, answer);
			return memo.get(num);
		}
	}
public class Fibo {
public static void main(String[] args) {
	System.out.println(Fibo(5));
	System.out.println(Fibo(6));
	System.out.println(Fibo(7));
	System.out.println(Fibo(8));
	System.out.println(Fibo(9));
	System.out.println(Fibo(10));
	
	
	
	
	}
}

