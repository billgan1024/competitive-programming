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
		int[] carLocations = new int[n], carSpeeds = new int[n];
		int currentLocation = 0, currentSpeed = 1;
		double totalTime = 0;
		for(int i = 0; i < n; i++)
		{
			carLocations[i] = readInt();
			carSpeeds[i] = readInt();
			int distance = Math.max(currentLocation - carLocations[i], 0);
			double time = (double) distance / (double) currentSpeed;
			totalTime += time;
			
			currentLocation = carLocations[i];
			
			currentSpeed = Math.max(currentSpeed, carSpeeds[i]);
		}
		
		int distance = currentLocation;
		double time = (double) distance / (double) currentSpeed;
		totalTime += time;
		System.out.println(totalTime);
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