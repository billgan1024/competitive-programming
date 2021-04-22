import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int[] nums;
	
	static void out()
	{
		for(int i : nums) System.out.print(i + " ");
		System.out.println();
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(); 
		int aliceCount = 0, aliceTypes[] = new int[n];
		
		for(int i = 0; i < n; i++) aliceTypes[i] = readInt();
		for(int i = 0; i < n; i++) aliceCount += readInt()*aliceTypes[i];
		
		int m = readInt();
		int carlCount = 0, carlTypes[] = new int[m];
		for(int i = 0; i < m; i++) carlTypes[i] = readInt();
		for(int i = 0; i < m; i++) carlCount += readInt()*carlTypes[i];
		System.out.println(aliceCount + " " + carlCount);
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