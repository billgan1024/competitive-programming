import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int[] nums;
	
	static class Box
	{
		int l, w, h; //l = length, w = width; h = height
		long vol;
		public Box(int l, int w, int h)
		{
			//instantiates a box with specified dimensions
			this.l = l; this.w = w; this.h = h;
			vol = (long)l * (long) w * (long) h;
		}
	}

	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		String[] s = readLine().split(" ");
		int op = 0; //1 is add, 2 is sub
		int res = 0;
		for(String c : s)
		{
			if(c.equals("P")) op = 1;
			else if(c.equals("M")) op = 2;
			else if(c.equals("=")) break;
			else
			{
				if(op == 0 || op == 1)
				{
					res += Integer.parseInt(c);
				}
				else
				{
					res -= Integer.parseInt(c);
				}
				op = 0;
			}
		}
		System.out.println(res);
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