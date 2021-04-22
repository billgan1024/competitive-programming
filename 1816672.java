import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Quadrant
	{
		int gold, id;
		public Quadrant(int gold, int id) { this.gold = gold; this.id = id; }
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int n = readInt();
		Quadrant[] q = new Quadrant[4]; for(int i = 0; i < 4; i++) q[i] = new Quadrant(0, i); 
		for(int i = 0; i < 2*n; i++) {
			String s = readLine();
			for(int j = 0; j < 2*n; j++) {
				boolean gold = s.charAt(j) == 'g';
				if(i < n) {
					if(j < n) {
						if(gold) q[1].gold++;
					}
					else
					{
						if(gold) q[0].gold++;
					}
				}
				else
				{
					if(j < n) {
						if(gold) q[2].gold++;
					}
					else
					{
						if(gold) q[3].gold++;
					}	
				}
			}
		}
		Arrays.sort(q, new Comparator<Quadrant>() {

			@Override
			public int compare(Quadrant arg0, Quadrant arg1) {
				if(arg0.gold == arg1.gold) return arg1.id-arg0.id;
				else return arg0.gold-arg1.gold;
			}
		});
		System.out.println(q[3].id+1);
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