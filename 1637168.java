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
		for(int i = 0; ; i++)
		{
			String s = readLine();
			if(s.equals("TTYL"))
			{
				System.out.println("talk to you later");
				break;
			}
			
			s = s.replace("CU", "see you");
			s = s.replace(":-)", "I'm happy");
			s = s.replace(":-(", "I'm unhappy");
			s = s.replace(";-)", "wink");
			s = s.replace(":-P", "stick out my tongue");
			s = s.replace("(~.~)", "sleepy");
			s = s.replace("TA", "totally awesome");
			s = s.replace("CCC", "Canadian Computing Competition");
			s = s.replace("CUZ", "because");
			s = s.replace("TY", "thank-you");
			s = s.replace("YW", "you're welcome");
			System.out.println(s);
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