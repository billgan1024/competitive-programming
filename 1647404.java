import java.util.*;
import java.io.*;

public class SaveNagato {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		ArrayList<Integer>[] adj = new ArrayList[n];
		
		for(int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0; i < n-1; i++)
		{
			int x = readInt()-1, y = readInt()-1;
			adj[x].add(y);
			adj[y].add(x);
		}
		
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] vis = new boolean[n];
		int[] dis = new int[n];
		
		queue.add(0);
		vis[0] = true;
		
		int endpoint = -1;
		int maxDistance = -1;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(int i : adj[cur])
			{
				if(vis[i]) continue;
				vis[i] = true;
				dis[i] = dis[cur] + 1;
				if(maxDistance < dis[i])
				{
					maxDistance = dis[i];
					endpoint = i;
				}
				queue.add(i);
			}
		}
		
		vis = new boolean[n];
		dis = new int[n];
		
		maxDistance = -1;
		
		queue.add(endpoint);
		vis[endpoint] = true;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(int i : adj[cur])
			{
				if(vis[i]) continue;
				vis[i] = true;
				dis[i] = dis[cur] + 1;
				if(maxDistance < dis[i])
				{
					maxDistance = dis[i];
					endpoint = i;
				}
				queue.add(i);
			}
		}
		//max distance from one diameter endpoint is dis[]
		
		//other endpoint is found
		int[] otherDis = new int[n];
		vis = new boolean[n];
		
		queue.add(endpoint);
		vis[endpoint] = true;
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(int i : adj[cur])
			{
				if(vis[i]) continue;
				vis[i] = true;
				otherDis[i] = otherDis[cur] + 1;
				queue.add(i);
			}
		}
		
		//max distance from other diameter endpoint is otherDis[]
		
		//for every node, find the maximum distance it can travel
		//that will be how many "levels" in the tree there are assuming that node
		//is the parent
		for(int i = 0; i < n; i++)
		{
			System.out.println(Math.max(dis[i], otherDis[i]) + 1);
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