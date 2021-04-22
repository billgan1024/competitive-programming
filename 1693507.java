import java.util.*;
import java.io.*;

public class CatchTheCat {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int x = readInt(), y = readInt();
		
		if(x == y) System.out.println(0);
		else
		{
			Queue<Integer> queue = new LinkedList<Integer>();
			boolean[] vis = new boolean[100001];
			int[] dis = new int[100001];
			queue.add(x); vis[x] = true; 
			while(!queue.isEmpty())
			{
				int cur = queue.remove();
				int[] to = {cur-1, cur+1, 2*cur};
				for(int i = 0; i < 3; i++)
				{
					if(to[i] >= 0 && to[i] <= 100000)
					{
						if(vis[to[i]]) continue;
						vis[to[i]] = true; dis[to[i]] = dis[cur] + 1;
						if(to[i] == y)
						{
							System.out.println(dis[to[i]]); return;
						}
						queue.add(to[i]);
					}
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