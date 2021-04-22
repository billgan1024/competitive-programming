import java.io.*;
import java.util.*;

public class BoardGames {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		boolean[] vis = new boolean[10000001];
		
		int[] dis = new int[10000001];
		
		int n = readInt(), m = readInt();
		if(n == m) 
		{
			System.out.println(0); return;
		}
		
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(n);
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			int[] avail;
			if(cur % 2 == 0) avail = new int[] {3*cur, cur-1, cur-3, cur/2};
			else avail = new int[] {3*cur, cur-1, cur-3};
			for(int i = 0; i < avail.length; i++)
			{
				if(avail[i] >= 1 && avail[i] <= 10000000)
				{
					if(vis[avail[i]]) continue;
					vis[avail[i]] = true;
					dis[avail[i]] = dis[cur] + 1;
					if(avail[i] == m)
					{
						System.out.println(dis[avail[i]]); return;
					}
					queue.add(avail[i]);
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