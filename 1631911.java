import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Point
	{
		int r, c, distance;
		public Point(int r, int c, int distance)
		{
			this.r = r;
			this.c = c;
			this.distance = distance;
		}
	}

	public static void main(String[] args) throws IOException
	{
		int n = readInt(), m = readInt();
		int[][] grid = new int[n][m];
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				grid[i][j] = readInt();
			}
		}
		
		int[][] dis = new int[n][m];
		for(int i = 0; i < dis.length; i++)
		{
			Arrays.fill(dis[i], Integer.MAX_VALUE);
		}
		
		Comparator<Point> comp = new Comparator<Point>()
		{
			@Override
			public int compare(Point arg0, Point arg1) {
				if(arg0.distance == arg1.distance) return 0;
				else return (arg0.distance - arg1.distance) > 0 ? 1 : -1;
			}
		};
		
		PriorityQueue<Point> pq = new PriorityQueue<Point>(comp);
		dis[0][0] = grid[0][0];
		pq.add(new Point(0, 0, dis[0][0]));
		
		while(!pq.isEmpty())
		{
			Point p = pq.remove();
			if(dis[p.r][p.c] < p.distance) continue;
			int[][] dir = {{0, 1}, {1, 0}};
			for(int i = 0; i < dir.length; i++)
			{
				int new_r = p.r + dir[i][0];
				int new_c = p.c + dir[i][1];
				
				if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m)
				{
					//update distance
					if(dis[new_r][new_c] > dis[p.r][p.c] + grid[new_r][new_c])
					{
						dis[new_r][new_c] = dis[p.r][p.c] + grid[new_r][new_c];
						pq.add(new Point(new_r, new_c, dis[new_r][new_c]));
					}
				}
			}
		}
		System.out.println(dis[n-1][m-1]);
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