import java.util.*;
import java.io.*;

public class InClass {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static ArrayList<Integer> primeFactorization(int n) //prints out unique prime factorization
	{
		ArrayList<Integer> result = new ArrayList<Integer>();
		int limit = (int) Math.sqrt(n); //floored sqrt of n
		for(int x = 2; x <= limit; x++)
		{
			if(n == 1) break;
			while(n % x == 0)
			{
				result.add(x);
				n /= x;
			}
		}
		//only one prime factor greater than sqrt n
		if(n != 1) result.add(n);
		return result;
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		for(int i = 0; i < 5; i++)
		{
			int n = readInt();
			if(primeFactorization(n).size() == 2) System.out.println("semiprime");
			else System.out.println("not");
		}
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