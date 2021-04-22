import java.util.*;

import java.io.*;

public class ContestOfficial3 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Edge>[] adj;
	static int n;
	static int root1 = -1, root2 = -1, maxDis = -1;
	static int[] dis1, prev;
	static boolean[] vis;
	
	static void bfs1(int start, int max)
	{
		maxDis = -1;
		Queue<Integer> queue = new LinkedList<Integer>();
		dis1 = new int[n];
		vis = new boolean[n];
		if(max == 2) prev = new int[n];
		
		queue.add(start); vis[start] = true;
		if(max == 2) prev[start] = -1;
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(Edge e : adj[cur])
			{
				if(vis[e.to]) continue;
				vis[e.to] = true;
				dis1[e.to] = dis1[cur] + e.weight;
				if(dis1[e.to] > maxDis)
				{
					maxDis = dis1[e.to];
					if(max == 1) root1 = e.to;
					else root2 = e.to;
				}
				if(max == 2) prev[e.to] = cur; 
				queue.add(e.to);
			}
		}
	}
	
	static class Edge
	{
		int to, weight;
		public Edge(int to, int weight)
		{
			this.to = to;
			this.weight = weight;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		n = readInt(); adj = new ArrayList[n];
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<Edge>();
		
		for(int i = 0; i < n-1; i++)
		{
			int u = readInt()-1, v = readInt()-1, weight = readInt();
			adj[u].add(new Edge(v, weight));
			adj[v].add(new Edge(u, weight));
		}
		
		bfs1(0, 1);
		bfs1(root1, 2);
		System.out.println(maxDis);
		
		int radius = Integer.MAX_VALUE;
		
		int r1Dis = dis1[root2], r2Dis = 0;
		
		for(int i = root2; i != -1; i = prev[i])
		{
			int max = Math.max(r1Dis, r2Dis);
			radius = Math.min(radius, max);
			
			for(Edge e : adj[i])
			{
				if(e.to == prev[i])
				{
					r1Dis -= e.weight;
					r2Dis += e.weight;
				}
			}
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