import java.util.*;
import java.io.*;

public class Median {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), a[] = new int[n+1];
		for(int i = 1; i <= n; i++)
		{
			int[] b = new int[n+1];
			for(int j = 1; j <= n; j++) b[j] = readInt();
			Arrays.sort(b); a[i] = b[n/2+1];
		}
		Arrays.sort(a); System.out.println(a[n/2+1]);
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