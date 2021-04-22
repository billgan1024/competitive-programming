import java.util.*;
import java.io.*;

public class WhereAmI {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(); String s = readLine();
		
		for(int i = 1; i <= n; i++)
		{
			boolean valid = true;
			HashSet<String> set = new HashSet<String>();
			for(int j = 0; j + i <= n; j++)
			{
				String temp = s.substring(j, j+i);
				if(set.contains(temp)) { valid = false; break; }
				else set.add(temp);
			}
			if(valid) { System.out.println(i); return; }
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