import java.util.*;
import java.io.*;

public class MockCCC {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		for(int i = 0; i < n; i++)
		{
			int x = readInt(), sum = 0;
			for(int y = 1; y <= Math.sqrt(x); y++)
			{
				if(x%y == 0)
				{
					sum += y;
					if((double)y != Math.sqrt(x) && y != 1) sum += x/y;
				}
			}
			String s = "";
			if(sum < x) s = "deficient";
			else if(sum == x) s = "perfect";
			else s = "abundant";
			if(s.equals("abundant")) System.out.printf("%d is an %s number.\n", x, s);
			else System.out.printf("%d is a %s number.\n", x, s);
		}
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