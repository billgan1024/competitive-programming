import java.util.*;
import java.io.*;

public class SumGame {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Integer> currentPath = new ArrayList<Integer>();
	static boolean cycle = false;
	static ArrayList<Integer>[] adj;
	static boolean[] vis;
	
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
	
	

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		for(int i = 0; i < 5; i++)
		{
			int n = readInt();
			int sum = 0;
			for(int j = 2; j <= n; j++)
			{
				if(isPrime(j)) sum += j;
			}
			System.out.println(sum);
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