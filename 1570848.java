import java.util.*;
import java.io.*;

public class ContestOfficial5 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt(), k = readInt();
		
		int[] discountNumber = new int[n];
		long sum = 0;
		
		for(int i = 0; i < n; i++)
		{
			int j = readInt();
			sum += j;
			discountNumber[i] = j - readInt();
		}
		
		Arrays.sort(discountNumber);
		
		for(int i = 0; i < k; i++)
		{
			sum -= discountNumber[discountNumber.length-1-i];
		}
		System.out.println(sum);

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