import java.util.*;
import java.io.*;

public class IceMaze {
	static class Point
	{
		int r, c, dist;
		public Point(int r, int c, int dist)
		{
			this.r = r; this.c = c; this.dist = dist;
		}
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static Comparator<Point> comp = new Comparator<Point>()
	{

		@Override
		public int compare(Point o1, Point o2) {
			// TODO Auto-generated method stub
			return o1.dist - o2.dist;
		}
		
	};
	static PriorityQueue<Point> queue = new PriorityQueue<Point>(comp);
	static int n = 10;
	static int[] loc_r = new int[6], loc_c = new int[6];
	static int[][] dis = new int[n][n];
	static char[][] grid = new char[n][n];
	
	static void bfs(char cur)
	{
		if(cur == 'F') return; dis = new int[n][n];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) dis[i][j] = Integer.MAX_VALUE;
		}
		dis[loc_r[cur-'A']][loc_c[cur-'A']] = 0;
		char target = (char)((int)cur+1);
		while(!queue.isEmpty())
		{
			Point p = queue.remove();
			int cur_r = p.r, cur_c = p.c;
			if(dis[cur_r][cur_c] < p.dist) continue;
			int[][] dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
			
			for(int i = 0; i < 4; i++)
			{
				int dist = 0;
				int new_r = cur_r + dir[i][0], new_c = cur_c + dir[i][1];
				while(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n && grid[new_r][new_c] != '#')
				{
					dist++;
					new_r += dir[i][0]; new_c += dir[i][1];
				}
				
				int final_r = cur_r + dir[i][0]*dist, final_c = cur_c+dir[i][1]*dist;
				if(dis[final_r][final_c] > dis[cur_r][cur_c] + dist)
				{
					dis[final_r][final_c] = dis[cur_r][cur_c] + dist;
					if(final_r != loc_r[target-'A'] || final_c != loc_c[target-'A'])
					{
						queue.add(new Point(final_r, final_c, dis[final_r][final_c]));
					}
				}
			}
		}
		System.out.println(dis[loc_r[target-'A']][loc_c[target-'A']]);
		queue = new PriorityQueue<Point>(comp);
		
		//add the next character's starting point and call it again
		queue.add(new Point(loc_r[target-'A'], loc_c[target-'A'], 0));
		bfs(target);
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		for(int r = 0; r < n; r++)
		{
			String s = readLine();
			for(int c = 0; c < n; c++) {
				grid[r][c] = s.charAt(c); 
				if(grid[r][c] != '.' && grid[r][c] != '#') {
					loc_r[grid[r][c]-'A'] = r; loc_c[grid[r][c]-'A'] = c;
				}
			}
		}
		queue.add(new Point(loc_r[0], loc_c[0], 0));
		bfs('A');
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