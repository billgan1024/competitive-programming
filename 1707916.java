import java.util.*;
import java.io.*;

public class DeathGUn {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		HashMap<String, Integer> sortOrder = new HashMap<String, Integer>();
		HashMap<String, ArrayList<String>> adj = new HashMap<String, ArrayList<String>>();
		HashMap<String, Integer> in = new HashMap<String, Integer>();
		
		int m = readInt();
		
		int pos = 0;
		for(int i = 0; i < m; i++)
		{
			String a = next(), b = next();
			if(!sortOrder.containsKey(a))
			{
				sortOrder.put(a, pos); pos++;
			}
			if(!sortOrder.containsKey(b))
			{
				sortOrder.put(b, pos); pos++;
			}
			ArrayList<String> temp = adj.getOrDefault(b, new ArrayList<String>());
			temp.add(a); adj.put(b, temp);
			int inDegree = in.getOrDefault(a, 0); inDegree++; in.put(a, inDegree);
			if(!adj.containsKey(a)) adj.put(a, new ArrayList<String>());
			if(!in.containsKey(b)) in.put(b, 0);
		}
		
		Comparator<String> comp = new Comparator<String>()
		{
			@Override
			public int compare(String arg0, String arg1) {
				return sortOrder.get(arg0) - sortOrder.get(arg1);
			}
		};
		
		PriorityQueue<String> pq = new PriorityQueue<String>(comp);
		for(String s : in.keySet())
		{
			if(in.get(s) == 0) pq.add(s);
		}
		
		while(!pq.isEmpty())
		{
			String cur = pq.remove();
			System.out.println(cur);
			for(String s : adj.get(cur))
			{
				in.put(s, in.get(s) - 1);
				if(in.get(s) == 0) pq.add(s);
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