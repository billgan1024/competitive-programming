import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		int max = -1, maxPlayer = -1;
		for(int i = 0; i < 5; i++)
		{
			int s = 0;
			for(int j = 0; j < 4; j++)
			{
				s += readInt();
			}
			if(s > max)
			{
				max = s; maxPlayer = i;
			}
		}
		System.out.println((maxPlayer + 1) + " " + max);
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