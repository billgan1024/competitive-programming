import java.util.*;

import java.io.*;

public class ChainRule {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Edge>[] adj;
	
	static class Edge
	{
		int to, weight;
		public Edge(int to, int weight) {
			this.to = to; this.weight = weight;
		}
	}
	
	static Comparator<Edge> comp = new Comparator<Edge>() {
		@Override
		public int compare(Edge arg0, Edge arg1) {
			return arg0.weight-arg1.weight;
		}
	};
	
	static int[] shortestPath(int start, int n)
	{
		int[] dis = new int[n]; Arrays.fill(dis, Integer.MAX_VALUE);
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>(comp);
		dis[start] = 0; pq.add(new Edge(start, dis[start]));
		
		while(!pq.isEmpty())
		{
			Edge cur = pq.remove(); 
			if(cur.weight > dis[cur.to]) continue;
			for(Edge e : adj[cur.to])
			{
				if(dis[e.to] > dis[cur.to] + e.weight) {
					dis[e.to]= dis[cur.to] + e.weight; 
					pq.add(new Edge(e.to, dis[e.to]));
				}
			}
		}
		return dis;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(); adj = new ArrayList[n]; 
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<Edge>();
		
		for(int i = 0; i < m; i++)
		{
			int a = readInt(), b = readInt(), t = readInt();
			adj[a].add(new Edge(b, t)); adj[b].add(new Edge(a, t));
		}

		int[] startDis = shortestPath(0, n), endDis = shortestPath(n-1, n);
		
		int maxDis = Integer.MIN_VALUE;
		for(int i = 0; i < n; i++) {
			maxDis = Math.max(maxDis, startDis[i] + endDis[i]);
		}
		System.out.println(maxDis);
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