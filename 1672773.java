import java.util.*;
import java.io.*;

public class ContestOfficial5 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Integer>[] adj;
	static ArrayList<Integer> currentPath = new ArrayList<Integer>();
	static boolean[] vis;
	
	static int minCycle = Integer.MAX_VALUE;
	
	public static void dfs(int n)
	{
		for(int i : adj[n])
		{
			if(!vis[i])
			{
				vis[i] = true;
				currentPath.add(i);
				dfs(i);
				currentPath.remove(currentPath.size()-1);
			}
			else
			{
				int index = currentPath.indexOf(i);
				if(index != -1)
				{
					//this cycle exists
					minCycle = Math.min(minCycle, currentPath.size()-index);
				}
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		adj = new ArrayList[n];
		vis = new boolean[n];
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<Integer>();
		
		for(int i = 0; i < n; i++)
		{
			adj[i].add(readInt()-1);
		}
		
		//find the cycle
		for(int i = 0; i < n; i++)
		{
			if(vis[i]) continue;
			vis[i] = true;
			currentPath.add(i);
			dfs(i);
			currentPath.remove(currentPath.size()-1);
		}
		System.out.println(minCycle);
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