import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int r = readInt(), c = readInt();
		char[][] grid = new char[r][c];
		
		for(int i = 0; i < r; i++)
		{
			String s = readLine();
			for(int j = 0; j < c; j++) grid[i][j] = s.charAt(j);
		}
		
		int safe = 0;
		for(int cur_r = 0; cur_r < r; cur_r++)
		{
			for(int cur_c = 0; cur_c < c; cur_c++)
			{
				if(grid[cur_r][cur_c] == 'S') continue;
				int snakes = 0, adj = 0;
				int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
						{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
				for(int i = 0; i < 8; i++)
				{
					int new_r = cur_r + dir[i][0], new_c = cur_c + dir[i][1];
					if(new_r >= 0 && new_r < r && new_c >= 0 && new_c < c)
					{
						adj++;
						if(grid[new_r][new_c] == 'S') snakes++;
					}
				}
				if((double)snakes/(double)adj < 0.5) safe++;
			}
		}
		
		System.out.println(safe);
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