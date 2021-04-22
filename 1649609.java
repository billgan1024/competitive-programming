import java.util.*;
import java.io.*;

public class Unfriends {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		ArrayList<Integer>[] adj = new ArrayList[n];
		
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<Integer>();
		
		for(int i = 0; i < n-1; i++)
		{
			int j = readInt()-1;
			adj[j].add(i);
		}
		
		ArrayList<HashSet<Integer>> sets = new ArrayList<HashSet<Integer>>();
		
		for(int i = 0; i < Math.pow(2, n-1); i++)
		{
			String s = Integer.toBinaryString(i);
			while(s.length() < n-1) s = "0" + s;
			
			HashSet<Integer> set = new HashSet<Integer>();
			Queue<Integer> queue = new LinkedList<Integer>();
			for(int j = 0; j < s.length(); j++)
			{
				if(s.charAt(j) == '1')
				{
					//remove this guy and all of his friends
					queue.add(j);
					set.add(j);
				}
			}
			
			while(!queue.isEmpty())
			{
				int cur = queue.remove();
				for(int j : adj[cur])
				{
					queue.add(j);
					set.add(j);
				}
			}
			
			boolean exists = false;
			for(HashSet<Integer> l : sets)
			{
				if(set.equals(l))
				{
					exists = true;
					break;
				}
			}
			
			if(!exists) sets.add(set);
			
		}
		
		System.out.println(sets.size());
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
	
	public static int lower_bound (int[] arr, int x) {
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

	public static int upper_bound (int[] arr, int x) {
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