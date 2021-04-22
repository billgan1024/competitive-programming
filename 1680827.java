import java.util.*;
import java.io.*;

public class ContestOfficial4 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Edge
	{
		int to, weight;
		public Edge(int to, int weight)
		{
			this.to = to;
			this.weight = weight;
		}
	}

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		ArrayList<Edge>[] adj = new ArrayList[n];
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<Edge>();
		
		for(int i = 0; i < n-1; i++)
		{
			int u = readInt()-1, v = readInt()-1, weight = readInt();
			adj[u].add(new Edge(v, weight));
			adj[v].add(new Edge(u, weight));
		}
		
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] vis = new boolean[n];
		int[] dis = new int[n];
		
		queue.add(0); vis[0] = true;
		
		int maxDis = -1, endpoint1 = -1;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(Edge e : adj[cur])
			{
				if(vis[e.to]) continue;
				vis[e.to] = true;
				dis[e.to] = dis[cur] + e.weight;
				if(dis[e.to] > maxDis)
				{
					maxDis = dis[e.to]; endpoint1 = e.to;
				}
				queue.add(e.to);
			}
		}
		
		int endpoint2 = -1;
		maxDis = -1;
		vis = new boolean[n];
		dis = new int[n];
		
		queue.add(endpoint1);
		vis[endpoint1] = true;
		//prev[endpoint1] = -1;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(Edge e : adj[cur])
			{
				if(vis[e.to]) continue;
				vis[e.to] = true;
				dis[e.to] = dis[cur] + e.weight;
				if(dis[e.to] > maxDis)
				{
					maxDis = dis[e.to]; endpoint2 = e.to;
				}
				//prev[e.to] = cur;
				queue.add(e.to);
			}
		}
		System.out.println(maxDis);
		
		vis = new boolean[n];
		int[] endDis = new int[n];
		queue.add(endpoint2);
		vis[endpoint2] = true;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(Edge e : adj[cur])
			{
				if(vis[e.to]) continue;
				vis[e.to] = true;
				endDis[e.to] = endDis[cur] + e.weight;
				queue.add(e.to);
			}
		}
		
		int radius = Integer.MAX_VALUE;
		
		for(int i = 0; i < n; i++)
		{
			int left = dis[i], right = endDis[i];
			int max = Math.max(left, right);
			
			radius = Math.min(radius, max);
		}
		
		System.out.println(radius);
		
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