import java.util.*;
import java.io.*;

public class InClass {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int n = readInt(), sum = 0;
		for(int i = 0; i < n; i++) sum += readInt();
		if(sum > 200) System.out.println("Over maximum capacity!");
		else System.out.println(200-sum);
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