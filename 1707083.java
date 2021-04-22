import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		for(int count = 0; count < 5; count++)
		{
			int r = readInt(), c = readInt();
			char[][] grid = new char[r][c];
			for(int i = 0; i < r; i++)
			{
				String s = readLine();
				for(int j = 0; j < c; j++) grid[i][j] = s.charAt(j);
			}
			String query = readLine();
			int target = 0;
			
			char[][] soln = new char[r][c];
			for(int i = 0; i < r; i++)
			{
				for(int j = 0; j < c; j++)
				{
					if(target < query.length() && grid[i][j] == query.charAt(target))
					{
						target++;
						soln[i][j] = '.';
					}
					else
					{
						soln[i][j] = '#';
					}
				}
			}
			
			if(target == query.length())
			{
				for(int i = 0; i < r; i++)
				{
					for(int j = 0; j < c; j++) System.out.print(soln[i][j]);
					System.out.println();
				}
			}
			else
			{
				for(int i = 0; i < r; i++)
				{
					for(int j = 0; j < c; j++) System.out.print('x');
					System.out.println();
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