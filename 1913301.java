import java.util.*;
import java.io.*;

public class Waterpark {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		//let dp[i] represent the number of paths from 1 to i (1 <= i <= n)
		//then dp[i] = sum of all dp[j] who have a slide connecting to i
		//since the # of different paths to a node is the sum of the # of different
		//paths to its neighbours
		//time complexity: O(n^2) space complexity: O(n^2)
		int n = readInt(); ArrayList<Integer>[] adj = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<Integer>();
		int x = readInt(), y = readInt();
		while(x != 0 && y != 0)
		{
			//add reverse edges 
			adj[y].add(x);
			x = readInt(); y = readInt();
		}
		
		int[] dp = new int[n+1];
		dp[1] = 1;
		for(int i = 2; i <= n; i++)
		{
			for(int from : adj[i]) dp[i] += dp[from];
		}
		System.out.println(dp[n]);
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