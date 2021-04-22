import java.util.*;
import java.io.*;

public class Dijkstra {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	//dijkstra runs from one node, gets shortest path to ALL other nodes in a weighted graph
	//maintain a distance array, vis array (dis array is infinite at first 
	//loop n rounds:
	//select a vertex with minimum distance that is not visited
	//set current = a, mark a as visited and update distances to all of its neighbours
	//this will be min(dis of neighbour node, dis of current node + weight of edge from cur to neighbour)
	//
	//every time, pick the node with the least cost to travel to
	//
	
	static class Edge
	{
		int to, dis;
		public Edge(int to, int dis)
		{
			this.to = to;
			this.dis = dis;
		}
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt();
		int[][] adj = new int[n][n];
		for(int i = 0; i < m; i++)
		{
			int u = readInt()-1, v = readInt()-1, w = readInt();
			if(adj[u][v] == 0 || w < adj[u][v]) adj[u][v] = w;
			if(adj[v][u] == 0 || w < adj[v][u]) adj[v][u] = w;
		}
		int[] dis = new int[n]; Arrays.fill(dis, Integer.MAX_VALUE);
		boolean[] vis = new boolean[n];
		dis[0] = 0;
		for(int i = 0; i < n; i++)
		{
			//find the vertex with min distance that has not yet been visited
			int minDis = Integer.MAX_VALUE, cur = -1;
			for(int j = 0; j < n; j++)
			{
				if(dis[j] < minDis && !vis[j]) { minDis = dis[j]; cur = j; }
			}
			if(cur == -1) break;
			vis[cur] = true;
			//update distances to all other neighbours if they are better
			for(int j = 0; j < adj[cur].length; j++)
			{
				if(adj[cur][j] != 0) {
					if(dis[cur] + adj[cur][j] < dis[j]) dis[j] = dis[cur] + adj[cur][j];
				}
			}
		}
		for(int i = 0; i < n; i++)
		{
			if(dis[i] == Integer.MAX_VALUE) System.out.println(-1);
			else System.out.println(dis[i]);
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