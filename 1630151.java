import java.util.*;
import java.io.*;

public class Dodgeball {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		long result = 0;
		int n = readInt();
		int consecutive = 0;
		char first = '*';
		
		for(int i = 0; i < n; i++)
		{
			String name = next().toLowerCase();
			if(name.charAt(0) == first) consecutive++;
			else { consecutive = 1; first = name.charAt(0); }
			result += consecutive;
		}
		
		System.out.println(result % 1000000007);

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