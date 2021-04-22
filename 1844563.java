import java.util.*;
import java.io.*;

public class SaveNagato {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int maxNode, maxDis, n;
	
	static void bfs(int o, ArrayList<Integer>[] adj, int[] dis)
	{
		maxNode = maxDis = -1;
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] vis = new boolean[n+1];
		queue.add(o); vis[o] = true;
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(int i : adj[cur])
			{
				if(vis[i]) continue;
				vis[i] = true; dis[i] = dis[cur] + 1;
				if(maxDis < dis[i]) { maxDis = dis[i]; maxNode = i; }
				queue.add(i);
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		n = readInt(); ArrayList<Integer>[] adj = new ArrayList[n+1]; 
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<Integer>();
		for(int i = 0; i < n-1; i++)
		{
			int u = readInt(), v = readInt(); adj[u].add(v); adj[v].add(u);
		}
		
		int[] temp = new int[n+1], dis1 = new int[n+1], dis2 = new int[n+1];
		bfs(1, adj, temp); bfs(maxNode, adj, dis1); bfs(maxNode, adj, dis2);
		for(int i = 1; i <= n; i++)
		{
			System.out.println(Math.max(dis1[i], dis2[i]) + 1);
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