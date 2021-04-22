import java.util.*;
import java.io.*;

public class Firehose {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int h, k, houses[];

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		h = readInt(); houses = new int[h];
		for(int i = 0; i < h; i++) {
			houses[i] = readInt();
			//if(houses[i] == 0) houses[i] = 1000000;
		}
		Arrays.sort(houses);
		k = readInt();
		if(k >= h) { System.out.println(0); return; }
		//partition this into k areas 5o that the max (highest+lowest)/2 of each area is minimized
		//the binary search is for the 'span' of each fire hose (distances to houses each one covers)
		//search for optimal span
		int low = 1, high = 1000000/(2*k), ans = 0;
		while(low <= high)
		{
			int mid = (low+high)/2;
			if(check(mid))
			{
				ans = mid; high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		System.out.println(ans);
	}
	
	static boolean check(int span)
	{
		int min = Integer.MAX_VALUE; //current min. # of beacons
		
		for(int i = 0; i < h; i++)
		{
 			int beacons = 0, current = i;
			for(int j = (i+1)%h; j % h != i; j++)
			{
				//if this house is out of range of the current beacon's span, create a new beacon
				if(Math.abs(houses[j%h]-houses[current]) <= 500000)
				{
					if(Math.abs(houses[j%h]-houses[current]) > 2*span)
					{
						current = j % h;
						beacons++;
					}
				}
				else
				{
					if(1000000 - Math.abs(houses[j%h]-houses[current]) > 2*span)
					{
						current = j % h;
						beacons++;
					}
				}
			}
			beacons++;
			min = Math.min(min, beacons);
			if(min <= k) return true;
		}
		return false;
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