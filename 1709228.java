import java.util.*;
import java.io.*;

public class Test2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static char answerA(int index)
	{
		if(index % 3 == 0) return 'A';
		else if(index % 3 == 1) return 'B';
		else return 'C';
	}
	
	static char answerB(int index)
	{
		if(index % 2 == 0) return 'B';
		else if(index % 4 == 1) return 'A';
		else return 'C';
	}
	
	static char answerG(int index)
	{
		if(index % 6 == 0 || index % 6 == 1) return 'C';
		else if(index % 6 == 2 || index % 6 == 3) return 'A';
		else return 'B';
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		
		char[] test = readLine().toCharArray();
		int a = 0, b = 0, g = 0;
		for(int i = 0; i < n; i++)
		{
			char c = test[i];
			if(answerA(i) == c) a++;
			if(answerB(i) == c) b++;
			if(answerG(i) == c) g++;
		}
		
		int max = Math.max(a, b); max = Math.max(max, g);
		System.out.println(max);
		if(a == max) System.out.println("Adrian");
		if(b == max) System.out.println("Bruno");
		if(g == max) System.out.println("Goran");
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