import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static char[][] grid;
	static boolean found;
	static boolean[][] vis;
	static int n;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		n = readInt();
		int q = readInt();
		grid = new char[n][n];
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				grid[i][j] = next().charAt(0);
			}
		}
		
		for(int i = 0; i < q; i++)
		{
			found = false;
			String query = readLine();
			
			for(int r = 0; r < n; r++)
			{
				for(int c = 0; c < n; c++)
				{
					if(grid[r][c] == query.charAt(0))
					{
						vis = new boolean[n][n];
						vis[r][c] = true;
						find(query, 0, r, c);
					}
				}
			}
			
			if(found) System.out.println("good puzzle!");
			else System.out.println("bad puzzle!");
		}
	}
	
	//finds the next character based on the current index, current row and current column
	public static void find(String query, int index, int cur_r, int cur_c)
	{
		if(found) return;
		//base case
		if(index + 1 == query.length())
		{
			found = true;
		}
		else
		{
			char toSearch = query.charAt(index + 1);
			int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
			
			for(int i = 0; i < 8; i++)
			{
				int new_r = cur_r + dir[i][0];
				int new_c = cur_c + dir[i][1];
				
				if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n)
				{
					if(vis[new_r][new_c]) continue;
					if(grid[new_r][new_c] == toSearch)
					{
						vis[new_r][new_c] = true;
						find(query, index + 1, new_r, new_c);
					}
				}
			}
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