import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		for(int count = 0; count < 5; count++)
		{
			char[][] grid = new char[10][10];
			int start_r = -1, start_c = -1;
			for(int i = 0; i < 10; i++)
			{
				String s = readLine();
				for(int j = 0; j < 10; j++)
				{
					grid[i][j] = s.charAt(j);
					if(grid[i][j] == 'X')
					{
						start_r = i; start_c = j;
					}
				}
			}
			Queue<Integer> queue_r = new LinkedList<Integer>();
			Queue<Integer> queue_c = new LinkedList<Integer>();
			
			boolean[][] vis = new boolean[10][10];
			int[][] dis = new int[10][10];
			
			queue_r.add(start_r);
			queue_c.add(start_c);
			vis[start_r][start_c] = true;
			boolean flag = false;
			
			while(!queue_r.isEmpty())
			{
				if(flag) break;
				int cur_r = queue_r.remove();
				int cur_c = queue_c.remove();
				
				int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
				
				for(int j = 0; j < dir.length; j++)
				{
					int new_r = cur_r + dir[j][0];
					int new_c = cur_c + dir[j][1];
					
					if(new_r >= 0 && new_r < 10 && new_c >= 0 && new_c < 10)
					{
						if(vis[new_r][new_c]) continue;
						if(grid[new_r][new_c] == '#') continue;
						vis[new_r][new_c] = true;
						dis[new_r][new_c] = dis[cur_r][cur_c] + 1;
						if(grid[new_r][new_c] == 'X')
						{
							System.out.println(dis[new_r][new_c]); flag = true;
							break;
						}
						queue_r.add(new_r); queue_c.add(new_c);
						
					}
				}
			}
			
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

	public static int lower_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] >= x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}

	public static int upper_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] > x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}
}