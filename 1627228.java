import java.util.*;
import java.io.*;

public class ANoisyClass {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Integer> currentPath = new ArrayList<Integer>();
	static boolean cycle = false;
	static ArrayList<Integer>[] adj;
	static boolean[] vis;
	
	public static void dfs(int n)
	{
		if(cycle) return;
		for(int i : adj[n])
		{
			if(!vis[i])
			{
				vis[i] = true;
				currentPath.add(i);
				dfs(i);
				currentPath.remove(currentPath.size()-1);
			}
			else if(currentPath.contains(i))
			{
				cycle = true;
				return;
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		adj = new ArrayList[n];
		for(int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Integer>();
		}
		vis = new boolean[n];
		
		int m = readInt();
		
		for(int i = 0; i < m; i++)
		{
			int a = readInt()-1, b = readInt()-1;
			
			if(!adj[a].contains(b)) adj[a].add(b);
		}
		
		
		for(int i = 0; i < n; i++)
		{
			if(cycle) break;
			if(vis[i]) continue;
			//dfs on this component
			vis[i] = true;
			currentPath.add(i);
			dfs(i);
			currentPath.remove(currentPath.size()-1);
			
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