import java.util.*;
import java.io.*;

public class P0 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		String s = readLine(), t = readLine();
		boolean changed = false;
		if(s.equals(t)) {
			System.out.println("LARRY IS DEAD!"); return;
		}
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) != t.charAt(i)) {
				if(!changed) changed = true;
				else
				{
					System.out.println("LARRY IS DEAD!"); return;
				}
			}
		}
		System.out.println("LARRY IS SAVED!");

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