import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		String s = readLine();
		for(int i = 0; i < s.length(); i++)
		{
			char c = s.charAt(i);
			if(c != 'I' && c != 'O' && c != 'S' && c != 'H' && c != 'Z' && c != 'N' && c != 'X')
			{
				System.out.println("NO"); return;
			}
		}
		System.out.println("YES");
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