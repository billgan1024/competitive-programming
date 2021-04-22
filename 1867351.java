import java.util.*;
import java.io.*;

public class LoanRepayment {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static long n, k, m;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		n = readLong(); k = readLong(); m = readLong();
		long low = 1, high = n, ans = 0;
		while(low <= high)
		{
			long mid = (low+high)/2;
			//if you can give n milk within k days, try increasing x 
			if(check(mid) >= n)
			{
				ans = mid; low = mid+1;
			}
			else high = mid-1;
		}
		System.out.println(ans);
	}
	
	static long check(long x)
	{
		//returns milk given after k days using the parameter 'x'
		long total = 0, day = 0;
		while(day < k)
		{
			long y = (n-total)/x;
			if(y <= m)
			{
				return total + m*(k-day);
			}
			//speed up calculation (add all the days where you give 'y' milk for this value
			//of y
			long remain = Math.min(k-day, (n-x*y-total)/y + 1);
			total += y*remain; day += remain;
		}
		return total;
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
}