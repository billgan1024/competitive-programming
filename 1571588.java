import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("rawtypes")
	public static void main(String[] args) throws IOException
	{
		int n = readInt(), m = readInt();
		
		int bestIndex = -1;
		int bestCount = Integer.MAX_VALUE;
		
		for(int i = 0; i < n; i++)
		{
			int count = 0;
			//read data from this array
			for(int j = 0; j < m; j++)
			{
				int k = readInt();
				if(k == 1 || k == 10) count++;
			}
			
			if(count < bestCount)
			{
				bestIndex = i;
				bestCount = count;
			}
		}
		System.out.println(bestIndex+1);
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