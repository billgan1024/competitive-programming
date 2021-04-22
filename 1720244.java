import java.util.*;
import java.io.*;

public class TruckingTroubles {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int[] set, dests;
	
	static class Edge
	{
		int u, v, cap;
		public Edge(int u, int v, int cap) {
			this.u = u; this.v = v; this.cap = cap;
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
	
	static void merge(int x, int y)
	{
		int fx = find(x), fy = find(y);
		if(fx != fy) set[fx] = fy;
	}
	
	static boolean connected()
	{
		//check if every destination is connected to 1
		for(int i : dests)
		{
			if(find(i) != find(1)) return false;
		}
		return true;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int c = readInt(), r = readInt(), d = readInt();
		set = new int[c+1]; for(int i = 1; i <= c; i++) set[i] = i;
		
		Edge[] roads = new Edge[r]; dests = new int[d];
		for(int i = 0; i < r; i++) roads[i] = new Edge(readInt(), readInt(), readInt());
		for(int i = 0; i < d; i++) dests[i] = readInt();
		
		Comparator<Edge> comp = new Comparator<Edge>() {
			@Override
			public int compare(Edge arg0, Edge arg1) {
				// TODO Auto-generated method stub
				return arg1.cap-arg0.cap;
			}
		};
		
		Arrays.sort(roads, comp);
		
		int maxWeight = Integer.MAX_VALUE;
		for(Edge e : roads)
		{
			merge(e.u, e.v); maxWeight = Math.min(maxWeight, e.cap);
			if(connected()) 
			{
				System.out.println(maxWeight); return;
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