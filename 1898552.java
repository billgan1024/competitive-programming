import java.util.*;
import java.io.*;

public class KeepOnTrucking {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int a = readInt(), b = readInt(), n = readInt();
		int[] s = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
		int[] pos = new int[s.length+n]; long[] dp = new long[pos.length];
		
		//we need dp[n-1] - the # of ways to reach motel n-1
		
		for(int i = 0; i < s.length; i++) pos[i] = s[i];
		for(int i = s.length; i < pos.length; i++) pos[i] = readInt();
		
		Arrays.sort(pos); 
		
		dp[0] = 1;
		for(int i = 1; i < pos.length; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(pos[i]-pos[j] >= a && pos[i]-pos[j] <= b) dp[i] += dp[j];
			}
		}
		System.out.println(dp[pos.length-1]);
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