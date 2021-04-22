import java.util.*;
import java.io.*;

public class HungaryGames {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Edge implements Comparable<Edge>
	{
		int v, w;
		public Edge(int v, int w) { this.v = v; this.w = w; }
		@Override
		public int compareTo(Edge e) { return w-e.w; }
	}
	
	static void shortestPath(int o, ArrayList<Edge>[] adj, int[] dis)
	{
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
		Arrays.fill(dis, Integer.MAX_VALUE);
		dis[o] = 0;  pq.add(new Edge(o, dis[o]));
		while(!pq.isEmpty())
		{
			Edge cur = pq.remove(); if(dis[cur.v] < cur.w) continue;
			for(Edge neighbour : adj[cur.v])
			{
				if(dis[cur.v] + neighbour.w < dis[neighbour.v])
				{
					dis[neighbour.v] = dis[cur.v] + neighbour.w;
					pq.add(new Edge(neighbour.v, dis[neighbour.v]));
				}
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(); ArrayList<Edge>[] adj = new ArrayList[n+1], rev = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) { adj[i] = new ArrayList<Edge>(); rev[i] = new ArrayList<Edge>(); }
		
		for(int i = 0; i < m; i++)
		{
			int a = readInt(), b = readInt(), l = readInt();
			adj[a].add(new Edge(b, l)); rev[b].add(new Edge(a, l));
		}
		
		int[] sdis = new int[n+1], edis = new int[n+1];
		shortestPath(1, adj, sdis); shortestPath(n, rev, edis);
		int min = sdis[n]; int second = Integer.MAX_VALUE;
		for(int cur = 1; cur <= n; cur++)
		{
			for(Edge e : adj[cur])
			{
				if(sdis[cur] == Integer.MAX_VALUE || edis[e.v] == Integer.MAX_VALUE) continue;
				int dis = sdis[cur] + e.w + edis[e.v];
				if(dis > min) second = Math.min(second, dis);
			}
		}
		System.out.println(second == Integer.MAX_VALUE ? -1 : second);
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