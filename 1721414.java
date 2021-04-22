import java.util.*;
import java.io.*;

public class Test2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Test
	{
		int mark, efficiency;
		public Test(int m, int e) {
			this.mark = m; this.efficiency = e;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt(), k = readInt();
		long goal = (long)n*(long)k, current = 0;
		
		Test[] tests = new Test[n];
		for(int i = 0; i < n; i++)
		{
			tests[i] = new Test(readInt(), readInt()); current += tests[i].mark;
		}
		Comparator<Test> comp = new Comparator<Test>() {
			@Override
			public int compare(Test o1, Test o2) {
				return o1.efficiency-o2.efficiency;
			}
		};
		Arrays.sort(tests, comp);
		long hours = 0; int index = 0;
		while(current < goal)
		{
			if(current + m-tests[index].mark <= goal) {
				current += (long)m-(long)tests[index].mark; 
				hours += (long)(m-tests[index].mark)*(long)tests[index].efficiency;
				index++;
			}
			else
			{
				long req = (long)goal - current;
				current += (long)req;
				hours += (long)req*(long)tests[index].efficiency;
			}
		}
		System.out.println(hours);
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