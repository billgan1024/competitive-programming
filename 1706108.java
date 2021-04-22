import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		while(true)
		{
			int n = readInt(); if(n == 0) break;
			
			int count = 0;
			for(int i = n; i >= 0; i--)
			{
				int notin = 0;
				//binary search for j
				int low = 0, high = n, ans = 0;
				while(low <= high)
				{
					int mid = (low+high)/2;
					if(Math.sqrt(Math.pow(i, 2) + Math.pow(mid, 2)) <= n)
					{
						ans = mid; low = mid+1;
					}
					else
					{
						high = mid-1;
					}
				}
				notin = n - ans;
				count += 2*n + 1 - 2*notin;
			}
			System.out.println(2*count - 2*n - 1);
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