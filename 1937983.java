import java.util.*;
import java.io.*;

public class Dijkstra2 {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static long getDis(int x1, int y1, int x2, int y2)
	{
		return (long)(Math.pow(x1-x2, 2) + Math.pow(y1-y2, 2));
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(); boolean vis[] = new boolean[n+1]; long dis[] = new long[n+1];
		Arrays.fill(dis, (long)1e15); int x[] = new int[n+1], y[] = new int[n+1];
		for(int i = 1; i <= n; i++)
		{
			x[i] = readInt(); y[i] = readInt();
		}
		int o = readInt(), q = readInt(); dis[o] = 0; 
		for(int i = 1; i <= n; i++)
	    {
	        int cur = -1; long d = (long) 1e15;
	        for(int j = 1; j <= n; j++)
	        {
	            if(dis[j] < d && !vis[j]) { d = dis[j]; cur = j; }
	        }
	        if(cur == -1) break; vis[cur] = true;
	        for(int j = 1; j <= n; j++)
	        {
	            if(dis[cur] + getDis(x[cur], y[cur], x[j], y[j]) < dis[j])
	            {
	                dis[j] = dis[cur] + getDis(x[cur], y[cur], x[j], y[j]);
	            }
	        }
	    }
		Arrays.sort(dis);
		for(int i = 0; i < q; i++)
		{
			long h = readLong(); System.out.println(upper_bound(dis, h));
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
	
	public static int upper_bound (long[] arr, long x) {
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