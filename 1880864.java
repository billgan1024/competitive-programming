import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static boolean valid = true;
	
	static void eval(String s, String t)
	{
		if(t.indexOf(s) != -1 && t.indexOf(s) == 0) valid = false;
		if(t.lastIndexOf(s) != -1 && t.lastIndexOf(s) == t.length()-s.length()) valid = false;
	}
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		for(int i = 0; i < n; i++)
		{
			valid = true;
			String a = readLine(), b = readLine(), c = readLine();
			eval(a, b); eval(a, c); eval(b, c);
			eval(b, a); eval(c, a); eval(c, b);
			System.out.println(valid ? "Yes" : "No");
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