import java.util.*;
import java.io.*;

public class ContestOfficial6 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt(), q = readInt();
		
		int[] a = new int[n], pre = new int[n], suf = new int[n];
		
		for(int i = 0; i < n; i++) {
			a[i] = readInt();
			if(i == 0 || a[i] > a[pre[i-1]]) pre[i] = i;
			else pre[i] = pre[i-1];
		}
		
		for(int i = n-1; i >= 0; i--) {
			if(i == n-1 || a[i] > a[suf[i+1]]) suf[i] = i;
			else suf[i] = suf[i+1];
		}
		
		for(int i = 0; i < q; i++) {
			int point = readInt()-1;
			System.out.println((pre[point-1]+1) + " " + (suf[point+1]+1));
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