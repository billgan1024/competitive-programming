import java.util.*;
import java.io.*;

public class FieldTrip {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	//maintain a disjoint set tracking parents, size of the component, and if it is a cycle
	static int[] set, size;
	static boolean[] isCycle;
	static int maxStudents = 0, removed = 0;
	
	static void init(int n)
	{
		set = new int[n+1]; size = new int[n+1]; isCycle = new boolean[n+1];
		for(int i = 1; i <= n; i++) { set[i] = i; size[i] = 1; }
	}
	
	static int find(int n)
	{
		if(set[n] != n)
		{
			set[n] = find(set[n]);
		}
		return set[n];
	}
	
	static void merge(int x, int y)
	{
		int fx = find(x), fy = find(y);
		if(fx != fy) {
			set[fx] = fy; 
			size[fy] += size[fx];
		}
		else
		{
			isCycle[fx] = true;
		}
	}
	
	static boolean connected(int x, int y)
	{
		return find(x) == find(y);
	}
	
	static void evaluate(int nodeCount, int k, boolean hasCycle) {
		maxStudents += k * Math.floorDiv(nodeCount, k);
		if(nodeCount > k)
		{
			if(hasCycle) removed++;
			removed += Math.ceil((double) nodeCount / k) - 1;
		}
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt(), k = readInt();
		init(n);
		for(int i = 0; i < m; i++)
		{
			int a = readInt(), b = readInt();
			merge(a, b);
		}
		for(int i = 1; i <= n; i++)
		{
			//evaluate each connected component
			if(size[find(i)] != -1) {
				evaluate(size[find(i)], k, isCycle[find(i)]);
				size[find(i)] = -1;
			}
		}
		System.out.println(maxStudents + " " + removed);
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