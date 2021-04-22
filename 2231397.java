import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Stack;
import java.util.StringTokenizer;

public class Test
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static boolean isPrime(int n)
	{
		if(n == 2 || n == 5) return true;
		int last = n % 10;
		if(last == 2 || last == 5 || last == 0 || n == 1) return false;
		int limit = (int) Math.sqrt(n); //limit is floor of sqrt(n)
		
		for(int x = 2; x <= limit; x++) //loop from 2 
		{
			if(n % x == 0)
			{
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) throws IOException
	{
		int count = readInt();
		for(int u = 0; u < count; u++)
		{
			int n = readInt();
			
			if(isPrime(n)) System.out.println(n + " " + n);
			else
			{
				int i = 1;
				while(i < n)
				{
					if(isPrime(n-i) && isPrime(n+i)) break;
					i++;
				}
				
				System.out.println((n-i) + " " + (n+i));
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