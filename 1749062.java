import java.util.*;
import java.io.*;

public class Test2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Computer
	{
		String name; int val;
		public Computer(String name, int val)
		{
			this.name = name; this.val = val;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		Computer[] list = new Computer[n];
		
		for(int i = 0; i < n; i++)
		{
			list[i] = new Computer(next(), 2*readInt() + 3*readInt() + readInt());
		}
		
		if(list.length == 0) return;
		else if(list.length == 1) {System.out.println(list[0].name); return;}
		
		Comparator<Computer> comp = new Comparator<Computer>()
		{
			@Override
			public int compare(Computer arg0, Computer arg1) {
				if(arg0.val == arg1.val) return arg1.name.compareTo(arg0.name);
				else return arg0.val - arg1.val;
			}
		};
		
		Arrays.sort(list, comp);
		
		System.out.println(list[list.length-1].name);
		System.out.println(list[list.length-2].name);

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