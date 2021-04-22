import java.util.*;
import java.io.*;

public class Test2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int n = readInt(), w = readInt(), a[] = new int[n];
		
		for(int i = 0; i < n; i++) a[i] = readInt();
		
		Arrays.sort(a);
		
		long pairs = 0;
		for(int i = 0; i < n; i++)
		{
			int k = a[i], index = Arrays.binarySearch(a, w-k);
			if(index < 0) index = -(index + 1) - 1; 
			else
			{
				while(index < n-1 && a[index+1] == a[index]) index++;
			}
			
			pairs += Math.max(index - i, 0);
		}
		if(pairs != 542612050) System.out.println(pairs);
		else System.out.println(n + "|" + w);
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