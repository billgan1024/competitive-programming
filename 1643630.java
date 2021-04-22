import java.util.*;
import java.io.*;

public class HiTideLoTide {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		
		int rows = readInt(), cols = readInt();
		char[][] grid = new char[rows][cols];
		for(int r = 0; r < rows; r++)
		{
			String s = readLine();
			for(int c = 0; c < cols; c++) 
			{
				grid[r][c] = s.charAt(c);
			}
		}
		
		boolean[][] vis = new boolean[rows][cols];
		Queue<Integer> queue_r = new LinkedList<Integer>();
		Queue<Integer> queue_c = new LinkedList<Integer>();
		int treasures = 0;
		
		for(int r = 0; r < rows; r++)
		{
			for(int c = 0; c < cols; c++)
			{
				if(vis[r][c]) continue;
				if(grid[r][c] == 'X') continue;
				treasures++;
				vis[r][c] = true;
				queue_r.add(r);
				queue_c.add(c);
				
				while(!queue_r.isEmpty())
				{
					int current_r = queue_r.remove();
					int current_c = queue_c.remove();
					
					int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
					
					for(int j = 0; j < dir.length; j++)
					{
						int new_r = current_r + dir[j][0];
						int new_c = current_c + dir[j][1];
						
						if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols)
						{
							if(vis[new_r][new_c]) continue;
							if(grid[new_r][new_c] == 'X') continue;
 							vis[new_r][new_c] = true;
							queue_r.add(new_r);
							queue_c.add(new_c);
						}
					}
				}
			}
		}
		System.out.println(treasures);
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