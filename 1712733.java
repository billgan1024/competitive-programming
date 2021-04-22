import java.util.*;
import java.io.*;

public class AnimeConventions {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int[] set;
	
	static int find(int n)
	{
		int r = n;
		while(set[r] != 0)
		{
			r = set[r];
		}
		for(int c = n; c != r; c = set[c])
		{
			set[c] = r;
		}
		return r;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), q = readInt();
		set = new int[n+1];
		for(int i = 0; i < q; i++)
		{
			char cmd = next().charAt(0);
			if(cmd == 'A')
			{
				int x = readInt(), y = readInt(), fx = find(x), fy = find(y);
				if(fx != fy) set[fx] = fy;
			}
			else
			{
				int x = readInt(), y = readInt(), fx = find(x), fy = find(y);
				System.out.println(fx == fy ? "Y" : "N");
			}
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