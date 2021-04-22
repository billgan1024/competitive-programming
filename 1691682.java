import java.util.*;
import java.io.*;

public class BirthdayGame {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int[] adj;
	static int[] vis, dis;
	static int minCycle = Integer.MAX_VALUE;
	
	static void dfs(int cur, int curDis)
	{
		//set this node as active and write its current distance
		vis[cur] = 1; dis[cur] = curDis; int to = adj[cur];
		
		//if a cycle exists, update min cycle
		if(vis[to] == 1) minCycle = Math.min(minCycle,  dis[cur] - dis[to] + 1);
		else if(vis[to] == 0) dfs(to, dis[cur] + 1); //start a new dfs, while setting the next node's distance
		vis[cur] = 2;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		adj = new int[n]; vis = new int[n]; dis = new int[n];
		
		for(int i = 0; i < n; i++)
		{
			adj[i] = readInt()-1;
		}
		
		for(int i = 0; i < n; i++)
		{
			if(vis[i] == 0) dfs(i, 0);
		}
		System.out.println(minCycle);
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

	public static int lower_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] >= x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}

	public static int upper_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] > x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}
}