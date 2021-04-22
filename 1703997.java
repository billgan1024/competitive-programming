import java.util.*;
import java.io.*;

public class LargestMinDistance {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n, m, seats[];

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		n = readInt(); m = readInt();
		
		seats = new int[n];
		for(int i = 0; i < n; i++) seats[i] = readInt();
		Arrays.sort(seats);
		
		int low = 1, high = seats[n-1] - seats[0];
		int ans = 0;
		//binary search for the maximum possible MINimum distance
		//(since we are trying to maximize the distance between any two students
		//min distance is 1, max distance = furthest seat - closest seat
		
		//when not enough students fit, cut the upper bound in half to reduce the distance
		//allowing more students
		//when all students fit, increase the lower bound to increase the distance
		//because we want to maximize this distance between any two students
		//the loop will then terminate when the distance between any two students
		//is maximized while still allowing all the students to sit
		while(low <= high)
		{
			int mid = (low+high)/2;
			if(check(mid))
			{
				ans = mid; low = mid+1;
			}
			else
			{
				high = mid-1;
			}
		}
		
		System.out.println(ans);
		
	}
	
	static boolean check(int dis)
	{
		//returns true if the # of students that can fit is >= than # of students
		//false otherwise
		int seated = 1, cur = seats[0];
		for(int i = 1; i < n; i++)
		{
			if(seats[i] - cur >= dis)
			{
				seated++; cur = seats[i];
			}
		}
		return seated >= m;
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