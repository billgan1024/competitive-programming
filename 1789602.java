import java.util.*;
import java.io.*;

public class P1 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		for(int c = 0; c < n; c++)
		{
			String s = readLine();
			int brackets = 0;
			boolean valid = true;
			for(int i = 0; i < s.length(); i++) {
				if(s.charAt(i) == '-') { valid = false; break; }
				if(s.charAt(i) == '(') brackets++;
				if(s.charAt(i) == ')') {
					brackets--; if(brackets < 0) { valid = false; break; }
				}
			}
			if(!valid) {
				System.out.println("NO");
			}
			else
			{
				if(brackets != 0) System.out.println("NO");
				else System.out.println("YES");
			}
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