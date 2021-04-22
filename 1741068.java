import java.util.*;
import java.io.*;

public class Test2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Platform
	{
		int alt, x1, x2;
		public Platform(int alt, int x1, int x2)
		{
			this.alt = alt; this.x1 = x1; this.x2 = x2;
		}
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int n = readInt(); Platform[] plats = new Platform[n];
		for(int i = 0; i < n; i++)
		{
			plats[i] = new Platform(readInt(), readInt(), readInt()-1);
		}
		Comparator<Platform> comp =  new Comparator<Platform>()
		{
			@Override
			public int compare(Platform o1, Platform o2) {
				return o1.alt-o2.alt;
			}
		};
		Arrays.sort(plats, comp);
		int sum = 0;
		for(int i = 0; i < plats.length; i++)
		{
			int left = plats[i].x1, right = plats[i].x2;
			int leftHeight = plats[i].alt, rightHeight = plats[i].alt;
			//find highest platform above the left pillar
			for(int j = i-1; j >= 0; j--)
			{
				if(left >= plats[j].x1 && left <= plats[j].x2)
				{
					leftHeight -= plats[j].alt; break;
				}
			}
			//find highest platform above the right pillar
			for(int j = i-1; j >= 0; j--)
			{
				if(right >= plats[j].x1 && right <= plats[j].x2)
				{
					rightHeight -= plats[j].alt; break;
				}
			}
			sum += leftHeight + rightHeight;
		}
		System.out.println(sum);
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