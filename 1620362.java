import java.util.*;
import java.io.*;

public class MaximumDistance {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int k = readInt();
		
		for(int c = 0; c < k; c++)
		{
			int n = readInt();
			int[] x = new int[n];
			int[] y = new int[n];
			
			for(int i = n-1; i >= 0; i--)
			{
				x[i] = readInt();
			}
			
			for(int i = n-1; i >= 0; i--)
			{
				y[i] = readInt();
			}
			
			int maxDistance = 0;
			for(int i = 0; i < n; i++)
			{
				int target = x[i];
				int index = Arrays.binarySearch(y, target);
				while(index > 0 && y[index-1] == y[index]) index--;
				if(index >= 0)
				{
					int distance = i - index;
					maxDistance = Math.max(maxDistance, distance);
				}
			}
			
			System.out.println("The maximum distance is " + maxDistance);
			
			
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