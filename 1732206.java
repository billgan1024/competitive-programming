import java.util.*;
import java.io.*;

public class LineGraph {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int[] set; static int totalSets, sum = 0;
	
	static class Edge
	{
		int u, v, w;
		public Edge(int u, int v, int w) {
			this.u = u; this.v = v; this.w = w;
		}
	}
	
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
	
	static void merge(int x, int y, int weight)
	{
		int fx = find(x), fy = find(y);
		if(fx != fy) { set[fx] = fy; totalSets--; sum += weight; }
	}
	
	static boolean connected(int x, int y)
	{
		return find(x) == find(y);
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), k = readInt(); set = new int[n+1];
		for(int i = 1; i <= n; i++) set[i] = i;
		totalSets = k;
		Edge[] edges = new Edge[n-1];
		
		for(int i = 1; i <= n-1; i++)
		{
			edges[i-1] = (new Edge(i, i+1, readInt()));
		}
		
		for(int i = k+1; i <= n; i++) merge(i, i-k, 0);
		
		Comparator<Edge> comp = new Comparator<Edge>() {
			@Override
			public int compare(Edge arg0, Edge arg1) {
				return arg0.w-arg1.w;
			}
		};
		Arrays.sort(edges, comp);
		for(Edge e : edges)
		{
			merge(e.u, e.v, e.w);
			if(totalSets == 1) break;
		}
		System.out.println(sum);
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