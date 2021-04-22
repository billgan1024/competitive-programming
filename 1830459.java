import java.util.*;
import java.io.*;

public class CherryTreeOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Edge
	{
		int to, weight;
		public Edge(int to, int weight) { this.to = to; this.weight = weight; }
	}
	
	static int n, c, k, cherries[], cherrySum[], weightSum[], ans;
	static ArrayList<Edge>[] adj;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		//read the tree, store weights and cherries SUM in an array
		//dfs from root node 1, update sum
		//on the return trip, add the cherry sum from the child to the parent node
		//do the same for the weights (each node carries the sum of weights for all its children)
		n = readInt(); c = readInt(); k = readInt();
		adj = new ArrayList[n+1]; for(int i = 1; i <= n; i++) adj[i] = new ArrayList<Edge>();
		
		//this way only requires ONE DFS to sum up the cherries and weights
		cherries = new int[n+1]; cherrySum = new int[n+1]; weightSum = new int[n+1];
		for(int i = 1; i <= n; i++) cherries[i] = readInt();
		
		for(int i = 0; i < n-1; i++)
		{
			int u = readInt(), v = readInt(), w = readInt();
			adj[u].add(new Edge(v, w));
			adj[v].add(new Edge(u, w));
		}
		//dfs on a tree, u don't need a visited array; u only need a parent array
		dfs(1, (int)1e9, 0);
		System.out.println(ans);
	}
	
	static void dfs(int cur, int parentWeight, int prev)
	{
		weightSum[cur] = parentWeight; cherrySum[cur] = cherries[cur];
		for(Edge e : adj[cur])
		{
			int v = e.to, weight = e.weight;
			if(v != prev) { 
				dfs(v, weight, cur);
				//sum up results when the recursion goes back
				cherrySum[cur] += cherrySum[v]; weightSum[cur] += weightSum[v];
			}
		}
		//when this vertex is done, check if a cut on this vertex is valid
		if(cherrySum[cur] >= c && weightSum[cur] <= k) ans++;
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