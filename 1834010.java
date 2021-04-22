import java.util.*;
import java.io.*;

public class MostlyTalking {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n, startDis[], endDis[]; static ArrayList<Edge>[] adj, rev;
	
	static class Edge
	{
		int to, weight;
		public Edge(int to, int weight)
		{
			this.to = to; this.weight = weight;
		}
	}
	
	static int[] shortestPath(int root)
	{
		int[] dis = new int[n+1]; Arrays.fill(dis, Integer.MAX_VALUE);
		Comparator<Edge> comp = new Comparator<Edge>() {
			@Override
			public int compare(Edge arg0, Edge arg1) {
				return arg0.weight-arg1.weight;
			}
		};
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>(comp);
		dis[root] = 0; pq.add(new Edge(root, dis[root]));
		while(!pq.isEmpty())
		{
			Edge temp = pq.remove(), cur = new Edge(temp.to, dis[temp.to]);
			if(comp.compare(temp, cur) > 0) continue;
			for(Edge e : adj[temp.to])
			{
				Edge orig = new Edge(e.to, dis[e.to]), alt = new Edge(e.to, dis[temp.to] + e.weight);
				if(comp.compare(orig, alt) > 0)
				{
					dis[e.to] = dis[temp.to] + e.weight; pq.add(alt);  
				}
			}
		}
		
		return dis;
	}
	
	static int[] shortestPath2(int root)
	{
		int[] dis = new int[n+1]; Arrays.fill(dis, Integer.MAX_VALUE);
		Comparator<Edge> comp = new Comparator<Edge>() {
			@Override
			public int compare(Edge arg0, Edge arg1) {
				return arg0.weight-arg1.weight;
			}
		};
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>(comp);
		dis[root] = 0; pq.add(new Edge(root, dis[root]));
		while(!pq.isEmpty())
		{
			Edge temp = pq.remove(), cur = new Edge(temp.to, dis[temp.to]);
			if(comp.compare(temp, cur) > 0) continue;
			for(Edge e : rev[temp.to])
			{
				Edge orig = new Edge(e.to, dis[e.to]), alt = new Edge(e.to, dis[temp.to] + e.weight);
				if(comp.compare(orig, alt) > 0)
				{
					dis[e.to] = dis[temp.to] + e.weight; pq.add(alt);  
				}
			}
		}
		
		return dis;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		n = readInt(); int m = readInt(); adj = new ArrayList[n+1]; rev = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) { adj[i] = new ArrayList<Edge>(); rev[i] = new ArrayList<Edge>(); }
		
		for(int i = 0; i < m; i++)
		{
			int a = readInt(), b = readInt(), k = readInt(); boolean exists = false;
			for(Edge e : adj[a])
			{
				if(e.to == b) { exists = true; e.weight = Math.min(e.weight, k); }
				for(Edge f : rev[b])
				{
					if(f.to == a) f.weight = Math.min(f.weight, k); 
				}
			}
			if(!exists) { adj[a].add(new Edge(b, k)); rev[b].add(new Edge(a, k)); }
		}
		
		//compute the shortest distance to each node from the start and the end using NO special edges
		startDis = shortestPath(1); endDis = shortestPath2(n);
		
		//start w/ the shortest path that can be achieved by using no special edges (infinity if unreachable)
		int d = readInt(); long ans = startDis[n];
		for(int i = 0; i < d; i++)
		{
			int a = readInt(), b = readInt(), g = readInt();
			ans = Math.min(ans, (long)startDis[a] + (long)g + (long)endDis[b]);
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