import java.util.*;
import java.io.*;

public class ConvexHull {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int k;
	
	static class Edge implements Comparable<Edge>
	{
		int v, w, d;
		public Edge(int v, int w, int d) { this.v = v; this.w = w; this.d = d; }
		@Override
		public int compareTo(Edge e) { return w-e.w; }
	}
	
	static void shortestPath(int o, ArrayList<Edge>[] adj, int[][] dis)
	{
		//dis[i][j] represents the shortest path from a to i while taking exactly j damage
		for(int i = 1; i < dis.length; i++) Arrays.fill(dis[i], Integer.MAX_VALUE);
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
		dis[o][0] = 0; pq.add(new Edge(o, dis[o][0], 0));
		
		while(!pq.isEmpty())
		{
			Edge cur = pq.remove(); if(dis[cur.v][cur.d] < cur.w) continue;
			for(Edge neighbour : adj[cur.v])
			{
				if(cur.d + neighbour.d >= k) continue;
				if(dis[cur.v][cur.d] + neighbour.w < dis[neighbour.v][cur.d + neighbour.d])
				{
					dis[neighbour.v][cur.d + neighbour.d] = dis[cur.v][cur.d] + neighbour.w;
					pq.add(new Edge(neighbour.v, dis[neighbour.v][cur.d + neighbour.d], cur.d + neighbour.d));
				}
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		k = readInt(); int n = readInt(), m = readInt();
		ArrayList<Edge>[] adj = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<Edge>();
		
		for(int i = 0; i < m; i++)
		{
			int a = readInt(), b = readInt(), t = readInt(), h = readInt();
			adj[a].add(new Edge(b, t, h)); adj[b].add(new Edge(a, t, h));
		}
		int a = readInt(), b = readInt(), ans = Integer.MAX_VALUE;
		int[][] dis = new int[n+1][k]; shortestPath(a, adj, dis);
		for(int i : dis[b]) ans = Math.min(ans, i);
		System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
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