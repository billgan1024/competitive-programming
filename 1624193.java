import java.util.*;
import java.io.*;

public class SurpriseTeleport {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int rows = readInt(), cols = readInt();
		char[][] grid = new char[rows][cols];

		int start_r = readInt(), start_c = readInt(), end_r = readInt(), end_c = readInt();
		
		for(int r = 0; r < rows; r++)
		{
			String s = readLine();
			for(int c = 0; c < cols; c++)
			{
				grid[r][c] = s.charAt(c);
			}
		}
		
		grid[end_r][end_c] = 'E';
		
		int t = readInt();
		for(int i = 0; i < t; i++)
		{
			int r = readInt(), c = readInt();
			grid[r][c] = 'T';
		}
		
		Queue<Integer> queue_r =  new LinkedList<Integer>();
		Queue<Integer> queue_c =  new LinkedList<Integer>();
		
		boolean[][] vis = new boolean[rows][cols];
		int[][] dis = new int[rows][cols];
		
		queue_r.add(start_r);
		queue_c.add(start_c);
		vis[start_r][start_c] = true;
		dis[start_r][start_c] = 0;
		int tpDistance = Integer.MAX_VALUE;
		
		
		while(!queue_r.isEmpty())
		{
			int cur_r = queue_r.remove();
			int cur_c = queue_c.remove();
			
			if(grid[cur_r][cur_c] == 'T') tpDistance = Math.min(tpDistance, dis[cur_r][cur_c]);
			int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
			for(int i = 0; i < dir.length; i++)
			{
				int new_r = cur_r + dir[i][0];
				int new_c = cur_c + dir[i][1];
				
				if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols)
				{
					if(vis[new_r][new_c]) continue;
					if(grid[new_r][new_c] == 'X') continue;
					
					queue_r.add(new_r);
					queue_c.add(new_c);
					vis[new_r][new_c] = true;
					dis[new_r][new_c] = dis[cur_r][cur_c] + 1;
					if(grid[new_r][new_c] == 'T') tpDistance = Math.min(tpDistance, dis[new_r][new_c]);
				}
			}
		}
		
		int walkDistance = dis[end_r][end_c];
		System.out.println(Math.max(walkDistance - tpDistance, 0));
		
		
		
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