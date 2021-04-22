import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class SumOfPrimes {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException
	{
		
		//sieve all (odd) primes up to 10^7 (boolean prime) LOL
		boolean[] composite = new boolean[10000001];
		for(int x = 2; x < composite.length; x++)
		{
			for(int y = x * x; y < composite.length; y += x)
			{
				if(y < 0) break;
				composite[y] = true;
			}
		}
		
		for(int i = 0; i < 5; i++)
		{
			int n = readInt();
			
			if(!composite[n]) System.out.println(n + " = " + n);
			else if(n % 2 == 0)
			{
				 //a <= b
				//search from x / 2, sieve primes
				//loop from x/2 (a = x/2) and subtract one each time
				//if a isn't prime keep subtracting
				//if a is prime check if b is prime and that is your answer
				
				
				for(int a = n / 2; a >= 3; a--)
				{
					if(!composite[a] && !composite[n-a])
					{
						System.out.println(n + " = " + a + " + " + (n-a)); 
						break;
					}
				}
				
			}
			else
			{
				//a <= b, b <= c
				//a largest, b largest
				//search a from floor x/3 for nearest prime (increment down)
				//if a is prime, subtract n-a
				//check if b + c == n-a (even)
				//do same method for even, making sure b is as large as possible and b is prime, then check if c is also prime
				//but not less than a (if b is less than a, subtract a down to the next greatest prime)
				
				boolean flag = false;
				int b = 0;
				for(int a = n/3; a >= 3 && !flag; a--)
				{
					if(composite[a]) continue; //skips this code during this iteration
					int y = n - a;
					for(b = y/2; b >= a && !flag; b--)
					{
						if(!composite[b] && !composite[y-b])
						{
							System.out.println(n + " = " + a + " + " + b + " + " + (y-b));
							flag = true;
							break; //don't print out any more answers (but we still need to loop)
						}
					}
					if(flag) break;
				}
			}
		}
	}
	
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}

}