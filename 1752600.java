import java.util.*;
import java.io.*;

public class ShopAndShip {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), t = readInt();
		int[][] adj = new int[n][n];
		
		for(int i = 0; i < t; i++)
		{
			int u = readInt()-1, v = readInt()-1, w = readInt();
			if(adj[u][v] == 0 || w < adj[u][v]) adj[u][v] = w;
			if(adj[v][u] == 0 || w < adj[v][u]) adj[v][u] = w;
		}
		HashMap<Integer, Integer> stores = new HashMap<Integer, Integer>();
		int k = readInt();
		for(int i = 0; i < k; i++)
		{
			stores.put(readInt()-1, readInt());
		}
		int d = readInt()-1;
		
		//commit dijkstra
		int[] dis = new int[n]; Arrays.fill(dis, Integer.MAX_VALUE);
		boolean[] vis = new boolean[n];
		dis[d] = 0;
		
		for(int i = 0; i < n; i++)
		{
			int minDis = Integer.MAX_VALUE, cur = -1;
			for(int j = 0; j < n; j++)
			{
				if(dis[j] < minDis && !vis[j]) { minDis = dis[j]; cur = j; }
			}
			
			if(cur == -1) break; vis[cur] = true;
			
			for(int j = 0; j < adj[cur].length; j++)
			{
				if(adj[cur][j] != 0) {
					if(dis[cur] + adj[cur][j] < dis[j]) dis[j] = dis[cur] + adj[cur][j];
				}
			}
		}
		
		int minPrice = Integer.MAX_VALUE;
		for(int i : stores.keySet())
		{
			minPrice = Math.min(minPrice, stores.get(i) + dis[i]);
		}
		System.out.println(minPrice);
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