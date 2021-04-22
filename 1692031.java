import java.util.*;
import java.io.*;

public class BigDeposits {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		long p = readLong();
		int y = readInt();
		long t = readLong();
		
		long low = 1, high = t, ans = 0;
		
		while(low <= high)
		{
			long mid = (low+high)/2;
			
			long count = 0;
			for(int i = 0; i < y; i++)
			{
				count += mid;
				count += (p * count) / 100;
				if(count >= t) break;
			}
			if(count >= t) {ans = mid; high = mid-1;} //this will terminate with ans = the optimal answer when high and low overlap
			else low = mid + 1;
		}
		
		System.out.println(ans);
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
	
	static float readFloat() throws IOException {
		return Float.parseFloat(next());
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