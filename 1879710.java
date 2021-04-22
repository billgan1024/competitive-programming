import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException {
		
		int a = 0, b = 0, ma = Integer.MAX_VALUE, mb = Integer.MAX_VALUE;
		for(int i = 0; i < 5; i++) { int x = readInt(); a += x; ma = Math.min(ma, x); }
		for(int i = 0; i < 5; i++) { int x = readInt(); b += x; mb = Math.min(mb, x); }
		
		System.out.println(Math.max(a-ma, b-mb));
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