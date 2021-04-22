import java.util.*;
import java.io.*;

public class FarthestHiking {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int m = readInt(), n = readInt(), u = readInt(), f = readInt(), d = readInt();
		
		int count = 0;
		String s = readLine();
		for(int i = 0; i < n; i++)
		{
			if(s.charAt(i) == 'u' || s.charAt(i) == 'd')
			{
				count += u; count += d;
			}
			else count += 2 * f;
			if(count == m)
			{
				System.out.println(i + 1); return;
			}
			else if(count > m)
			{
				System.out.println(i); return;
			}
		}
		
		System.out.println(n);

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