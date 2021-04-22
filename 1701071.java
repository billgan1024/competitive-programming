import java.util.*;
import java.io.*;

public class Test2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;


	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int k = readInt();
		ArrayList<Integer> set = new ArrayList<Integer>();
		for(int i = 0; i <= k; i++) set.add(i);
		int m = readInt();
		for(int i = 0; i < m; i++)
		{
			int r = readInt();
			for(int c = r; c < set.size(); c += r)
			{
				set.set(c, -1);
			}
			for(int j = 0; j < set.size(); j++)
			{
				if(set.get(j) == -1)
				{
					set.remove(j); j--;
				}
			}
		}
		for(int i : set) { if(i != 0) System.out.println(i); }
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