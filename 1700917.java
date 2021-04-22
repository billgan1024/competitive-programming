import java.util.*;
import java.io.*;

public class Test2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static long evaluate(long[] poly, long x)
	{
		long res = 0;
		for(int i = 0; i < poly.length; i++)
		{
			res += poly[i] * Math.pow(x, poly.length-1-i);
		}
		return res;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		HashMap<String, ArrayList<String>> adj = new HashMap<String, ArrayList<String>>();
		
		HashMap<String, String> in = new HashMap<String, String>();
		
		int n = readInt();
		
		for(int i = 0; i < n; i++)
		{
			String from = next(), to = next();
			ArrayList<String> temp = adj.getOrDefault(from, new ArrayList<String>());
			temp.add(to); adj.put(from, temp);
			in.put(to, from);
		}
		
		for(int i = 0; i < 10; i++)
		{
			String s = readLine();
			int sisters = adj.get(in.get(s)).size()-1;
			String mother = in.get(s), grandmother = in.get(mother);
			
			if(mother.equals(null) || grandmother.equals(null))
			{
				System.out.println("Cousins: 0, Sisters: 0"); continue;
			}
			
			int cousins = 0;
			for(String t : adj.get(grandmother))
			{
				if(!t.equals(mother) && adj.containsKey(t)) cousins += adj.get(t).size();
			}
			System.out.println("Cousins: " + cousins + ", Sisters: " + sisters);
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