import java.util.*;
import java.io.*;

public class FrankAndRoads {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Point
	{
		int id, dis;
		public Point(int id, int dis) {
			this.id = id; this.dis = dis;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int t = readInt(), n = readInt(), m = readInt(), g = readInt();
		int[][] adj = new int[n+1][n+1]; int[] stores = new int[g];
		
		for(int i = 0; i < g; i++) stores[i] = readInt();
		
		for(int i = 0; i < m; i++)
		{
			int a = readInt(), b = readInt(), l = readInt();
			adj[a][b] = l;
		}
		
		Comparator<Point> comp = new Comparator<Point>() {
			@Override
			public int compare(Point arg0, Point arg1) {
				// TODO Auto-generated method stub
				return arg0.dis-arg1.dis;
			}
		};
		
		int[] dis = new int[n+1]; Arrays.fill(dis, Integer.MAX_VALUE);
		PriorityQueue<Point> pq = new PriorityQueue<Point>(comp);
		dis[0] = 0; pq.add(new Point(0, dis[0]));
		while(!pq.isEmpty())
		{
			Point p = pq.remove();
			if(p.dis > dis[p.id]) continue;
			for(int i = 0; i <= n; i++)
			{
				if(adj[p.id][i] != 0 && dis[i] > dis[p.id] + adj[p.id][i])
				{
					dis[i] = dis[p.id] + adj[p.id][i];
					pq.add(new Point(i, dis[i]));
				}
			}
		}
		
		int count = 0;
		for(int i : stores)
		{
			if(dis[i] < t) count++;
		}
		System.out.println(count);
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