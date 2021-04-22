import java.util.*;
import java.io.*;

public class FuninForagOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n, a, b; static long c;
	
	static class Edge
	{
		int v; long w; int l;
		public Edge(int v, long w, int l) { this.v = v; this.w = w; this.l = l; }
	}
	
	static boolean shortestPath(ArrayList<Edge>[] adj, int level)
	{
		Comparator<Edge> comp = new Comparator<Edge>()
		{
			@Override
			public int compare(Edge arg0, Edge arg1) { return Long.compare(arg0.w, arg1.w); }
		};
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>(comp);
		long[] dis = new long[n+1]; Arrays.fill(dis, Long.MAX_VALUE);
		dis[a] = 0; pq.add(new Edge(a, dis[a], 0));
		
		while(!pq.isEmpty())
		{
			Edge cur = pq.remove(); if(dis[cur.v] < cur.w) continue;
			for(Edge neighbour : adj[cur.v])
			{
				if(neighbour.l > level) continue;
				if(dis[cur.v] + neighbour.w < dis[neighbour.v])
				{
					dis[neighbour.v] = dis[cur.v] + neighbour.w;
					pq.add(new Edge(neighbour.v, dis[neighbour.v], 0));
				}
			}
		}
		
		//if u can get here in less than c time, update answer to be this level
		return dis[b] < c;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		//use dijkstra with binary search
		//low is 1 edge, high is m edges
		//for each pass, the mid is the level of transport pass (test if you can et there
		//if you cannot reach the end in less than c, go to (mid+high)/2
		//if you can reach the end in less than c, go to (low+mid)/2
		//the end result will be the lowest level of transport pass that is needed
		//to get to the end in less than c minutes
		
		//when doing dijkstra, just store a unique id for each edge (ranging from 1 to m)
		//you can also use spfa
		
		n = readInt(); int m = readInt(); ArrayList<Edge>[] adj = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<Edge>();
		for(int i = 1; i <= m; i++)
		{
			int a = readInt(), b = readInt(); long c = readLong();
			adj[a].add(new Edge(b, c, i)); adj[b].add(new Edge(a, c, i));
		}
		a = readInt(); b = readInt(); c = readLong();
		//ans starts at -1 because if you cannot get there in less than c time, 
		//you would print -1
		int low = 1, high = m, ans = -1;
		while(low <= high)
		{
			int mid = (low+high)/2;
			if(shortestPath(adj, mid))
			{
				ans = mid; high = mid-1;
			}
			else
			{
				low = mid+1;
			}
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