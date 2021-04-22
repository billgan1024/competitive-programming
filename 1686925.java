import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), k = readInt(), q = readInt();
		int[] nums = new int[n+1];
		int[] pre = new int[n+1];
		TreeSet<Integer>[] occurrences = new TreeSet[2002];
		for(int i = 0; i < occurrences.length; i++)
		{
			occurrences[i] = new TreeSet<Integer>();
		}
		
		for(int i = 1; i <= n; i++)
		{
			nums[i] = readInt();
			occurrences[nums[i]+1000].add(i);
			pre[i] = nums[i] + pre[i-1];
		}
		
		for(int i = 0; i < q; i++)
		{
			int a = readInt(), b = readInt(), x = readInt(), y = readInt();
			if(pre[y] - pre[x-1] <= k)
			{
				System.out.println("No"); continue;
			}
			Integer a1 = occurrences[a+1000].ceiling(x);
			if(a1 == null || a1 > y)
			{
				System.out.println("No"); continue;
			}
			
			Integer b1 = occurrences[b+1000].ceiling(x);
			if(b1 == null || b1 > y)
			{
				System.out.println("No"); continue;
			}
			System.out.println("Yes");
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