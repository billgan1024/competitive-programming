import java.util.*;
import java.io.*;

public class ForestFires {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		for(int count = 0; count < 5; count++)
		{
			char[][] grid = new char[10][10];
			
			ArrayList<Integer> fire_r = new ArrayList<Integer>();
			ArrayList<Integer> fire_c = new ArrayList<Integer>();
			
			for(int r = 0; r < 10; r++)
			{
				String s = readLine();
				for(int c = 0; c < 10; c++)
				{
					grid[r][c] = s.charAt(c);
					if(grid[r][c] == 'F')
					{
						fire_r.add(r); fire_c.add(c);
					}
				}
			}
			
			Queue<Integer> queue_r = new LinkedList<Integer>();
			Queue<Integer> queue_c = new LinkedList<Integer>();
			boolean[][] vis = new boolean[10][10];
			int[][] dis = new int[10][10];
			//Arrays.fill(dis, new int[] {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1});
			
			for(int i = 0; i < fire_r.size(); i++)
			{
				queue_r.add(fire_r.get(i));
				queue_c.add(fire_c.get(i));
				vis[fire_r.get(i)][fire_c.get(i)] = true;
			}
			
			while(!queue_r.isEmpty())
			{
				int cur_r = queue_r.remove(), cur_c = queue_c.remove();
				int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
				
				for(int i = 0; i < dir.length; i++)
				{
					int new_r = cur_r + dir[i][0];
					int new_c = cur_c + dir[i][1];
					
					if(new_r >= 0 && new_r < 10 && new_c >= 0 && new_c < 10)
					{
						if(vis[new_r][new_c]) continue;
						if(grid[new_r][new_c] == '.') continue;
						
						vis[new_r][new_c] = true;
						dis[new_r][new_c] = dis[cur_r][cur_c] + 1;
						queue_r.add(new_r);
						queue_c.add(new_c);
					}
				}
			}
			
			int maxTime = Integer.MIN_VALUE;
			for(int r = 0; r < 10; r++)
			{
				if(maxTime == -1) break;
				for(int c = 0; c < 10; c++)
				{
					if(grid[r][c] == 'T')
					{
						if(!vis[r][c])
						{
							maxTime = -1;
							break;
						}
						else maxTime = Math.max(maxTime, dis[r][c]);
					}
				}
			}
			
			System.out.println(maxTime);
			
			String bruh = readLine();
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