import java.util.*;
import java.io.*;

public class Dodgeball {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Distance
	{
		int d, l, r;
		public Distance(int d, int l, int r)
		{
			this.d = d; this.l = l; this.r = r;
		}
		public Distance(Distance dis)
		{
			this.d = dis.d; this.l = dis.l; this.r = dis.r;
		}
	}

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		char[][] grid = new char[n][n];
		
		for(int r = 0; r < n; r++)
		{
			String s = readLine();
			for(int c = 0; c < n; c++)
			{
				grid[r][c] = s.charAt(c);
			}
		}
		
		Queue<Integer> queue_r = new LinkedList<Integer>();
		Queue<Integer> queue_c = new LinkedList<Integer>();
		boolean[][] vis = new boolean[n][n];
		Distance[][] dis = new Distance[n][n];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				dis[i][j] = new Distance(0, 0, 0);
			}
		}
		
		queue_r.add(0);
		queue_c.add(0);
		vis[0][0] = true;
		
		while(!queue_r.isEmpty())
		{
			int cur_r = queue_r.remove(), cur_c = queue_c.remove();
			int[][] dir = {{1, 0}, {0, -1}, {0, 1}};
			for(int i = 0; i < dir.length; i++)
			{
				int new_r = cur_r + dir[i][0];
				int new_c = cur_c + dir[i][1];
				
				if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n)
				{
					if(vis[new_r][new_c]) continue;
					if(grid[new_r][new_c] == '#') continue;
					vis[new_r][new_c] = true;
					dis[new_r][new_c] = new Distance(dis[cur_r][cur_c]);
					switch(i)
					{
						case 0: dis[new_r][new_c].d++;
						break;
						case 1: dis[new_r][new_c].l++;
						break;
						case 2: dis[new_r][new_c].r++;
						break;
					}
					queue_r.add(new_r);
					queue_c.add(new_c);
				}
			}
		}
		
		if(!vis[n-1][n-1]) System.out.println(-1);
		else System.out.println((long)(Math.pow(dis[n-1][n-1].d, 2) 
				+ Math.pow(dis[n-1][n-1].l, 2) + Math.pow(dis[n-1][n-1].r, 2)));
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