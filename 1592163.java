import java.util.*;
import java.io.*;

public class Sorting {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		int[] nums = new int[n];
		
		int lastVal = 1;
		int minVal = 1;
		
		
		for(int i = 0; i < n; i++)
		{
			nums[i] = readInt();
			if(nums[i] != 0) lastVal = nums[i];
			else minVal = lastVal;
			
			if(i > 0 && nums[i] != 0 && nums[i] < lastVal)
			{
				System.out.println("NO"); return;
			}
		}
		
		//simulate setting all zeroes to the minumum value 
		//(value of the element before the last zero)
		for(int i = 0; i < nums.length; i++)
		{
			if(nums[i] == 0) {
				nums[i] = minVal;
			}
		}
		//check if list is sorted
		for(int i = 1; i < nums.length; i++)
		{
			if(nums[i] < nums[i-1]) 
			{
				System.out.println("NO"); return;
			}
		}
		System.out.println("YES");

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