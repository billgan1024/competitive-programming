import java.util.*;
import java.io.*;

public class MostlyTalking {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Edge 
	{
		int v, w;
		public Edge(int v, int w)
		{
			this.v = v; this.w = w;
		}
	}
	
	static void shortestPath(int root, ArrayList<Edge>[] adj, int[] dis)
	{
		Arrays.fill(dis, Integer.MAX_VALUE);
		Comparator<Edge> comp = new Comparator<Edge>() {
			@Override
			public int compare(Edge arg0, Edge arg1) {
				return arg0.w-arg1.w;
			}
		};
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>(comp);
		dis[root] = 0; pq.add(new Edge(root, dis[root]));
		while(!pq.isEmpty())
		{
			Edge temp = pq.remove(), cur = new Edge(temp.v, dis[temp.v]);
			if(comp.compare(temp, cur) > 0) continue;
			for(Edge neighbour : adj[temp.v])
			{
				Edge orig = new Edge(neighbour.v, dis[neighbour.v]);
				Edge alt = new Edge(neighbour.v, dis[temp.v] + neighbour.w);
				if(comp.compare(orig, alt) > 0)
				{
					dis[neighbour.v] = dis[temp.v] + neighbour.w;
					pq.add(alt);
				}
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(); int[] startDis = new int[n+1], endDis = new int[n+1];
		ArrayList<Edge>[] adj = new ArrayList[n+1], rev = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) { adj[i] = new ArrayList<Edge>(); rev[i] = new ArrayList<Edge>(); }
		
		for(int i = 0; i < m; i++)
		{
			int a = readInt(), b = readInt(), k = readInt();
			adj[a].add(new Edge(b, k)); rev[b].add(new Edge(a, k));
		}
		
		//compute the shortest distance to each node from the start and the end using NO special edges
		shortestPath(1, adj, startDis); shortestPath(n, rev, endDis);
		
		//start w/ the shortest path that can be achieved by using no special edges (infinity if unreachable)
		int d = readInt(), ans = startDis[n];
		for(int i = 0; i < d; i++)
		{
			int a = readInt(), b = readInt(), g = readInt();
			if(startDis[a] == Integer.MAX_VALUE || endDis[b] == Integer.MAX_VALUE) continue;
			ans = Math.min(ans, startDis[a] + g + endDis[b]);
		}
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