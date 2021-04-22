import java.util.*;
import java.io.*;

public class AnArrayProblen {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		
		//get max num and total sum
		//if the rest is greater than the max num, print the TOTAL sum / 2 (floored)
		//otherwise, print rest
		
		int[] nums = new int[n];
		int maxNum = 0;
		long sum = 0;
		for(int i = 0; i < n; i++)
		{
			nums[i] = readInt();
			maxNum = Math.max(maxNum, nums[i]);
			sum += nums[i];
		}
		
		if(sum - maxNum >= maxNum)
		{
			System.out.println(sum/2);
		}
		else
		{
			System.out.println(sum - maxNum);
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
}