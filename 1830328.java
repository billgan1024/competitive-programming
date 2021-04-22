import java.util.*;
import java.io.*;

public class SpiesLikeUs {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(), k = readInt(); ArrayList<Integer>[] adj = new ArrayList[m+1];
		for(int i = 1; i <= m; i++) adj[i] = new ArrayList<Integer>();
		
		boolean[][] common = new boolean[n+1][n+1];
		
		
		//for each node in m, common shows the nodes in n which share a common vertex in m
		//for each edge that goes from m, update this common matrix
		//if two nodes in n (u and v) share a common vertex, common[u][v] = 1;
		//if they are already marked, then the graph has two nodes that share two common vertices (which isn't allowed)
		//time complexity: n^2 (4*10^6) 
		for(int i = 0; i < k; i++)
		{
			int u = readInt(), v = readInt();
			for(int next : adj[v])
			{
				if(!common[u][next]) { common[u][next] = true; common[next][u] = true; }
				else { System.out.println("NO"); return; }
			}
			adj[v].add(u);
		}
		System.out.println("YES");
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