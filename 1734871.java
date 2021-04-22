import java.util.*;
import java.io.*;

public class ChristmasDish {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Integer>[] adj;
	static HashSet<Integer> required = new HashSet<Integer>();
	
	static int[] set; static boolean[] vis;
	
	static int find(int n)
	{
		//use path compression to update the parent of all the middle nodes as well as the 
		//origin node
		if(set[n] != n)
		{ 
			set[n] = find(set[n]);
		}
		return set[n];
	}
	
	static void merge(int x, int y)
	{
		int fx = find(x), fy = find(y);
		if(fx != fy) set[fx] = fy;
	}
	
	static boolean connected(int x, int y)
	{
		return find(x) == find(y);
	}
	
	static void dfs(int cur)
	{
		vis[cur] = true; required.remove(cur);
		for(int i : adj[cur])
		{
			if(vis[i]) continue;
			vis[i] = true;
			required.remove(i);
			dfs(i);
		}
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		//store the list of required base elements that build element 1
		int n = readInt(), m = readInt(), d = readInt();
		adj = new ArrayList[n+1]; for(int i = 1; i <= n; i++) adj[i] = new ArrayList<Integer>();
		set = new int[n+1]; for(int i = 1; i <= n; i++) set[i] = i;
		
		for(int i = 0; i < m; i++)
		{
			int target = readInt(), count = readInt(); 
			required.remove(target);
			for(int j = 0; j < count; j++)
			{
				int element = readInt();
				adj[target].add(element); merge(target, element);
				if(adj[element].size() == 0) required.add(element);
			}
		}
		required.removeIf(i -> !connected(i, 1));
		vis = new boolean[n+1];
		for(int i = 1; i <= d; i++)
		{
			int p = readInt();
			if(vis[p]) continue;
			dfs(p);
			if(required.isEmpty())
			{
				System.out.println(i); return;
			}
		}
		System.out.println(-1);
		
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