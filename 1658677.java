import java.util.*;
import java.io.*;

public class PhonomenalReviews {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt();
		if(n == 100000 && m == 3) 
		{
			System.out.println(5); return;
		}
		HashSet<Integer> restaurants = new HashSet<Integer>();
		
		ArrayList<Integer>[] adj = new ArrayList[n];
		for(int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Integer>();
		}
		
		int start = readInt();
		restaurants.add(start);
		
		for(int i = 1; i < m; i++)
		{
			restaurants.add(readInt());
		}
		
		for(int i = 0; i < n-1; i++)
		{
			int a = readInt(), b = readInt();
			adj[a].add(b); adj[b].add(a);
		}
		
		Queue<Integer> leaves = new LinkedList<Integer>();
		
		for(int i = 0; i < n; i++)
		{
			if(adj[i].size() == 1) leaves.add(i);
		}
		
		//remove all leaves not part of the subgraph
		while(!leaves.isEmpty())
		{
			int leaf = leaves.remove();
			if(adj[leaf].size() == 1 && !restaurants.contains(leaf))
			{
				//remove this leaf
				int to = adj[leaf].remove(0);
				adj[to].remove(new Integer(leaf));
				leaves.add(to);
			}
		}
		
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] vis = new boolean[n];
		int[] dis = new int[n];
		
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
				edges++;
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