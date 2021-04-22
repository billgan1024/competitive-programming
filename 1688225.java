import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Integer>[] adj;
	static ArrayList<Integer> currentPath = new ArrayList<Integer>();
	static boolean exists = false;
	static boolean[] vis;
	
	static void dfs(int cur)
	{
		if(exists) return;
		for(int i : adj[cur])
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
					if(currentPath.size()-index >= 6)
					{
						exists = true; return;
					}
				}
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt();
		adj = new ArrayList[n]; for(int i = 0; i < n; i++) adj[i] = new ArrayList<Integer>();
		vis = new boolean[n];
		
		for(int i = 0; i < m; i++)
		{
			int u = readInt()-1, v = readInt()-1;
			adj[u].add(v); adj[v].add(u);
		}
		for(int i = 0; i < n; i++)
		{
			if(exists) break;
			if(vis[i]) continue;
			//dfs on this component
			vis[i] = true;
			currentPath.add(i);
			dfs(i);
			currentPath.remove(currentPath.size()-1);
		}
		if(exists) System.out.println("YES");
		else System.out.println("NO");
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