import java.util.*;
import java.io.*;

public class BloodDistribution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int[] avail = new int[8], need = new int[8];
	static int total = 0;
	
	public static void drain(int availIndex, int needIndex)
	{
		int original = avail[availIndex];
		avail[availIndex] = Math.max(avail[availIndex] - need[needIndex], 0);
		need[needIndex] -= original - avail[availIndex];
		total += original - avail[availIndex];
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		for(int i = 0; i < 8; i++) avail[i] = readInt();
		for(int i = 0; i < 8; i++) need[i] = readInt();
		
		//0 = O-, 1 = O+, 2 = A-, 3 = A+, 4 = B-, 5 = B+, 6 = AB-, 7 = AB+
		drain(0, 0);
		
		//get all o-positive
		drain(1, 1);
		drain(0, 1);
		
		//get all a-negative
		drain(2, 2);
		drain(0, 2);
		
		//get all a-positive
		drain(3, 3); drain(2, 3); drain(1, 3); drain(0, 3);
		
		//get all b-negative
		drain(4, 4);
		drain(0, 4);
		
		//get all b-positive
		drain(5, 5); drain(4, 5); drain(1, 5); drain(0, 5);
		
		//get all ab-negative
		drain(6, 6); drain(4, 6); drain(2, 6); drain(0, 6);
		
		//get all ab-positive
		for(int i = 0; i < 8; i++)
		{
			drain(8-i-1, 7);
		}
		System.out.println(total);
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