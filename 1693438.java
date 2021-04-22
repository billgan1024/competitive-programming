import java.util.*;
import java.io.*;

public class ItsTough {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static boolean cycle = false;
	static int[] vis = new int[8];

	static void dfs(ArrayList<Integer>[] adj, int cur)
	{
		if(cycle) return;
		for(int i : adj[cur])
		{
			if(vis[i] == 2) continue;
			else if(vis[i] == 1)
			{
				cycle = true; break;
			}
			else
			{
				vis[i] = 1;
				dfs(adj, i);
			}
		}
		vis[cur] = 2;
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		ArrayList<Integer>[] adj = new ArrayList[8];
		int[] in = new int[8]; //in-degree of each node
		for(int i = 1; i < 8; i++) adj[i] = new ArrayList<Integer>();
		
		adj[1].add(7); adj[1].add(4); adj[2].add(1); adj[3].add(4); adj[3].add(5);
		in[1] = 1; in[4] = 2; in[5] = 1; in[7] = 1;
		
		int from = readInt(), to = readInt();
		while(from != 0 && to != 0)
		{
			adj[from].add(to);
			in[to]++;
			from = readInt(); to = readInt();
		}
		
		//first check if there are any cycles
		vis[1] = 1;
		dfs(adj, 1);
		if(cycle)
		{
			System.out.println("Cannot complete these tasks. Going to bed."); return;
		}
		
		//takes lowest available node first
		PriorityQueue<Integer> available = new PriorityQueue<Integer>();
		for(int i = 1; i < 8; i++)
		{
			if(in[i] == 0) available.add(i);
		}
		
		while(!available.isEmpty())
		{
			int i = available.remove();
			System.out.print(i + " ");
			for(int j : adj[i])
			{
				in[j]--;
				if(in[j] == 0) available.add(j);
			}
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

	public static int lower_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] >= x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}

	public static int upper_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] > x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}
}