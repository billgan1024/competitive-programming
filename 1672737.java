import java.util.*;
import java.io.*;

public class ContestOfficial4 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Edge
	{
		int to, weight;
		public Edge(int to, int weight)
		{
			this.to = to;
			this.weight = weight;
		}
	}

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		ArrayList<Edge>[] adj = new ArrayList[n];
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<Edge>();
		
		for(int i = 0; i < n-1; i++)
		{
			int u = readInt()-1, v = readInt()-1, weight = readInt();
			adj[u].add(new Edge(v, weight));
			adj[v].add(new Edge(u, weight));
		}
		
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] vis = new boolean[n];
		int[] dis = new int[n];
		
		queue.add(0); vis[0] = true;
		
		int maxDis = -1, endpoint1 = -1;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(Edge e : adj[cur])
			{
				if(vis[e.to]) continue;
				vis[e.to] = true;
				dis[e.to] = dis[cur] + e.weight;
				if(dis[e.to] > maxDis)
				{
					maxDis = dis[e.to]; endpoint1 = e.to;
				}
				queue.add(e.to);
			}
		}
		
		int endpoint2 = -1;
		maxDis = -1;
		vis = new boolean[n];
		dis = new int[n];
		int[] prev = new int[n];
		prev[endpoint1] = -1;
		
		queue.add(endpoint1);
		vis[endpoint1] = true;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(Edge e : adj[cur])
			{
				if(vis[e.to]) continue;
				vis[e.to] = true;
				dis[e.to] = dis[cur] + e.weight;
				if(dis[e.to] > maxDis)
				{
					maxDis = dis[e.to]; endpoint2 = e.to;
				}
				prev[e.to] = cur;
				queue.add(e.to);
			}
		}
		System.out.println(maxDis);
		
		ArrayList<Integer> diameterPath = new ArrayList<Integer>();
		ArrayList<Integer> costs = new ArrayList<Integer>();
		
		int previousNode = -1;
		for(int i = endpoint2; i != -1; i = prev[i])
		{
			diameterPath.add(i);
			//find edge cost
			for(Edge e : adj[i])
			{
				if(e.to == previousNode)
				{
					costs.add(e.weight); break;
				}
			}
			previousNode = i;
		}
		
		int minDis = Integer.MAX_VALUE;
		
		for(int i = 0; i < diameterPath.size(); i++)
		{
			int leftSum = 0, rightSum = 0;
			
			for(int j = i-1; j >= 0; j--)
			{
				leftSum += costs.get(j);
			}
			for(int j = i; j < costs.size(); j++)
			{
				rightSum += costs.get(j);
			}
			int localMax = Math.max(leftSum, rightSum);
			minDis = Math.min(minDis, localMax);
		}
		System.out.println(minDis);
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