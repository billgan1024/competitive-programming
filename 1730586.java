import java.util.*;
import java.io.*;

public class DisjointSetExample2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static HashMap<String, String> set;
	
	static String find(String s)
	{
		//use path compression to update the parent of all the middle nodes as well as the 
		//origin node
		if(set.get(s) != s)
		{ 
			set.put(s, find(set.get(s)));
		}
		return set.get(s);
	}
	
	static void merge(String s, String t)
	{
		String fs = find(s), ft = find(t);
		if(!fs.equals(ft)) set.put(fs, ft);
	}
	
	static boolean connected(String s, String t)
	{
		return find(s) == find(t);
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		for(int i = 0; i < 5; i++)
		{
			set = new HashMap<String, String>();
			
			int n = readInt();
			for(int j = 0; j < n; j++)
			{
				char c = next().charAt(0); String a = next(), b = next();
				if(!set.containsKey(a)) set.put(a, a);
				if(!set.containsKey(b)) set.put(b, b);
				
				if(c == 'p') merge(a, b);
				else {
					System.out.println(connected(a, b) ? "connected" : "not connected");
				}
			}
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