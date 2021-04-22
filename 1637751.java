import java.util.*;
import java.io.*;

public class JaydenTrees {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		ArrayList<Integer>[] adj = new ArrayList[n];
		
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<Integer>();
		
		for(int i = 0; i < n-1; i++)
		{
			int a = readInt()-1, b = readInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] vis = new boolean[n];
		int[] dis = new int[n];
		
		int maxDis = Integer.MIN_VALUE;
		int maxVertex = Integer.MIN_VALUE;
		
		queue.add(0);
		vis[0] = true;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(int i : adj[cur])
			{
				if(vis[i]) continue;
				vis[i] = true;
				dis[i] = dis[cur] + 1;
				if(maxDis < dis[i])
				{
					maxDis = dis[i];
					maxVertex = i;
				}
				queue.add(i);
			}
		}
		
		maxDis = Integer.MIN_VALUE;
		vis = new boolean[n];
		dis = new int[n];
		queue.add(maxVertex);
		vis[maxVertex] = true;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(int i : adj[cur])
			{
				if(vis[i]) continue;
				vis[i] = true;
				dis[i] = dis[cur] + 1;
				maxDis = Math.max(maxDis, dis[i]);
				queue.add(i);
			}
		}
		
		System.out.println(maxDis);

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