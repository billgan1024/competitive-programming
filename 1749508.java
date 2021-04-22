import java.util.*;
import java.io.*;

public class BridgeTransport {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int w = readInt(), n = readInt();
		long a[] = new long[n+1], sum[] = new long[n+1];
		
		for(int i = 1; i <= n; i++)
		{
			a[i] = readLong(); sum[i] = sum[i-1] + a[i];
		}
		if(sum[1] > w) {
			System.out.println(0); return;
		}else if(sum[2] > w){
			System.out.println(1); return;
		}
		else if(sum[3] > w) {
			System.out.println(2); return;
		}
		
		for(int i = 4; i <= n; i++)
		{
			long section = sum[i]-sum[i-4];
			if(section > w) {
				System.out.println(i-1); return;
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