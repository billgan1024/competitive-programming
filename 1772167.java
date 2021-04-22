import java.util.*;
import java.io.*;

public class ContestOfficial2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int[] set;
	
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
	
	static class Edge
	{
		int u, v, fiberWeight, cableWeight;
		boolean used = false;
		public Edge(int u, int v, int fiberWeight, int cableWeight)
		{
			this.u = u; this.v = v; this.fiberWeight = fiberWeight; this.cableWeight = cableWeight;
		}
	}
	
	
	public static void main(String[] args) throws IOException {
		int n = readInt(), k = readInt(), m = readInt();
		set = new int[n+1]; for(int i = 1; i <= n; i++) set[i] = i;
		Edge[] edges = new Edge[m];
		for(int i = 0; i < m; i++) {
			edges[i] = new Edge(readInt(), readInt(), readInt(), readInt());
		}
		
		Comparator<Edge> fiberComp = new Comparator<Edge>() {

			@Override
			public int compare(Edge o1, Edge o2) {
				return o1.fiberWeight-o2.fiberWeight;
			}
		};
		
		Comparator<Edge> remainingComp = new Comparator<Edge>() {

			@Override
			public int compare(Edge o1, Edge o2) {
				if(o1.used && o2.used) return 0;
				else if(!o1.used && o2.used) return -1;
				else if(o1.used && !o2.used) return 1;
				else
				{
					int best1 = Math.min(o1.fiberWeight, o1.cableWeight);
					int best2 = Math.min(o2.fiberWeight, o2.cableWeight);
					return best1-best2;
				}
			}
		};
		
		Arrays.sort(edges, fiberComp);
		
		int maxCost = Integer.MIN_VALUE;
		int connected = 0;
		
		for(Edge e : edges) {
			if(connected == k) break;
			if(!connected(e.u, e.v)) {
				
				merge(e.u, e.v); 
				maxCost = Math.max(maxCost, e.fiberWeight);
				connected++;
				e.used = true;
			}
		}
		
		Arrays.sort(edges, remainingComp);
		for(Edge e : edges) {
			if(connected == n-1) break;
			if(!connected(e.u, e.v)) {
				
				merge(e.u, e.v); 
				maxCost = Math.max(maxCost, Math.min(e.fiberWeight, e.cableWeight));
				connected++;
			}
		}
		System.out.println(maxCost);
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