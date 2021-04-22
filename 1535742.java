import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class LoveGuru {
	
	public static int powerMod(int n, int exp, int mod)
	{
		if(exp == 0) return 1;
		else
		{
			int t = powerMod(n, exp/2, mod);
			t = t * t % mod;
			if(exp % 2 == 0) return t; //if even, return it
			else return t * n % mod; //otherwise return t * n (one extra exponent)
		}
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException
	{
		String a = readLine().toLowerCase();
		String b = readLine().toLowerCase();
		
		int valueA = 0, valueB = 0;
		
		for(int i = 0; i < a.length(); i++)
		{
			valueA += powerMod(a.charAt(i) - 'a' + 1, i + 1, 10);
		}
		
		for(int i = 0; i < b.length(); i++)
		{
			valueB += powerMod(b.charAt(i) - 'a' + 1, i + 1, 10);
		}
		
		valueA %= 10;
		valueB %= 10;
		
		if(valueA == 0) valueA = 10;
		if(valueB == 0) valueB = 10;
		
		
		System.out.println(valueA + valueB);
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