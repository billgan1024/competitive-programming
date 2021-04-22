import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Grind {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		int[] difCpuUsage = new int[10000001];
		for(int i = 0; i < n; i++)
		{
			int a = readInt(), b = readInt();
			difCpuUsage[a-1] += 1;
			difCpuUsage[b-1] -= 1;
		}
		
		//take sum and max number
		int sum = difCpuUsage[0];
		int maxSum = Integer.MIN_VALUE;
		for(int x = 1; x < difCpuUsage.length-1; x++)
		{
			sum += difCpuUsage[x];
			if(maxSum < sum) maxSum = sum;
		}
		System.out.println(maxSum);
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