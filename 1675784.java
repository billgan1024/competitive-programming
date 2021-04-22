import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		char[][] grid = new char[n][n];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				grid[i][j] = '*';
			}
		}
		
		int mid = n/2;
		int width = 0;
		int direction = 1;
		for(int i = 1; i < n-1; i++)
		{
			for(int j = mid-width; j <= mid+width; j++)
			{
				grid[i][j] = ' ';
			}
			width += direction;
			if(width == n/2-1) direction = -1;
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				System.out.print(grid[i][j]);
			}
			System.out.println();
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