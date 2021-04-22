import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int c = readInt(), r = readInt(), t = readInt();
		char[][] grid = new char[r][c];
		
		int cur_r = -1, cur_c = -1;
		for(int i = 0; i < r; i++)
		{
			String s = readLine();
			for(int j = 0; j < c; j++)
			{
				grid[i][j] = s.charAt(j);
				if(grid[i][j] == 'O')
				{
					cur_r = i; cur_c = j;
				}
			}
		}
		
		int time = 0, dir_r = 0, dir_c = 1;
		while(true)
		{
			time++;
			cur_r += dir_r; cur_c += dir_c;
			if(cur_r < 0 || cur_r >= r || cur_c < 0 || cur_c >= c)
			{
				System.out.println("The observer leaves the grid after " + time + " tick(s)."); break;
			}
			if(time == t)
			{
				System.out.println("The observer stays within the grid."); break;
			}
			
			if(grid[cur_r][cur_c] != '.' && grid[cur_r][cur_c] != 'O')
			{
				if(dir_r == 0)
				{
					if(grid[cur_r][cur_c] == '|')
					{
						dir_c *= -1; grid[cur_r][cur_c] = '-';
					}
					else if(grid[cur_r][cur_c] == '/')
					{
						if(dir_c == 1) dir_r = -1;
						else if(dir_c == -1) dir_r = 1;
						grid[cur_r][cur_c] = '\\';
						dir_c = 0;
					}
					else if(grid[cur_r][cur_c] == '\\')
					{
						if(dir_c == 1) dir_r = 1;
						else if(dir_c == -1) dir_r = -1;
						grid[cur_r][cur_c] = '/';
						dir_c = 0;
					}
				}
				else if(dir_c == 0)
				{
					if(grid[cur_r][cur_c] == '-')
					{
						dir_r *= -1; grid[cur_r][cur_c] = '|';
					}
					else if(grid[cur_r][cur_c] == '/')
					{
						if(dir_r == 1) dir_c = -1;
						else if(dir_r == -1) dir_c = 1;
						grid[cur_r][cur_c] = '\\';
						dir_r = 0;
					}
					else if(grid[cur_r][cur_c] == '\\')
					{
						if(dir_r == 1) dir_c = 1;
						else if(dir_r == -1) dir_c = -1;
						grid[cur_r][cur_c] = '/';
						dir_r = 0;
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