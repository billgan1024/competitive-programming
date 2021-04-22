import java.util.*;
import java.io.*;

public class GoodWriting {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static String base = "Good writing is good writing is good writing.";
	static String pre = "Good writing is good ";
	static String mid = " writing is good ";
	static String suf = " is good writing.";

	static long[] stringLengths;
	public static void main(String[] args) throws IOException {
		
		//get the length of each string
		stringLengths = new long[31];
		
		stringLengths[0] = base.length();
		//length of each recursive string
		
		for(int i = 1; i < stringLengths.length; i++)
		{
			stringLengths[i] = 2 * stringLengths[i-1] + pre.length() + mid.length() + suf.length();
		}
		
		
		
		int q = readInt();
		for(int i = 0; i < q; i++)
		{
			int n = readInt(), k = readInt()-1;
			
			if(k > stringLengths[n]) System.out.println(".");
			else findChar(n, k);
		}

	}
	
	public static void findChar(int n, int k)
	{
		//base case: n = 0 (at 0th level)
		if(n == 0) {
			System.out.println(base.charAt(k)); return;
		}
		//k is in the pre length
		if(k < pre.length()) {
			System.out.println(pre.charAt(k)); return;
		}
		//decrease by pre length
		k -= pre.length();
		if(k < stringLengths[n-1]) 
		{
			findChar(n-1, k); return;
			
		}
		k -= stringLengths[n-1];
		
		if(k < mid.length()) {
			System.out.println(mid.charAt(k)); return;
		}
		k -= mid.length();
		
		if(k < stringLengths[n-1])
		{
			findChar(n-1, k); return;
		}
		
		k -= stringLengths[n-1];
		
		System.out.println(suf.charAt(k));
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