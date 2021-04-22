import java.util.*;
import java.io.*;

public class WordProcessor {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), k = readInt(), chars = 0;
		boolean space = false;
		for(int i = 0; i < n; i++)
		{
			String s = next(); chars += s.length();
			if(chars > k) { System.out.println(); chars = s.length(); space = false; }
			
			if(space) System.out.print(" "); 
			System.out.print(s);
			if(!space) space = true;
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