import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		int n = readInt(), k = readInt();
		int[] nums = new int[n];
		
		for(int i = 0; i < n; i++)
		{
			nums[i] = readInt();
		}
		
		Arrays.sort(nums);
		int count = 0;
		int counter = -1;
		for(int i = 0; i < n; i++)
		{
			if(counter == -1)
			{
				count++;
				counter = nums[i];
			}
			else
			{
				if(nums[i] - counter >= k)
				{
					count++;
					counter = nums[i];
				}
			}
		}
		System.out.println(count);
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