import java.util.*;
import java.io.*;

public class FunInForag {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Edge
	{
		int v, l; long w; 
		public Edge(int v, long w, int l) { this.v = v; this.w = w; this.l = l; }
	}
	
	static void shortestPath(int o, ArrayList<Edge>[] adj, long[] dis, int[] level)
	{
		Arrays.fill(dis, Long.MAX_VALUE);
		Comparator<Edge> comp = new Comparator<Edge>()
		{
			@Override
			public int compare(Edge arg0, Edge arg1) { return (int)arg0.w-(int)arg1.w; }
		};
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>(comp);
		dis[o] = 0; level[o] = 0; pq.add(new Edge(o, dis[o], level[o]));
		
		while(!pq.isEmpty())
		{
			Edge temp = pq.remove(); if(dis[temp.v] < temp.w) continue;
			for(Edge neighbour : adj[temp.v])
			{
				if(dis[temp.v] + neighbour.w < dis[neighbour.v])
				{
					dis[neighbour.v] = dis[temp.v] + neighbour.w;
					level[neighbour.v] = Math.max(level[temp.v], neighbour.l);
					pq.add(new Edge(neighbour.v, dis[neighbour.v], level[neighbour.v]));
				}
			}
		}
	}
	
	static void lowestLevel(int o, ArrayList<Edge>[] adj, int[] level, long[] dis)
	{
		Arrays.fill(level, Integer.MAX_VALUE);
		Comparator<Edge> comp = new Comparator<Edge>()
		{
			@Override
			public int compare(Edge arg0, Edge arg1) { return arg0.l-arg1.l; }
		};
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>(comp);
		dis[o] = 0; level[o] = 0; pq.add(new Edge(o, dis[o], level[o]));
		
		while(!pq.isEmpty())
		{
			Edge temp = pq.remove(); if(level[temp.v] < temp.l) continue;
			for(Edge neighbour : adj[temp.v])
			{
				if(Math.max(level[temp.v], neighbour.l) < level[neighbour.v])
				{
					level[neighbour.v] = Math.max(level[temp.v], neighbour.l);
					dis[neighbour.v] = dis[temp.v] + neighbour.w;
					pq.add(new Edge(neighbour.v, dis[neighbour.v], level[neighbour.v]));
				}
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt(); 
		ArrayList<Edge>[] adj = new ArrayList[n+1]; for(int i = 1; i <= n; i++) adj[i] = new ArrayList<Edge>();
		
		for(int i = 1; i <= m; i++)
		{
			int a = readInt(), b = readInt(), c = readInt();
			adj[a].add(new Edge(b, c, i)); adj[b].add(new Edge(a, c, i));
		}
		
		int a = readInt(), b = readInt(); long c = readLong();
		
		//track important information for each node
		long[] sdis = new long[n+1]; int[] sdlevel = new int[n+1];
		int[] slevel = new int[n+1]; long[] sldis = new long[n+1];
		long[] edis = new long[n+1]; int[] edlevel = new int[n+1];
		int[] elevel = new int[n+1]; long[] eldis = new long[n+1];
		
		shortestPath(a, adj, sdis, sdlevel); lowestLevel(a, adj, slevel, sldis);
		shortestPath(b, adj, edis, edlevel); lowestLevel(b, adj, elevel, eldis);
		
		//loop thru all nodes and get the best time/level of each node and take the best
		int minLevel = Integer.MAX_VALUE;
		for(int i = 1; i <= n; i++)
		{
			long[] dis = new long[4]; int[] level = new int[4];
			dis[0] = sdis[i] + edis[i]; level[0] = Math.max(sdlevel[i], edlevel[i]);
			dis[1] = sldis[i] + eldis[i]; level[1] = Math.max(slevel[i], elevel[i]);
			dis[2] = sdis[i] + eldis[i]; level[2] = Math.max(sdlevel[i], elevel[i]);
			dis[3] = sldis[i] + edis[i]; level[3] = Math.max(slevel[i], edlevel[i]);
			for(int j = 0; j < 3; j++)
			{
				if(dis[j] >= c) continue;
				minLevel = Math.min(minLevel, level[j]);
			}
		}
		System.out.println(minLevel == Integer.MAX_VALUE ? -1 : minLevel);
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