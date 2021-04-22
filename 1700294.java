import java.util.*;
import java.io.*;

public class Test2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static long evaluate(long[] poly, long x)
	{
		long res = 0;
		for(int i = 0; i < poly.length; i++)
		{
			res += poly[i] * Math.pow(x, poly.length-1-i);
		}
		return res;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int q = readInt();
		
		for(int c = 0; c < q; c++)
		{
			int n = readInt();
			long[] poly = new long[n+1];
			poly[n] = 1;
			
			for(int r = 0; r < n; r++)
			{
				int root = -readInt();
				long[] temp = Arrays.copyOf(poly, n+1);
				//multiply all terms by 'x'
				for(int i = 1; i < n+1; i++)
				{
					temp[i-1] = temp[i];
				}
				temp[n] = 0;
				
				for(int i = 0; i < n+1; i++)
				{
					long term = poly[i] * root;
					temp[i] += term;
				}
				
				poly = temp;
			}
			long x = readLong(), y = readLong();
			
			long xx = evaluate(poly, x);
			long a = y/xx;
			
			for(int i = 0; i < n+1; i++) System.out.print((poly[i]*a) + " ");
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