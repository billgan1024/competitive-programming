import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(); 
		ArrayList<Integer>[] adj = new ArrayList[1000];
		for(int i = 0; i < 1000; i++) adj[i] = new ArrayList<Integer>();
		
		for(int i = 0; i < n; i++) 
		{
			int a = readInt()-1, b = readInt()-1; adj[a].add(b);
		}
		
		int x = readInt()-1, y = readInt()-1;
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] vis = new boolean[1000];
		
		queue.add(x); vis[x] = true;
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			for(int i : adj[cur])
			{
				if(vis[i]) continue;
				vis[i] = true;
				if(i == y)
				{
					System.out.println("Tangled"); return;
				}
				queue.add(i);
			}
		}
		System.out.println("Not Tangled");
		
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