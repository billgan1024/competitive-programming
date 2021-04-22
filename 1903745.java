import java.util.*;
import java.io.*;

public class PhonomenalReviews {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n, maxDis, maxNode, edges; static ArrayList<Integer>[] adj; static boolean[] pho;
	
	static boolean dfs(int cur, int prev)
	{
		for(int i : adj[cur])
		{
			if(i != prev)
			{
				if(dfs(i, cur)) pho[cur] = true;
			}
		}
		return pho[cur];
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		n = readInt(); pho = new boolean[n];
		int m = readInt();
		
		adj = new ArrayList[n];
		for(int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Integer>();
		}
		
		int start = readInt();
		pho[start] = true;
		for(int i = 1; i < m; i++)
		{
			int p = readInt();
			pho[p] = true;
		}
		
		for(int i = 0; i < n-1; i++)
		{
			int a = readInt(), b = readInt();
			adj[a].add(b); adj[b].add(a);
		}
		
		dfs(start, -1);
		//after this, all nodes that are part of the necessary subgraph
		//of the pho restaurants will have hasPho[] = true
		maxDis = 0;
		dfs2(start, -1, 0); int end1 = maxNode, edge = edges;
		dfs2(end1, -1, 0); int max = maxDis;
		//shortest length path in a tree that visits every vertex = 2*edges-diameter
		System.out.println(2*edge - max);
		
	}
	
	static void dfs2(int cur, int prev, int dis)
	{
		if(dis > maxDis) { maxDis = dis; maxNode = cur; }
		for(int neighbour : adj[cur])
		{
			if(neighbour != prev && pho[neighbour])
			{
				edges++;
				dfs2(neighbour, cur, dis+1);
			}
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