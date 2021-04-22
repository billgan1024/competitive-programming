import java.util.*;
import java.io.*;

public class ContestOfficial2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static HashMap<Integer, Integer> factorFreq = new HashMap<Integer, Integer>();
	
	public static void primeFactorization(int n) //prints out unique prime factorization
	{
		int limit = (int) Math.sqrt(n); //floored sqrt of n
		for(int x = 2; x <= limit; x++)
		{
			if(n == 1) break;
			while(n % x == 0)
			{
				//add this prime factor
				factorFreq.put(x, factorFreq.getOrDefault(x, 0) + 1);
				n /= x;
			}
		}
		//only one prime factor greater than sqrt n
		if(n != 1) factorFreq.put(n, factorFreq.getOrDefault(n, 0) + 1);
	}
	
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), l = readInt();
		String[] s = new String[n];
		for(int i = 0; i < n; i++) s[i] = readLine();
		Arrays.sort(s, Collections.reverseOrder());
		for(String t : s) System.out.print(t);
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