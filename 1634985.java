import java.util.*;
import java.io.*;

public class Dijkstra {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Point
	{
		int node, distance;
		public Point(int node, int distance)
		{
			this.node = node;
			this.distance = distance;
		}
	}

	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt();
		int[][] adj = new int[n][n];
		
		for(int i = 0; i < m; i++)
		{
			int u = readInt()-1, v = readInt()-1, w = readInt();
			if(adj[u][v] == 0 || adj[u][v] > w) adj[u][v] = w;
			if(adj[v][u] == 0 || adj[v][u] > w) adj[v][u] = w;
		}
		
		int[] dis = new int[n];
		Arrays.fill(dis, Integer.MAX_VALUE);
		
		Comparator<Point> comp = new Comparator<Point>()
		{
			@Override
			public int compare(Point arg0, Point arg1) {
				if(arg0.distance == arg1.distance) return 0;
				else return (arg0.distance - arg1.distance) > 0 ? 1 : -1;
			}
		};
		
		PriorityQueue<Point> pq = new PriorityQueue<Point>(comp);
		
		dis[0] = 0;
		pq.add(new Point(0, dis[0]));
		
		while(!pq.isEmpty())
		{
			Point p = pq.remove();
			if(dis[p.node] < p.distance) continue;
			for(int i = 0; i < adj[p.node].length; i++)
			{
				//i is the neighbouring vertex
				if(adj[p.node][i] != 0)
				{
					int weight = adj[p.node][i];
					if(dis[i] > p.distance + weight)
					{
						dis[i] = p.distance + weight; 
						pq.add(new Point(i, dis[i]));
					}
				}
			}
		}
		
		for(int i = 0; i < n; i++)
		{
			if(dis[i] == Integer.MAX_VALUE) System.out.println(-1);
			else System.out.println(dis[i]);
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