import java.util.*;
import java.io.*;

public class RoboThieves {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st; static ArrayList<Point> path = new ArrayList<Point>();
	
	static class Point
	{
		int r, c;
		public Point(int r, int c) { this.r = r; this.c = c; }
		@Override
		public boolean equals(Object o)
		{
			Point p = (Point) o; return (r == p.r && c == p.c);
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(); char[][] grid = new char[n][m];
		ArrayList<Point> end = new ArrayList<Point>(), cam = new ArrayList<Point>(); Point start = new Point(0, 0);
		for(int i = 0; i < n; i++)
		{
			String s = readLine();
			for(int j = 0; j < m; j++)
			{
				grid[i][j] = s.charAt(j);
				if(grid[i][j] == 'S') start = new Point(i, j);
				else if(grid[i][j] == '.') end.add(new Point(i, j));
				else if(grid[i][j] == 'C') cam.add(new Point(i, j));
			}
		}
		
		int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		
		for(Point p : cam)
		{
			//extend walls for this camera's line of sight
			for(int i = 0; i < 4; i++)
			{
				int r = p.r + dir[i][0], c = p.c + dir[i][1];
				while(r >= 0 && r < n && c >= 0 && c < m)
				{
					if(grid[r][c] == 'W') break;
					if(grid[r][c] == 'S' || grid[r][c] == '.') grid[r][c] = 'C';
					r += dir[i][0]; c += dir[i][1];
				}
			}
		}
		
		Queue<Point> q = new LinkedList<Point>();
		boolean[][] vis = new boolean[n][m]; int[][] dis = new int[n][m];
		if(grid[start.r][start.c] == 'S') { vis[start.r][start.c] = true; q.add(start); }
		while(!q.isEmpty())
		{
			Point c = q.remove(); int cr = c.r, cc = c.c;
			for(int i = 0; i < 4; i++)
			{
				int nr = cr+dir[i][0], nc  = cc+dir[i][1];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m)
				{
					if(grid[nr][nc] == 'W' || grid[nr][nc] == 'C') continue;
					else if(grid[nr][nc] == '.')
					{
						if(vis[nr][nc]) continue;
						vis[nr][nc] = true; dis[nr][nc] = dis[cr][cc] + 1; q.add(new Point(nr, nc));
					}
					else 
					{
						boolean valid = true;
						while(true)
						{
							if(nr < 0 || nr >= n || nc < 0 || nc >= m) { valid = false; break; }
							if(vis[nr][nc]) { valid = false; break; }
							if(grid[nr][nc] == 'C' || grid[nr][nc] == 'W') { valid = false; break; }
							if(grid[nr][nc] == '.') break;
							vis[nr][nc] = true; 
							switch(grid[nr][nc]) 
							{
								case 'U': nr--; break;
								case 'D': nr++; break;
								case 'L': nc--; break;
								case 'R': nc++; break;
							}
						}
						if(valid) { vis[nr][nc] = true; dis[nr][nc] = dis[cr][cc] + 1; q.add(new Point(nr, nc)); }
					}
				}
			}
		}
		
		for(Point p : end)
		{
			System.out.println(vis[p.r][p.c] ? dis[p.r][p.c] : -1);
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
}