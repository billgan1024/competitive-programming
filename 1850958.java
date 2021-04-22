import java.util.*;
import java.io.*;

public class FencePlanning {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(); int[][] grid = new int[n+1][2];
		ArrayList<Integer>[] adj = new ArrayList[n+1]; 
		for(int i = 1; i <= n; i++)
		{
			adj[i] = new ArrayList<Integer>();
			grid[i][0] = readInt(); grid[i][1] = readInt();
		}
		
		for(int i = 0; i < m; i++)
		{
			int a = readInt(), b = readInt();
			adj[a].add(b); adj[b].add(a);
		}
		
		boolean[] vis = new boolean[n+1]; 
		ArrayList<ArrayList<Integer>> components = new ArrayList<ArrayList<Integer>>();
		Queue<Integer> q = new LinkedList<Integer>();
		
		for(int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			ArrayList<Integer> c = new ArrayList<Integer>();
			vis[i] = true; c.add(i); q.add(i);
			while(!q.isEmpty())
			{
				int cur = q.remove();
				for(int next : adj[cur])
				{
					if(vis[next]) continue;
					vis[next] = true; c.add(next); q.add(next);
				}
			}
			components.add(c);
		}
		
		int ans = Integer.MAX_VALUE;
		for(ArrayList<Integer> c : components)
		{
			int min_x = grid[c.get(0)][0], max_x = grid[c.get(0)][0];
			int min_y = grid[c.get(0)][1], max_y = grid[c.get(0)][1];
			for(int i = 1; i < c.size(); i++)
			{
				min_x = Math.min(min_x, grid[c.get(i)][0]);
				max_x = Math.max(max_x, grid[c.get(i)][0]);
				min_y = Math.min(min_y, grid[c.get(i)][1]);
				max_y = Math.max(max_y, grid[c.get(i)][1]);
			}
			ans = Math.min(ans, 2*(max_x - min_x + max_y - min_y));
		}
		System.out.println(ans);
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