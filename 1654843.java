import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		long a = readLong(), b = readLong();
		int k = readInt();
		long ans = gcd(a, b);
		ArrayList<Long> f = factors(ans);
		
		Collections.sort(f);
		if(f.size()-k < 0) System.out.println(-1);
		else System.out.println(f.get(f.size()-k));
	}
	
	public static ArrayList<Long> factors(long n)
	{
		ArrayList<Long> fact = new ArrayList<Long>();
		for(long x = 1; x <= Math.sqrt(n); x++)
		{
			if(n % x == 0)
			{
				fact.add(x);
				if((double) x != Math.sqrt(n))
				{
					fact.add(n / x);
				}
			}
		}
		return fact;
	}
	
	public static long gcd(long m, long n) //48, 30
	{
		if(n == 0) return m;
		else return gcd(n, m % n);
	}

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}