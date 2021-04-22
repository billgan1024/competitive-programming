import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		String[] s = readLine().split(" ");
		if(s[s.length-1].equals("True"))
		{
			if(s.length % 2 == 1) System.out.println("True");
			else System.out.println("False");
		}
		else
		{
			if(s.length % 2 == 1) System.out.println("False");
			else System.out.println("True");
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

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}