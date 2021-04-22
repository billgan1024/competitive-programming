import java.util.*;
import java.io.*;

public class ContestOfficial4 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		for(int test = 0; test < 5; test++)
		{
			int[][] grid = new int[10][10];
			
			for(int i = 0; i < 10; i++)
			{
				String s = readLine();
				for(int j = 0; j < 10; j++)
				{
					grid[i][j] = Character.getNumericValue(s.charAt(j));
				}
			}
			
			int minDistance = Integer.MAX_VALUE;
			
			for(int i = 0; i < 10; i++)
			{
				Queue<Integer> queue_r = new LinkedList<Integer>();
				Queue<Integer> queue_c = new LinkedList<Integer>();
				
				int[][] dis = new int[10][10];
				boolean[][] vis = new boolean[10][10]; 
				
				queue_r.add(i);
				queue_c.add(0);
				vis[i][0] = true;
				boolean found = false;
				
				while(!queue_r.isEmpty() && !found)
				{
					int cur_r = queue_r.remove(), cur_c = queue_c.remove();
					int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
					
					for(int j = 0; j < dir.length; j++)
					{
						int new_r = cur_r + dir[j][0];
						int new_c = cur_c + dir[j][1];
						
						if(new_r >= 0 && new_r < 10 && new_c >= 0 && new_c < 10)
						{
							if(vis[new_r][new_c]) continue;
							if(Math.abs(grid[new_r][new_c] - grid[cur_r][cur_c]) > 1) continue;
							vis[new_r][new_c] = true;
							dis[new_r][new_c] = dis[cur_r][cur_c] + 1;
							
							if(new_c == 9)
							{
								minDistance = Math.min(minDistance, dis[new_r][new_c]);
								found = true;
								break;
							}
							
							queue_r.add(new_r);
							queue_c.add(new_c);
						}
					}
				}
			}
			
			if(minDistance == Integer.MAX_VALUE) System.out.println("IMPOSSIBLE");
			else System.out.println(minDistance);
			
			String next = readLine();
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