import java.util.*;
import java.io.*;

public class FlightsPlanning {
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
		dis[o] = 0; pq.add(new Edge(o, dis[o]));
		while(!pq.isEmpty())
		{
			Edge cur = pq.remove(); if(dis[cur.v] < cur.w) continue;
			for(Edge neighbour: adj[cur.v])
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
		
		int n = readInt(), m = readInt(), k = readInt(), q = readInt();
		ArrayList<Edge>[] adj = new ArrayList[n+1], rev = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) { adj[i] = new ArrayList<Edge>(); rev[i] = new ArrayList<Edge>(); }
		
		for(int i = 0; i < m; i++)
		{
			int u = readInt(), v = readInt(), d = readInt();
			adj[u].add(new Edge(v, d)); rev[v].add(new Edge(u, d));
		}
		
		//it is guaranteed that at least one hub will store the shortest distance from u to v since
		//it will lie along the path for the shortest path (it is directly connected to a vertex)
		//as such, the neighbouring node (one startpoint) will have minimum distance, and since it is on 
		//the path, the distance to the endpoint will also be minimized
		int[][] dis = new int[k][n+1], rdis = new int[k][n+1];
		for(int i = 0; i < k; i++)
		{
			int x = readInt(); shortestPath(x, adj, dis[i]); shortestPath(x, rev, rdis[i]);
		}
		
		int valid = 0; long cost = 0;
		for(int i = 0; i < q; i++)
		{
			int a = readInt(), b = readInt(), min = Integer.MAX_VALUE;
			for(int j = 0; j < k; j++)
			{
				if(rdis[j][a] == Integer.MAX_VALUE || dis[j][b] == Integer.MAX_VALUE) continue;
				min = Math.min(min, rdis[j][a] + dis[j][b]);
			}
			if(min != Integer.MAX_VALUE) { valid++; cost += min; }
		}
		System.out.println(valid + "\n" + cost);
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