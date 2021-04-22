import java.util.*;

import java.io.*;

public class ContestOfficial3 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Edge>[] adj;
	static int n, len, far;
	
	static int[] prev, cost;
	
	static class Edge
	{
		int to, weight;
		public Edge(int to, int weight)
		{
			this.to = to;
			this.weight = weight;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), q = readInt();
		
		int[] a = new int[n], preIndex = new int[n], sufIndex = new int[n];
		
		for(int i = 0; i < n; i++)
		{
			a[i] = readInt();
			if(i == 0)
			{
				preIndex[i] = 0;
			}
			else if(a[i] > a[preIndex[i-1]]) {
				preIndex[i] = i;
			}
			else
			{
				preIndex[i] = preIndex[i-1];
			}
		}
		
		for(int i = n-1; i >= 0; i--) {
			if(i == n-1) sufIndex[i] = n-1;
			else if(a[i] > a[sufIndex[i+1]]) {
				sufIndex[i] = i;
			}
			else
			{
				sufIndex[i] = sufIndex[i+1];
			}
		}
		
		for(int i = 0; i < q; i++)
		{
			int point = readInt()-1;
			System.out.println((preIndex[point-1]+1) + " " + (sufIndex[point+1]+1));
		}
		
	}
	
	static void dfs(int cur, int from, int dis)
	{
		//update max dis (only one path so only check if this is not the returning path)
		if(dis > len) { len = dis; far = cur; }
		for(Edge e : adj[cur])
		{
			int to = e.to, weight = e.weight;
			if(to != from)
			{
				prev[to] = cur;
				//store cost to travel from previous node to this node
				cost[to] = weight;
				dfs(to, cur, dis+weight);
			}
		}
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

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}