import java.util.*;
import java.io.*;

public class Test2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Platform
	{
		int alt, x1, x2;
		public Platform(int alt, int x1, int x2)
		{
			this.alt = alt; this.x1 = x1; this.x2 = x2;
		}
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int l = readInt(), s = readInt();
		if(s <= l) System.out.println("Congratulations, you are within the speed limit!");
		else if(s - l > 0 && s - l <= 20) System.out.println("You are speeding and your fine is $100.");
		else if(s - l > 20 && s - l <= 30) System.out.println("You are speeding and your fine is $270.");
		else System.out.println("You are speeding and your fine is $500.");
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