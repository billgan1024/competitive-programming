import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		int[] nums = new int[n];
		for(int i = 0; i < n; i++)
		{
			nums[i] = readInt();
		}
		Arrays.sort(nums);
		
		int medianIndex = (n-1)/2;
		double median = 0;
		if(n % 2 == 1) {
			median = nums[medianIndex];
			int[] bottom = Arrays.copyOfRange(nums, 0, medianIndex);
			int[] top = Arrays.copyOfRange(nums, medianIndex + 1, n);
			
			int q1index = (bottom.length-1)/2;
			double q1 = 0;
			if(bottom.length % 2 == 1) 
			{
				q1 = bottom[q1index];
			}
			else
			{
				q1 = (double)(bottom[q1index] + bottom[q1index+1])/2.0;
			}
			
			int q3index = (top.length-1)/2;
			double q3 = 0;
			if(top.length % 2 == 1) 
			{
				q3 = top[q3index];
			}
			else
			{
				q3 = (double)(top[q3index] + top[q3index+1])/2.0;
			}
			System.out.println(nums[0] + " " + nums[nums.length-1] + " " + q1 + " " + median + " " + q3);
		}
		else {
			median = (double)(nums[medianIndex] + nums[medianIndex+1])/2.0;
			int[] bottom = Arrays.copyOfRange(nums, 0, medianIndex+1);
			int[] top = Arrays.copyOfRange(nums, medianIndex + 1, n);
			
			int q1index = (bottom.length-1)/2;
			double q1 = 0;
			if(bottom.length % 2 == 1) 
			{
				q1 = bottom[q1index];
			}
			else
			{
				q1 = (double)(bottom[q1index] + bottom[q1index+1])/2.0;
			}
			
			int q3index = (top.length-1)/2;
			double q3 = 0;
			if(top.length % 2 == 1) 
			{
				q3 = top[q3index];
			}
			else
			{
				q3 = (double)(top[q3index] + top[q3index+1])/2.0;
			}
			
			System.out.println(nums[0] + " " + nums[nums.length-1] + " " + q1 + " " + median + " " + q3);
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