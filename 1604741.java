import java.util.*;
import java.io.*;

public class MimiAndPrimes {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static long[] nums;
	static long maxGCD = Long.MIN_VALUE;
	
	public static boolean isPrime(long n)
	{
		if(n == 2 || n == 5) return true;
		long last = n % 10;
		if(last == 2 || last == 5 || last == 0 || n == 1) return false;
		long limit = (long) Math.sqrt(n); //limit is floor of sqrt(n)
		
		for(long x = 2; x <= limit; x++) //loop from 2 
		{
			if(n % x == 0)
			{
				return false;
			}
		}
		return true;
	}
	
	public static long gcd(long m, long n) //48, 30
	{
		if(n == 0) return m;
		else return gcd(n, m % n);
	}

	public static void main(String[] args) throws IOException {
		int n = readInt();
		nums = new long[n];
		nums[0] = readLong();
		maxGCD = nums[0];
		
		for(int i = 1; i < n; i++)
		{
			nums[i] = readLong();
			maxGCD = gcd(maxGCD, nums[i]);
		}
		
		long maxPrime = Long.MIN_VALUE;
		if(maxGCD == 1) System.out.println("DNE");
		else
		{
			long limit = (long) Math.sqrt(maxGCD); //floored sqrt of n
			for(long x = 2; x <= limit; x++)
			{
				if(maxGCD == 1) break;
				while(maxGCD % x == 0)
				{
					maxPrime = Math.max(maxPrime, x);
					maxGCD /= x;
				}
			}
			//only one prime factor greater than sqrt n
			if(maxGCD != 1) maxPrime = Math.max(maxPrime, maxGCD);
			System.out.println(maxPrime);
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