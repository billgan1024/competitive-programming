import java.util.*;
import java.io.*;

public class DisjointSetTest {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int[] set;
	
	static int find(int n)
	{
		//use path compression to update the parent of all the middle nodes as well as the 
		//origin node
		if(set[n] != n)
		{ 
			set[n] = find(set[n]);
		}
		return set[n];
	}
	
	static void merge(int x, int y)
	{
		int fx = find(x), fy = find(y);
		if(fx != fy) set[fx] = fy;
	}
	
	static boolean connected(int x, int y)
	{
		int fx = find(x), fy = find(y);
		return fx == fy;
	}


	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt(); set = new int[n+1];
		for(int i = 1; i < n+1; i++) set[i] = i;
		HashSet<Integer> minSpan = new HashSet<Integer>();
		for(int i = 1; i <= m; i++)
		{
			int u = readInt(), v = readInt();
			if(connected(u, v)) continue;
			merge(u, v); minSpan.add(i);
		}
		if(minSpan.size() == n-1) {
			for(int i : minSpan) System.out.println(i);
		}
		else System.out.println("Disconnected Graph");
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

	public static int lower_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] >= x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}

	public static int upper_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] > x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}
}