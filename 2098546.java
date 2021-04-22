import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(); long psa[] = new long[n+1], dp[][] = new long[n+1][n+1];
		for(int i=1; i<=n; i++) {
			psa[i] = readInt(); dp[i][i] = psa[i];
			psa[i] += psa[i-1];
		}
		for(int len=1; len<n; len++) {
			for(int lft=1; lft+len<=n; lft++) {
				int rit = lft + len; 
				dp[lft][rit] = psa[rit] - psa[lft-1] - Math.min(dp[lft+1][rit], dp[lft][rit-1]);
			}
		}
		System.out.println(2*dp[1][n] - psa[n]);
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
	static char readCharacter() throws IOException {
		return next().charAt(0);
	}
	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}