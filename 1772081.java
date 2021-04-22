import java.util.*;

import java.io.*;

public class ContestOfficial3 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Point
	{
		int id, dis;
		public Point(int id, int dis) {
			this.id = id; this.dis = dis;
		}
	}
	
	static ArrayList<Point>[] adj, adjReverse;
	
	static int[] shortestPath(int a, int n) {
		int[] dis = new int[n+1]; Arrays.fill(dis, Integer.MAX_VALUE);
		
		Comparator<Point> comp = new Comparator<Point>() {
			@Override
			public int compare(Point arg0, Point arg1) {
				return arg0.dis-arg1.dis;
			}
		};
		
		PriorityQueue<Point> pq = new PriorityQueue<Point>(comp);
		
		dis[a] = 0; pq.add(new Point(a, dis[a]));
		
		while(!pq.isEmpty()) {
			Point cur = pq.remove();
			if(cur.dis > dis[cur.id]) continue;
			
			for(Point e : adj[cur.id]) {
				if(dis[e.id] > cur.dis + e.dis)
				{
					dis[e.id] = cur.dis + e.dis;
					pq.add(new Point(e.id, dis[e.id]));
				}
			}
		}
		return dis;
	}
	
	static int[] shortestReversePath(int a, int n) {
		int[] dis = new int[n+1]; Arrays.fill(dis, Integer.MAX_VALUE);
		
		Comparator<Point> comp = new Comparator<Point>() {
			@Override
			public int compare(Point arg0, Point arg1) {
				return arg0.dis-arg1.dis;
			}
		};
		
		PriorityQueue<Point> pq = new PriorityQueue<Point>(comp);
		
		dis[a] = 0; pq.add(new Point(a, dis[a]));
		
		while(!pq.isEmpty()) {
			Point cur = pq.remove();
			if(cur.dis > dis[cur.id]) continue;
			
			for(Point e : adjReverse[cur.id]) {
				if(dis[e.id] > cur.dis + e.dis)
				{
					dis[e.id] = cur.dis + e.dis;
					pq.add(new Point(e.id, dis[e.id]));
				}
			}
		}
		return dis;
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(), k = readInt(), q = readInt();
		
		adj = new ArrayList[n+1]; adjReverse = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) {
			adj[i] = new ArrayList<Point>(); adjReverse[i] = new ArrayList<Point>();
		}
		
		for(int i = 0; i < m; i++) {
			int u = readInt(), v = readInt(), w = readInt();
			adj[u].add(new Point(v, w)); adjReverse[v].add(new Point(u, w));
		}
		
		int[][] hubDis = new int[k][n+1];
		int[][] hubReverseDis = new int[k][n+1];
		
		for(int i = 0; i < k; i++) {
			int hub = readInt();
			hubDis[i] = shortestPath(hub, n);
			hubReverseDis[i] = shortestReversePath(hub, n);
		}
		
		
		long minCost = 0;
		int fulfilled = 0;
		for(int i = 0; i < q; i++) {
			int a = readInt(), b = readInt();
			long min = Integer.MAX_VALUE;
			for(int j = 0; j < k; j++) {
				min = Math.min(min, (long)hubDis[j][b] + (long)hubReverseDis[j][a]);
			}
			if(min != Integer.MAX_VALUE)
			{
				fulfilled++;
				minCost += min;
			}
		}
		System.out.println(fulfilled);
		System.out.println(minCost);
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