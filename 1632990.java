import java.util.*;
import java.io.*;

public class Dodgeball {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		int n = readInt();
		int[] values = new int[n];
		for(int i = 0; i < n; i++)
		{
			values[i] = readInt();
		}
		int m = readInt();
		int sum = 0;
		for(int i = 0; i < m; i++)
		{
			int a = readInt()-1, d = readInt();
			int lowerValue = 0, lowerIndex = 0;
			if(values[a] <= values[a+1])
			{
				lowerValue = values[a];
				lowerIndex = a;
			}
			else
			{
				lowerValue = values[a+1];
				lowerIndex = a+1;
			}
			if(lowerValue < d) values[lowerIndex] = 0;
			else sum -= d;
		}
		
		for(int i = 0; i < n; i++)
		{
			sum += values[i];
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