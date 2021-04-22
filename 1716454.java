import java.util.*;
import java.io.*;

public class Test2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Num
	{
		int n, pos;
		public Num(int n, int pos) {
			this.n = n; this.pos = pos;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		Deque<Num> d = new LinkedList<Num>();
		HashMap<Integer, Integer> positions = new HashMap<Integer, Integer>();
		
		int q = readInt();
		for(int i = 1; i <= q; i++)
		{
			char cmd = next().charAt(0); int x = readInt();
			switch(cmd) {
			case 'F':
				d.addFirst(new Num(x, i));
				positions.put(x, i);
				break;
			case 'E':
				d.addLast(new Num(x, i));
				positions.put(x, i);
				break;
			case 'R':
				positions.put(x, 0);
				break;
			}
		}
		
		for(Num num : d)
		{
			if(num.pos == positions.get(num.n)) System.out.println(num.n);
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