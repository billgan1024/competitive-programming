import java.util.*;
import java.io.*;

public class Photoshoot {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static TreeSet<Integer> set = new TreeSet<Integer>();

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), b[] = new int[n-1];
		for(int i = 0; i < n-1; i++) b[i] = readInt(); 
		for(int i = 1; i <= n; i++) 
		{
			//set makes sure we are not allowed to use the same # twice
			//if at any point you cannot make a permutation, we need to increase the first
			//value to reset it (otherwise it would not work)
			//by looping from lexicographically minimum to maximum we will find the optimal
			//answer
			int[] a = new int[n]; HashSet<Integer> set = new HashSet<Integer>();
			for(int c = 1; c <= n; c++) set.add(c);
			a[0] = i; int prev = b[0]-i; set.remove(i);
			boolean valid = true;
			for(int j = 1; j < n-1; j++)
			{
				if(!set.contains(prev)) { valid = false; break; }
				else
				{
					a[j] = prev; set.remove(prev); prev = b[j]-prev; 
				}
			}
			if(valid) { a[n-1] = prev; for(int x : a) System.out.print(x + " "); return; }
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
}