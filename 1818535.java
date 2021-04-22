import java.util.*;
import java.io.*;

public class CherryTree {
	
	static class Node
	{
		int id, depth;
		public Node(int id, int depth) { this.id = id; this.depth = depth; }
	}
	
	static class Edge
	{
		int to, weight;
		public Edge(int to, int weight) { this.to = to; this.weight = weight; }
	}
	
	static ArrayList<Edge>[] adj;
	static PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {
		@Override
		public int compare(Node arg0, Node arg1) {
			return arg1.depth-arg0.depth; //sorts by deepest node first
		}
	});
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static void dfs(int cur, int depth) {
		if(adj[cur].size() == 0) pq.add(new Node(cur, depth));
		else
		{
			for(Edge e : adj[cur]) dfs(e.to, depth+1);
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), c = readInt(), k = readInt(); if(n == 1) { System.out.println(0); return; }
		
		//cherries = total cherries from this node & beyond
		//weight = total weight from beyond this node (get parent weight from the in edge)
		int[] cherries = new int[n+1], weight = new int[n+1];
		for(int i = 1; i <= n; i++) cherries[i] = readInt();
		Edge[] parent = new Edge[n+1];
		adj = new ArrayList[n+1]; for(int i = 1; i <= n; i++) adj[i] = new ArrayList<Edge>();
		
		//use out for dfs distance from origin, use in for collecting the sum of weights and cherries
		for(int i = 0; i < n-1; i++) {
			int a = readInt(), b = readInt(), w = readInt();
			adj[a].add(new Edge(b, w)); parent[b] = new Edge(a, w);
		}
		dfs(1, 0);
		
		boolean[] vis = new boolean[n+1];
		while(!pq.isEmpty()) {
			Node node = pq.remove(); Edge e = parent[node.id];
			if(!vis[e.to] && e.to != 1) { vis[e.to] = true; pq.add(new Node(e.to, node.depth-1)); }
			cherries[e.to] += cherries[node.id]; weight[e.to] += e.weight; weight[e.to] += weight[node.id]; 
		}
		int count = 0;
		for(int i = 2; i <= n; i++) {
			if(cherries[i] >= c && weight[i] + parent[i].weight <= k) count++;
		}
		System.out.println(count);
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