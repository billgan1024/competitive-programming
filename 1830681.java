import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int k = readInt(), n = readInt(); ArrayList<Integer>[] order = new ArrayList[k];
		for(int i = 0; i < k; i++) {
			order[i] = new ArrayList<Integer>();
			for(int j = 0; j < n; j++) {
				order[i].add(readInt()-1);
			}
		}
		int count = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				int consistent = 0; boolean valid = true;
				for(int l = 0; l < k; l++) {
					int ai = order[l].indexOf(i), aj = order[l].indexOf(j);
					if(consistent == 0) consistent = ai - aj > 0 ? 1 : -1;
					else if(consistent == 1) {
						if(ai < aj) { valid = false; break; }
					}
					else if(consistent == -1) {
						if(ai > aj) { valid = false; break; }
					}
				}
					
				if(valid) count++;
			}
		}
		System.out.println(count);
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