import java.util.*;
import java.io.*;

public class MockCCC18S1 {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		//min value of f(x) = ax + bc/x given that x > 0
		double b = readDouble(), c = readDouble(), a = readDouble();
		double x = Math.sqrt(b*c/a); int y = (int)x, z = y+1;
		double f1 = a*(double)y + b*c/(double)y, f2 = a*(double)z + b*c/(double)z;
		System.out.printf("%.3f\n", Math.min(f1, f2));
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

	static float readFloat() throws IOException {
		return Float.parseFloat(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}