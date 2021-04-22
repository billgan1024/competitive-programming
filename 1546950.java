import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class DamageOutput {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		st = new StringTokenizer(br.readLine());
		int n  = readInt();
		long m = readLong();
		int[] damage = new int[n];
		long[] preSum = new long[n];
		
		st = new StringTokenizer(br.readLine());
		
		damage[0] = Integer.parseInt(st.nextToken());
		preSum[0] = damage[0];
		
		for(int i = 1; i < n; i++)
		{
			damage[i] = Integer.parseInt(st.nextToken());
			preSum[i] = damage[i] + preSum[i-1];
		}
		
		
		if(preSum[n-1] < m) System.out.println("-1");
		else
		{
			int bestSize = Integer.MAX_VALUE;
			int a = 0, b = 0;
			
			while(b < n)
			{
				long total = 0;
				if(a == 0)
				{
					total = preSum[b];
				}
				else
				{
					total = preSum[b]-preSum[a-1];
				}
				if(total >= m)
				{
					bestSize = b-a+1; //the length of the contiguous array
					a++;
				}
				else
				{
					b++;
					if(b-a+1 >= bestSize) //we dont need to find a contiguous array with length >= bestSize
					{
						a++;
					}
				}
			}
			System.out.println(bestSize);
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
	static String readLine () throws IOException {
	    return br.readLine().trim();
	}

}