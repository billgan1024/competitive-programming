import java.util.*;
import java.io.*;

public class RunningInCircles {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Integer> path, adj[]; static boolean[] vis; static int len;
	
	static void dfs(int cur)
	{
		if(len != 0) return;
		vis[cur] = true;
		for(int i : adj[cur])
		{
			if(vis[i] && path.contains(i))
			{
				len = path.size()-path.indexOf(i);
				break;
			}
			else
			{
				vis[i] = true; path.add(i); dfs(i); path.remove(path.size()-1);
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		for(int c = 0; c < 5; c++)
		{
			int n = readInt(); adj = new ArrayList[100]; path = new ArrayList<Integer>();
			for(int i = 0; i < 100; i++) adj[i] = new ArrayList<Integer>();
			vis = new boolean[100]; len = 0;
			for(int i = 0; i < n; i++)
			{
				int a = readInt()-1, b = readInt()-1;
				adj[a].add(b);
			}
			path.add(0); dfs(0);
			System.out.println(len);
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