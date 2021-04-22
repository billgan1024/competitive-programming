import java.util.*;
import java.io.*;

public class WormholeSort {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int[] set;
	
	static int find(int n)
	{
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
	
	static class Edge implements Comparable<Edge>
	{
		int u, v, w;
		public Edge(int u, int v, int w) { this.u = u; this.v = v; this.w = w; }
		@Override
		public int compareTo(Edge e) {
			return e.w-w;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(), pos[] = new int[n+1];
		set = new int[n+1]; for(int i = 1; i <= n; i++) { pos[i] = readInt(); set[i] = i; }
		Edge[] edges = new Edge[m]; for(int i = 0; i < m; i++) edges[i] = new Edge(readInt(), readInt(), readInt());
		Arrays.sort(edges);
		
		int min = Integer.MAX_VALUE; int counter = 0; 
		//if i and pos[i] is connected, then cow pos[i] can return to its original location
		for(int i = 1; i <= n; i++)
		{
			while(!connected(pos[i], i))
			{
				Edge e = edges[counter];
				if(!connected(e.u, e.v))
				{
					merge(e.u, e.v); min = Math.min(min, e.w);
				}
				counter++;
			}
		}
		System.out.println(min == Integer.MAX_VALUE ? -1 : min);
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
}