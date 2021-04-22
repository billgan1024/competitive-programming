import java.util.*;
import java.io.*;

public class PhonomenalReviews {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n;
	static ArrayList<Integer>[] adj;
	static boolean[] hasPho;
	
	public static boolean dfs(int cur, int prev)
	{
		//lazy dfs
		//instead of keeping a visited array, since this is a tree,
		//we only need to restrict the current node from visiting its
		//previous node.
		for(int i : adj[cur])
		{
			if(i != prev)
			{
				if(dfs(i, cur)) hasPho[cur] = true;
			}
		}
		//each pho restaurant enables part of the subgraph
		//when the dfs reaches it since after returning true,
		//the whole branch of nodes becomes hasPho[] = true
		//otherwise, the whole branch becomes hasPho[] = false
		//and it will not be considered in the pathfinding
		return hasPho[cur];
	}


	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		n = readInt();
		hasPho = new boolean[n];
		int m = readInt();
		
		adj = new ArrayList[n];
		for(int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Integer>();
		}
		
		int start = readInt();
		hasPho[start] = true;
		for(int i = 1; i < m; i++)
		{
			int pho = readInt();
			hasPho[pho] = true;
		}
		
		for(int i = 0; i < n-1; i++)
		{
			int a = readInt(), b = readInt();
			adj[a].add(b); adj[b].add(a);
		}
		
		dfs(start, -1);
		//after this, all nodes that are part of the necessary subgraph
		//of the pho restaurants will have hasPho[] = true
		
		
		Queue<Integer> queue = new LinkedList<Integer>();
		int[] dis = new int[n];
		boolean[] vis = new boolean[n];
		
		int edges = 0;
		
		queue.add(start);
		vis[start] = true;
		
		int maxDis = -1, maxNode = -1;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(int i : adj[cur])
			{
				if(vis[i]) continue;
				if(!hasPho[i]) continue;
				edges++; //calculate # of edges
				vis[i] = true;
				dis[i] = dis[cur] + 1;
				if(maxDis < dis[i])
				{
					maxDis = dis[i];
					maxNode = i;
				}
				queue.add(i);
			}
		}
		
		queue.add(maxNode);
		dis = new int[n];
		vis = new boolean[n];
		vis[maxNode] = true;
		maxDis = -1;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(int i : adj[cur])
			{
				if(vis[i]) continue;
				if(!hasPho[i]) continue;
				vis[i] = true;
				dis[i] = dis[cur] + 1;
				if(maxDis < dis[i])
				{
					maxDis = dis[i];
				}
				queue.add(i);
			}
		}
		
		System.out.println(2*edges - maxDis);
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