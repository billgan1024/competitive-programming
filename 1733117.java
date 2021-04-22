import java.util.*;
import java.io.*;

public class WishUponAStar {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int[] set;
	static boolean used = false, invalid = false;
	
	static void init(int n)
	{
		set = new int[n+1];
		for(int i = 1; i <= n; i++) set[i] = i;
	}
	
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
		else
		{
			if(!used) used = true;
			else invalid = true;
		}
	}
	
	static boolean connected(int x, int y)
	{
		return find(x) == find(y);
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(); init(n);
		for(int i = 0; i < m; i++)
		{
			int a = readInt(), b = readInt();
			merge(a, b);
			if(invalid) {
				System.out.println("NO"); return;
			}
		}
		System.out.println("YES");

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