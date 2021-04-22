import java.util.*;
import java.io.*;

public class ANoisyClass {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static boolean cycle = false;
	static ArrayList<Integer>[] adj;
	static int[] vis;
	
	public static void dfs(int cur)
	{
		if(cycle) return;
		vis[cur] = 1;
		for(int i : adj[cur])
		{
			if(vis[i] == 0) dfs(i);
			else if(vis[i] == 1) { cycle = true; return; }
		}
		vis[cur] = 2;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		adj = new ArrayList[n];
		for(int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Integer>();
		}
		vis = new int[n];
		
		int m = readInt();
		
		for(int i = 0; i < m; i++)
		{
			int a = readInt()-1, b = readInt()-1;
			
			if(!adj[a].contains(b)) adj[a].add(b);
		}
		
		
		for(int i = 0; i < n; i++)
		{
			if(cycle) break;
			if(vis[i] == 2) continue;
			//dfs on this component
			dfs(i);		
		}
		
		if(!cycle) System.out.println("Y");
		else System.out.println("N");
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