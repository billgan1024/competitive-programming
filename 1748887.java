import java.util.*;

import java.io.*;

public class MinCostFlow {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;	
	static int[] set; static int total; static Edge[] edges;
	
	static class Edge
	{
		int u, v, cost;
		boolean isNew;
		public Edge(int u, int v, int cost, boolean isNew) {
			this.u = u; this.v = v; this.cost = cost; this.isNew = isNew;
		}
	}
	
	static void init(int n)
	{
		set = new int[n+1]; for(int i = 1; i <= n; i++) set[i] = i; total = n;
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
	
	static boolean merge(int x, int y)
	{
		int fx = find(x), fy = find(y);
		if(fx != fy) { set[fx] = fy; return true; }
		else return false;
	}
	
	static boolean connected(int x, int y)
	{
		return find(x) == find(y);
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(), d = readInt(); init(n);
		edges = new Edge[m];
		
		for(int i = 0; i < m; i++)
		{
			edges[i] = new Edge(readInt(), readInt(), readInt(), i >= n-1);
		}
		Comparator<Edge> comp = new Comparator<Edge>() {
			@Override
			public int compare(Edge arg0, Edge arg1) {
				if(arg0.cost == arg1.cost) {
					//new pipes will be used later
					return (arg0.isNew ? 1 : 0) - (arg1.isNew ? 1 : 0);
				}
				else return arg0.cost-arg1.cost;
			}
		};
		Arrays.sort(edges, comp);
		int swaps = 0, lastCost = 0, lastIndex = 0;
		for(int i = 0; i < m; i++)
		{
			Edge e = edges[i];
			if(merge(e.u, e.v)) {
				//only update when you use this edge
				if(e.isNew) swaps++;
				lastCost = e.cost; lastIndex = i; total--;
			}
			if(total == 1) break;
		}
		
		if(edges[lastIndex].isNew)
		{
			init(n);
			for(int i = 0; i < m; i++)
			{
				Edge e = edges[i];
				if(!connected(e.u, e.v))
				{
					if(e.cost < lastCost || (e.cost == lastCost && !e.isNew))
					{
						merge(e.u, e.v);
					}
					else if(!e.isNew && e.cost <= d) {
						System.out.println(swaps-1);
	                    return;
	                }
				}
			}
		}
		System.out.println(swaps);
		//if the last edge in the mst is an old edge, or if the last edge weight is > d, 
		//enhancer won't help
		//we pick an old edge not in the MST to replace (to check if we can reduce time by 1)
		//This is because if the last edge is greater than or equal to d, the next edge will also be greater than d
		//d will always be used on the last edge in the MST.
		//if last edge already greater than d, any old edge that will try to replace it will have a higher
		//weight and make the total cost greater (doesn't work)
		//if the last edge in the mst is new and > d, 
		//run kruskal again, avoiding all edges in the old mst with cost equal to cost of last edge
		//see if you can connect an old edge to the graph, if you can, then you can reduce
		//# of days by one while still maintaining minimum total cost
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