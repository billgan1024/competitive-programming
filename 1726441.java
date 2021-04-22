import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		int n = readInt(); HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
		TreeSet<Integer> modes = new TreeSet<Integer>();
		int largest = Integer.MIN_VALUE;
		for(int i = 0; i < n; i++)
		{
			int a = readInt();
			freq.put(a, freq.getOrDefault(a, 0) + 1);
			if(freq.get(a) > largest)
			{
				modes = new TreeSet<Integer>(); modes.add(a); largest = freq.get(a);
			}
			else if(freq.get(a) == largest) modes.add(a);
		}
		for(int i : modes) System.out.print(i + " ");
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