import java.util.*;
import java.io.*;

public class ContestOfficial2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int a = readInt(), b = readInt();
		int lower = (int) Math.round((Math.pow(a, 1.0/6)));
		int upper = (int) Math.round((Math.pow(b, 1.0/6)));
		
		int count = 0;
		for(int i = lower; i <= upper; i++)
		{
			if(Math.pow(i, 6) >= a && Math.pow(i, 6) <= b) count++;
		}
		System.out.println(count);
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