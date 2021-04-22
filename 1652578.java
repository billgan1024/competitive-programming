import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Number
	{
		int sign, val;
		public Number(int sign, int val)
		{
			this.sign = sign;
			this.val = val;
		}
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		Number[] nums = new Number[n];
		for(int i = 0; i < n; i++)
		{
			int sign = 1;
			int num = readInt();
			if(num < 0)
			{
				num = -num;
				sign = -1;
			}
			nums[i] = new Number(sign, num);
		}
		
		if(nums.length == 1)
		{
			System.out.println(nums[0].val * nums[0].sign); return;
		}
		
		Comparator<Number> comp = new Comparator<Number>()
		{
			@Override
			public int compare(Number arg0, Number arg1) {
				return arg0.val - arg1.val;
			}
		};
		Arrays.sort(nums, comp);
		
		long product = 0;
		int prev = 0;
		for(int i = n-1; i >= 0; i--)
		{
			if(nums[i].val != 0)
			{
				if(nums[i].sign == -1)
				{
					if(prev == 0) prev = nums[i].val;
					else
					{
						if(product == 0) product = 1;
						product *= nums[i].val;
						product *= prev;
						prev = 0;
					}
				}
				else
				{
					if(product == 0) product = 1;
					product *= nums[i].val;
				}
			}
		}
		
		System.out.println(product);
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