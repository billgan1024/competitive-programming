import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int[] nums;
	
	static char[][] grid = new char[8][8];
	static int max = 0;
	
	static void findMax(int cur_r, int cur_c, int val)
	{
		if(cur_r == 0 && cur_c == 7)
		{
			max = Math.max(max, val);
		}
		else
		{
			//scan up and right square, if it isn't a wall, pick up any loot and call this function again
			int[][] dir = {{-1, 0}, {0, 1}};
			for(int i = 0; i < 2; i++)
			{
				int new_r = cur_r + dir[i][0], new_c = cur_c + dir[i][1];
				if(new_r >= 0 && new_c < 8)
				{
					if(grid[new_r][new_c] == '#') continue;
					int pickup = 0;
					if(grid[new_r][new_c] != '.') pickup += Character.getNumericValue(grid[new_r][new_c]);
					
					findMax(new_r, new_c, val + pickup);
				}
			}
		}
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		for(int i = 0; i < 5; i++)
		{
			for(int r = 0; r < 8; r++)
			{
				String s = readLine();
				for(int c = 0; c < 8; c++) grid[r][c] = s.charAt(c);
			}
			int pickup = 0;
			if(grid[7][0] != '.') pickup += Character.getNumericValue(grid[7][0]);
			findMax(7, 0, pickup);
			System.out.println(max); max = 0;
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