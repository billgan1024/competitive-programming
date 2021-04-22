import java.util.*;
import java.io.*;

public class ThanksgivingDish {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Integer>[] adj;
	static int minDepth = Integer.MAX_VALUE, count[];
	
	static void dfs(int cur, int depth)
	{
		if(adj[cur].size() == 0) minDepth = Math.min(minDepth, depth);
		else
		{
			for(int i : adj[cur])
			{
				dfs(i, depth + count[i]);
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(); adj = new ArrayList[n]; count = new int[n];
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<Integer>();
		
		for(int i = 0; i < m; i++)
		{
			int from = readInt()-1, k = readInt();
			for(int j = 0; j < k; j++) adj[from].add(readInt()-1);
		}
		for(int i = 0; i < n; i++) count[i] = readInt();
		
		dfs(0, 0);
		
		//print out the min depth + the # of 1s
		System.out.println(minDepth + count[0]);
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