import java.util.*;
import java.io.*;

public class SplittingASequence {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, a[], m;

	public static void main(String[] args) throws IOException {
		
		n = readInt(); m = readInt();
		a = new int[n];
		long low = 0, high = 0, ans = 0;
		for(int i = 0; i < n; i++)
		{
			a[i] = readInt();
			high += a[i];
			low = Math.max(low, a[i]); //least maximum subarray sum is the maximum element
			//since each subarray is not empty
		}
		
		while(low <= high)
		{
			long mid = (low + high)/2;
			if(check(mid))
			{
				//<= m # of subarrays, move high down to reduce mid (to increase subarrays)
				ans = mid; high = mid-1;
			}
			else
			{
				low = mid+1; //> than m # of subarrays, move low up to boost mid (to decrease subarrays)
			}
		}
		//will stop at the maximum min subarray sum which has m divisions
		System.out.println(ans);
	}
	
	static boolean check(long x)
	{
		//check how many subarrays will be used with a max number of x;
		//returns true if the number is less than or equal to m (too low # of subarrays)
		//returns false if number is greater than m (too many subarrays)
		int subCount = 0;
		int subSum = 0;
		for(int i = 0; i < n; i++)
		{
			if(subSum + a[i] > x)
			{
				subCount++; subSum = a[i];
			}
			else
			{
				subSum += a[i];
			}
		}
		subCount++; //final one is unfinished
		return subCount <= m;
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
}