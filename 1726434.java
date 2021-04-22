import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		int n = readInt();
		
		for(int i = 0; i < n; i++)
		{
			int[] a = new int[10];
			boolean arith = true, geo = true;
			int zeroes = 0;
			for(int j = 0; j < 10; j++) {
				a[j] = readInt();
				if(a[j] == 0) zeroes++;
			}
			for(int j = 1; j < 9; j++)
			{
				if(a[j] - a[j-1] != a[j+1] - a[j])
				{
					arith = false; break;
				}
			}
			if(zeroes == 0)
			{
				for(int j = 1; j < 9; j++)
				{
					if((double)a[j]/(double)a[j-1] % 1.0 != 0.0 || a[j] / a[j-1] != a[j+1] / a[j])
					{
						geo = false; break;
					}
				}
			}
			else if(a[0] != 0 && zeroes == 9) geo = true;
			else if(zeroes != 10) geo = false;
			if(arith && geo) System.out.println("both");
			else if(arith) System.out.println("arithmetic");
			else if(geo) System.out.println("geometric");
			else System.out.println("neither");
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