import java.util.*;
import java.io.*;

public class MountainPassage {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int trips = readInt();
		
		for(int x = 0; x < trips; x++)
		{
			int n = readInt();
			int[][] grid = new int[n][n];
			
			for(int r = 0; r < n; r++)
			{
				for(int c = 0; c < n; c++)
				{
					grid[r][c] = readInt();
				}
			}
			
			int startHeight = grid[0][0];
			
			Queue<Integer> queue_r = new LinkedList<Integer>();
			Queue<Integer> queue_c = new LinkedList<Integer>();
			
			boolean[][] visited = new boolean[n][n];
			int[][] oxygen = new int[n][n];
			
			queue_r.add(0);
			queue_c.add(0);
			visited[0][0] = true;
			oxygen[0][0] = 0;
			
			while(!queue_r.isEmpty())
			{
				int cur_r = queue_r.remove();
				int cur_c = queue_c.remove();
				
				int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
				
				for(int i = 0; i < dir.length; i++)
				{
					int new_r = cur_r + dir[i][0];
					int new_c = cur_c + dir[i][1];
					
					if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n)
					{
						if(visited[new_r][new_c]) continue;
						if(Math.abs(grid[new_r][new_c] - grid[cur_r][cur_c]) > 2) continue;
						
						//add this new node
						queue_r.add(new_r);
						queue_c.add(new_c);
						visited[new_r][new_c] = true;
						if(grid[cur_r][cur_c] > startHeight || grid[new_r][new_c] > startHeight)
						{
							oxygen[new_r][new_c] = oxygen[cur_r][cur_c] + 1;
						}
						else
						{
							oxygen[new_r][new_c] = oxygen[cur_r][cur_c];
						}
					}
				}
			}
			
			if(visited[n-1][n-1])
			{
				System.out.println(oxygen[n-1][n-1]);
				if(x < trips-1) System.out.println("");
			}
			else
			{
				System.out.println("CANNOT MAKE THE TRIP");
				if(x < trips-1) System.out.println("");
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