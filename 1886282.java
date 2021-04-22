import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt(), count = 0; boolean battle = false;
		int[] a = new int[n], b = new int[n];
		for(int i = 0; i < n; i++) a[i] = readInt(); 
		for(int i = 0; i < n; i++) b[i] = readInt(); 
		for(int i = 0; i < n; i++)
		{
			if(a[i] == b[i])
			{
				if(!battle) { battle = true; count++; }
			}
			else battle = false;
		}
		System.out.println(count);
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