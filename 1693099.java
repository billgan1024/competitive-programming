import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Integer>[] adj;
	static ArrayList<Integer> currentPath = new ArrayList<Integer>();
	static boolean exists = false;
	static boolean[] vis;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		char[] freq = new char[26], freq2 = new char[26];
		String s = readLine();
		for(int i = 0; i < s.length(); i++)
		{
			if(s.charAt(i) != ' ')
			{
				freq[s.charAt(i)-'A']++;
			}
		}
		String s2 = readLine();
		for(int i = 0; i < s2.length(); i++)
		{
			if(s2.charAt(i) != ' ')
			{
				freq2[s2.charAt(i)-'A']++;
			}
		}
		for(int i = 0; i < 26; i++)
		{
			if(freq[i] != freq2[i])
			{
				System.out.println("Is not an anagram."); return;
			}
		}
		System.out.println("Is an anagram.");
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