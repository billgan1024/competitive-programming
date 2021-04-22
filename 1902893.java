import java.util.*;
import java.io.*;

public class MooBuzz {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static long count(long a, long b)
	{
		//returns # of numbers which are a multiple of 3 or 5 in the range [a, b]
		long total = b/3 + b/5 - b/15, sub = (a-1)/3 + (a-1)/5 - (a-1)/15;
		return total-sub;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		long n = readInt();
		long l = 1, r = n, c = count(l, r);
		while(c > 0)
		{
			l = n+1; n += c; r = n;
			c = count(l, r);
		}
		System.out.println(n);
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