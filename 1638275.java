import java.util.*;
import java.io.*;

public class Pusheen
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		int n = readInt(), m = readInt();
		ArrayList<Integer>[] adj = new ArrayList[n];
		for(int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0; i < m; i++)
		{
			int x = readInt()-1, y = readInt()-1;
			adj[x].add(y);
			adj[y].add(x);
		}
		int s = readInt()-1, t = readInt()-1;
		if(s == t) {
			System.out.println(m); return;
		}
		
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] vis = new boolean[n];
		int[] dis = new int[n];
			
		queue.add(s);
		vis[s] = true;
		
		boolean exists = false;
		int min = 0;
			
		while(!queue.isEmpty() && !exists)
		{
			int cur = queue.remove();
			for(int i : adj[cur])
			{
				if(vis[i]) continue;
				vis[i] = true;
				dis[i] = dis[cur] + 1;
				if(i == t) {
					min = m - dis[i];
					exists = true;
					break;
				}
				queue.add(i);
			}
		}
		
		System.out.println(min);
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