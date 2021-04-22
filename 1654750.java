import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		String g = readLine();
		int[] pre = new int[g.length()];
		pre[0] = g.charAt(0) == 'G' ? 1 : 0;
		for(int i = 1; i < g.length(); i++)
		{
			pre[i] = pre[i-1] + (g.charAt(i) == 'G' ? 1 : 0);
		}
		
		int q = readInt();
		for(int i = 0; i < q; i++)
		{
			int a = readInt(), b = readInt();
			if(a == 0) System.out.println(pre[b]);
			else System.out.println(pre[b]-pre[a-1]);
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