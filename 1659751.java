import java.util.*;
import java.io.*;

public class ThirdPlace {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Edge
	{
		int to, weight;
		public Edge(int to, int weight)
		{
			this.to = to; this.weight = weight;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		ArrayList<Edge>[] adj = new ArrayList[n];
		
		for(int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Edge>();
		}
		
		for(int i = 0; i < n-1; i++)
		{
			int a = readInt()-1, b = readInt()-1, c = readInt();
			adj[a].add(new Edge(b, c));
			adj[b].add(new Edge(a, c));
		}
		
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] vis = new boolean[n];
		long[] dis = new long[n];
		long maxDis = -1;
		int maxNode = -1;
		
		queue.add(0);
		vis[0] = true;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(Edge i : adj[cur])
			{
				if(vis[i.to]) continue;
				vis[i.to] = true;
				dis[i.to] = dis[cur] + i.weight;
				if(dis[i.to] > maxDis)
				{
					maxNode = i.to;
					maxDis = dis[i.to];
				}
				queue.add(i.to);
			}
		}
		
		int endpoint1 = maxNode;
		
		vis = new boolean[n];
		dis = new long[n];
		maxDis = -1;
		maxNode = -1;
		queue.add(endpoint1);
		vis[endpoint1] = true;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(Edge i : adj[cur])
			{
				if(vis[i.to]) continue;
				vis[i.to] = true;
				dis[i.to] = dis[cur] + i.weight;
				if(dis[i.to] > maxDis)
				{
					maxNode = i.to;
					maxDis = dis[i.to];
				}
				queue.add(i.to);
			}
		}
		
		int endpoint2 = maxNode;
		
		vis = new boolean[n];
		long[] endpointDis = new long[n];
		queue.add(endpoint2);
		vis[endpoint2] = true;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(Edge i : adj[cur])
			{
				if(vis[i.to]) continue;
				vis[i.to] = true;
				endpointDis[i.to] = endpointDis[cur] + i.weight;
				queue.add(i.to);
			}
		}
		 long ans = 0;
		 for(int i = 0; i < n; i++)
		 {
			 if(i != endpoint2) ans = Math.max(ans, dis[i]);
			 if(i != endpoint1) ans = Math.max(ans, endpointDis[i]);
		 }
		 System.out.println(ans);
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