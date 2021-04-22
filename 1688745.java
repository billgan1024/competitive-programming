import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Integer>[] adj;
	static ArrayList<Integer> currentPath = new ArrayList<Integer>();
	static boolean exists = false;
	static boolean[] vis;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		String s = readLine();
		int k = readInt();
		ArrayList<String> subs = new ArrayList<String>();
		for(int i = 0; i < s.length()-k; i++)
		{
			subs.add(s.substring(i, i+k));
		}
		Collections.sort(subs);
		System.out.println(subs.get(0));
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