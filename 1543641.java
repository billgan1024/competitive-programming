import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class MaxGCD
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int maxGCD = Integer.MIN_VALUE;
	static HashMap<ArrayList<Integer>, Integer> gcdMap = new HashMap<ArrayList<Integer>, Integer>();
	
	public static int gcd(int m, int n) //48, 30
	{
		if(n == 0) return m;
		else return gcd(n, m % n);
	}
	
	public static void main(String[] args) throws IOException
	{
		int count = readInt();
		int[] num = new int[count];
		for(int i = 0; i < count; i++)
		{
			num[i] = readInt();
		}
		if(num.length == 2) System.out.println(Math.max(num[0], num[1]));
		else
		{
			//prefix the array (new array) and suffix
			//prefix stores gcd of all numbers before it and it; suffix stores gcd of all numbers after it and it
			int[] pre = new int[count];
			pre[0] = num[0];
			for(int i = 1; i < pre.length; i++)
			{
				pre[i] = gcd(num[i], pre[i-1]);
			}
			
			int[] suf = new int[count];
			suf[suf.length-1] = num[num.length-1];
			for(int i = suf.length-2; i >= 0; i--)
			{
				suf[i] = gcd(num[i], suf[i+1]);
			}
			
			//loop thru all elements of array, check gcd prefix and suffix array of i-1 (pre) and i+1 (suf)
			int maxGCD = Integer.MIN_VALUE;
			for(int i = 0; i < num.length; i++)
			{
				if(i == 0) maxGCD = Math.max(maxGCD, suf[i+1]);
				else if(i == num.length-1) maxGCD = Math.max(maxGCD, pre[i-1]);
				else maxGCD = Math.max(maxGCD, gcd(pre[i-1], suf[i+1]));
			}
			
			System.out.println(maxGCD);
		}
	}
	
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}