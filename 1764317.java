import java.util.*;
import java.io.*;

public class InClass {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int t = readInt();
		for(int i = 0; i < t; i++)
		{
			String s = Integer.toBinaryString(readInt());
			for(int j = 0; j < s.length(); j++)
			{
				System.out.print(s.charAt(j) == '1' ? "dank " : "meme ");
			}
			System.out.println();
		}
	}
	
	static boolean up(char c) {
		return Character.isUpperCase(c);
	}
	static boolean lo(char c) {
		return Character.isLowerCase(c);
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