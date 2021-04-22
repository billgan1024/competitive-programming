import java.util.*;
import java.io.*;

public class S1 {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int compare(char a, char b)
	{
		return (int)a-(int)b;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(); char[] s = readLine().toCharArray();
		Deque<Character> d = new ArrayDeque<Character>();
		for(char c : s)
		{
			Character f = d.peekFirst();
			if(f == null || compare(c, f) <= 0) d.addFirst(c);
			else d.addLast(c);
		}
		for(char c : d) System.out.print(c);
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