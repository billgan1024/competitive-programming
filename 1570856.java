import java.util.*;
import java.io.*;

public class ContestOfficial5 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int g = readInt();
		
		double probability = 1.0;
		
		for(int i = 0; i < g; i++)
		{
			int evil = readInt();
			int total = readInt();
			
			probability *= (double)(total-evil)/(double)total;
			
		}
		
		System.out.println(probability);

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