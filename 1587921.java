import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("rawtypes")
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		int maxNum = Integer.MIN_VALUE, minNum = Integer.MAX_VALUE;
		
		for(int i = 0; i < n; i++)
		{
			int k = readInt();
			maxNum = Math.max(maxNum, k);
			minNum = Math.min(minNum, k);
		}
		System.out.println(maxNum-minNum);
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