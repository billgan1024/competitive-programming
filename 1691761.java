import java.util.*;

import java.io.*;

public class ContestOfficial3 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Edge>[] adj;
	static int n, len, far;
	
	static int[] prev, cost;
	
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
		
		n = readInt(); adj = new ArrayList[n]; prev = new int[n]; cost = new int[n];
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<Edge>();
		for(int i = 0; i < n-1; i++)
		{
			int u = readInt()-1, v = readInt()-1, weight = readInt();
			adj[u].add(new Edge(v, weight));
			adj[v].add(new Edge(u, weight));
		}
		len = -1; dfs(1, 0, 0); int p1 = far;
		len = -1; dfs(p1, 0, 0); int p2 = far; int diameter = len; int radius = len;
		//get diameter path
		for(int i = p2, left = 0; i != p1; i = prev[i])
		{
			int right = diameter-left;
			radius = Math.min(radius,  Math.max(left,  right));
			left += cost[i];
		}
		System.out.println(diameter + "\n" + radius);
	}
	
	static void dfs(int cur, int from, int dis)
	{
		//update max dis (only one path so only check if this is not the returning path)
		if(dis > len) { len = dis; far = cur; }
		for(Edge e : adj[cur])
		{
			int to = e.to, weight = e.weight;
			if(to != from)
			{
				prev[to] = cur;
				//store cost to travel from previous node to this node
				cost[to] = weight;
				dfs(to, cur, dis+weight);
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
}