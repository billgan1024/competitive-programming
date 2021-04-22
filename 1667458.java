import java.util.*;
import java.io.*;

public class HeavyLight {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), q = readInt();
		ArrayList<Integer>[] adj = new ArrayList[n];
		int[] val = new int[n];
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<Integer>();
		
		for(int i = 0; i < n; i++) val[i] = readInt();
		
		for(int i = 0; i < n-1; i++)
		{
			int x = readInt()-1, y = readInt()-1;
			adj[x].add(y); adj[y].add(x);
		}
		
		for(int i = 0; i < q; i++)
		{
			int cmd = readInt(), x = readInt()-1, y = readInt()-1;
			Queue<Integer> queue = new LinkedList<Integer>();
			boolean[] vis = new boolean[n];
			int[] prev = new int[n];
			
			queue.add(x);
			vis[x] = true;
			prev[x] = -1;
			
			while(!queue.isEmpty())
			{
				int cur = queue.remove();
				for(int j : adj[cur])
				{
					if(vis[j]) continue;
					vis[j] = true; prev[j] = cur; queue.add(j);
				}
			}
			
			if(cmd == 1)
			{
				int sum = 0, count = 0;
				for(int j = y; j != -1; j = prev[j])
				{
					sum += val[j]; count++;
				}
				System.out.println(Math.round((double)sum/(double)count));
			}
			else if(cmd == 2)
			{
				ArrayList<Integer> path = new ArrayList<Integer>();
				for(int j = y; j != -1; j = prev[j])
				{
					path.add(val[j]);
				}
				
				Collections.sort(path);
				
				if(path.size() % 2 == 1) System.out.println(path.get(path.size()/2));
				else 
				{
					int right = path.get(path.size()/2), left = path.get(path.size()/2 - 1);
					System.out.println(Math.round((double)(right + left)/2.0));
				}
			}
			else if(cmd == 3)
			{
				HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
				for(int j = y; j != -1; j = prev[j])
				{
					freq.put(val[j], freq.getOrDefault(val[j], 0) + 1);
				}
				int mostFrequent = 0, max = 0;
				for(int j : freq.keySet())
				{
					if(freq.get(j) > max)
					{
						max = freq.get(j);
						mostFrequent = j;
					}
					else if(freq.get(j) == max)
					{
						if(j < mostFrequent) mostFrequent = j;
					}
				}
				System.out.println(mostFrequent);
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