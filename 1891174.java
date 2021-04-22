import java.util.*;
import java.io.*;

public class GlobalWarming {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		while(true)
		{
			int n = readInt(); if(n == 0) return;
			int[] a = new int[n], d = new int[n-1];
			for(int i = 0; i < n; i++)
			{
				a[i] = readInt();
			}
			if(n == 1 || n == 2) { System.out.println(n-1); continue; }
			for(int i = 0; i < n-1; i++) d[i] = a[i+1]-a[i];
			int ans = 0;
			for(int i = 1; i <= n-1; i++)
			{
				boolean valid = true;
				int[] temp = Arrays.copyOfRange(d, 0, i);
				for(int j = i; j <= n-1; j += i)
				{
					int[] cur = Arrays.copyOfRange(d, j, Math.min(j+i, n-1));
					if(!eval(cur, temp)) { valid = false; break; }
					temp = cur.clone();
				}
				if(valid) { ans = i; break; }
			}
			System.out.println(ans);
		}
	}
	
	static boolean eval(int[] a, int[] b)
	{
		for(int i = 0; i < Math.min(a.length, b.length); i++)
		{
			if(a[i] != b[i]) return false;
		}
		return true;
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