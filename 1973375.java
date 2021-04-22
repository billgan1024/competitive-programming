import java.util.*;
import java.io.*;

public class Test {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;	
	
	public static void main(String[] args) throws IOException
	{
		int cnt = 0;
		for(int i = 0; i < 6; i++)
		{
			char c = next().charAt(0); if(c == 'W') cnt++;
		}
		if(cnt == 5 || cnt == 6) System.out.println(1);
		else if(cnt == 3 || cnt == 4) System.out.println(2);
		else if(cnt == 1 || cnt == 2) System.out.println(3);
		else System.out.println(-1);
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