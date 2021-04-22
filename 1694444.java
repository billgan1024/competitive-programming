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
		nums = new int[n];
		for(int i = 0; i < n; i++)
		{
			nums[i] = readInt();
			System.out.print(nums[i] + " ");
		}
		System.out.println();
		
		boolean swapped = false;
		while(true)
		{
			swapped = false;
			for(int i = 1; i < n; i++)
			{
				if(nums[i] < nums[i-1])
				{
					int temp = nums[i]; nums[i] = nums[i-1]; nums[i-1] = temp;
					out();
					swapped = true;
				}
			}
			if(!swapped) break;
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