import java.util.*;
import java.io.*;

public class Test2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static boolean isPrime(int n)
	{
		if(n == 2 || n == 5) return true;
		int last = n % 10;
		if(last == 2 || last == 5 || last == 0 || n == 1) return false;
		int limit = (int) Math.sqrt(n); //limit is floor of sqrt(n)
		
		for(int x = 2; x <= limit; x++) //loop from 2 
		{
			if(n % x == 0)
			{
				return false;
			}
		}
		return true;
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int n = readInt();
		boolean[][] grid = new boolean[2001][2001];
		int r = 1000, c = 1000; grid[r][c] = true;
		for(int i = 1; i <= n; i++)
		{
			char ch = next().charAt(0);
			switch(ch)
			{
			case 'L':
				c--; break;
			case 'R':
				c++; break;
			case 'U':
				r--; break;
			case 'D':
				r++; break;
			}
			if(grid[r][c]) {
				System.out.println("Fell at " + i); return;
			}
			grid[r][c] = true;
		}
		System.out.println("Safe!");
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