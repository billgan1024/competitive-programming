import java.util.*;
import java.io.*;

public class Gates {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int g = readInt(), p = readInt();
		TreeSet<Integer> gates = new TreeSet<Integer>();
		for(int i = 0; i < g; i++)
		{
			gates.add(i);
		}
		
		int count = 0;
		for(int i = 0; i < p; i++)
		{
			int target = readInt()-1;
			Integer element = gates.floor(target);
			if(element != null)
			{
				gates.remove(element);
				count++;
			}
			else
			{
				System.out.println(count);
				return;
			}
		}
		
		System.out.println(count);

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