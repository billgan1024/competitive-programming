import java.util.*;
import java.io.*;

public class AGraphProblem {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		long[] nums = new long[n];
		long sum = 0;
		for(int i = 0; i < n; i++)
		{
			nums[i] = readLong();
			sum += nums[i];
		}
		
		//add together weights of the edges of each vertex, it must be even since edges apply weights to 2 vertices
		//also, no number can be bigger than all of the other numbers combined since that would mean more weight than the total weight of edges
		if(sum % 2 != 0 || n == 1) System.out.println("NO");
		else
		{
			
			for(int i = 0; i < n; i++)
			{
				boolean ok = false;
				long tempSum = 0;
				for(int j = 0; j < n; j++)
				{
					if(j != i) tempSum += nums[j];
					if(tempSum >= nums[i]) {
						ok = true;
						break;
					}
				}
				if(!ok)
				{
					System.out.println("NO"); 
					return;
				}
			}
			System.out.println("YES");
		
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