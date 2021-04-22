import java.util.*;
import java.io.*;

public class DutyOfCall {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), r = readInt()-1;
		ArrayList<Integer>[] adj = new ArrayList[n], in = new ArrayList[n];
		for(int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Integer>(); in[i] = new ArrayList<Integer>();
		}
	
		for(int i = 0; i < n; i++)
		{
			int k = readInt();
			for(int j = 0; j < k; j++)
			{
				int m = readInt()-1;
				adj[i].add(m); in[m].add(i);
			}
		}
		
		int soupsurvived = 0, brucesurvived = 0;
		
		Queue<Integer> queue = new LinkedList<Integer>();
		byte[] team = new byte[n]; //1 is soupy boi, 2 is bruce
		
		//graph is guaranteed to be connected so use soupy's boi as starting point
		team[r] = 1;
		queue.add(r);
		
		while(!queue.isEmpty())
		{
			int cur = queue.remove();
			if(in[cur].size() == 0)
			{
				if(team[cur] == 1) soupsurvived++;
				else if(team[cur] == 2) brucesurvived++;
			}
			for(int i : adj[cur])
			{
				if(team[i] == 0)
				{
					queue.add(i);
					if(team[cur] == 1) team[i] = 2;
					else team[i] = 1;
				}
			}
			for(int i : in[cur])
			{
				if(team[i] == 0)
				{
					queue.add(i);
					if(team[cur] == 1) team[i] = 2;
					else team[i] = 1;
				}
			}
		}
		System.out.println(soupsurvived + " " + brucesurvived);
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