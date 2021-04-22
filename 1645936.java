import java.util.*;
import java.io.*;

public class CastleInvasion {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static int lower_bound (int[] arr, int x) {
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

	public static int upper_bound (int[] arr, int x) {
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

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		
		int[] cols = new int[n];
		int[] rows = new int[n];
		
		for(int i = 0; i < n; i++)
		{
			cols[i] = readInt();
		}
		for(int i = 0; i < n; i++)
		{
			rows[i] = readInt();
		}
		
		Arrays.sort(cols);
		Arrays.sort(rows);
		int rowsCaptured = 0, colsCaptured = 0;
		
		int c = 0, r = 0;
		
		long sum = 0;
		
		while(c < n || r < n)
		{
			if(c < n && r < n && cols[c] == rows[r])
			{
				int upper_c = upper_bound(cols, cols[c]), lower_c = lower_bound(cols, cols[c]);
				int colCount = upper_c - lower_c;
				
				int upper_r = upper_bound(rows, rows[r]), lower_r = lower_bound(rows, rows[r]);
				int rowCount = upper_r - lower_r;
				
				//update cols
				if(colsCaptured == n)
				{
					if(rows[n-1] != cols[c])
					{
						System.out.println(-1); return;
					}
				}
				
				sum += (long)(n - colsCaptured) * (long)colCount * (long)cols[c];
				rowsCaptured += colCount;
				
				if(rowsCaptured == n)
				{
					if(cols[n-1] != rows[r])
					{
						System.out.println(-1); return;
					}
				}
				
				sum += (long)(n - rowsCaptured) * (long)rowCount * (long)rows[r];
				colsCaptured += rowCount;
				
				c = upper_c;
				r = upper_r;
				
			}
			else if(r == n || (c < n && cols[c] < rows[r]))
			{
				int upper_c = upper_bound(cols, cols[c]), lower_c = lower_bound(cols, cols[c]);
				int colCount = upper_c - lower_c;
				
				//update cols
				if(colsCaptured == n)
				{
					if(rows[n-1] != cols[c])
					{
						System.out.println(-1); return;
					}
				}
				sum += (long)(n - colsCaptured) * (long)colCount * (long)cols[c];
				rowsCaptured += colCount;
				c = upper_c;
			}
			else if(c == n || (r < n && rows[r] < cols[c]))
			{
				int upper_r = upper_bound(rows, rows[r]), lower_r = lower_bound(rows, rows[r]);
				int rowCount = upper_r - lower_r;
				
				if(rowsCaptured == n)
				{
					if(cols[n-1] != rows[r])
					{
						System.out.println(-1); return;
					}
				}
				
				sum += (long)(n - rowsCaptured) * (long)rowCount * (long)rows[r];
				colsCaptured += rowCount;
				
				r = upper_r;
			}
		}
		
		System.out.println(sum);
		
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