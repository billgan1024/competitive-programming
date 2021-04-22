import java.util.*;
import java.io.*;

public class LightsGoingEzGame {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int r, c;
	static boolean[][] grid;
	static ArrayList<Boolean[]> combos;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		r = readInt(); c = readInt();
		grid = new boolean[r][c];
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++) grid[i][j] = readInt() == 1 ? true : false;
		}
		combos = new ArrayList<Boolean[]>();
		
		Boolean[] init = new Boolean[c]; 
		for(int j = 0; j < c; j++) init[j] = grid[r-1][j];
		combos.add(init);
		
		boolean[][] og = new boolean[r][c];
		for(int j = 0; j < r; j++) og[j] = Arrays.copyOf(grid[j], c);
		
		for(int i = 1; i < r; i++)
		{
			for(int j = i; j < r; j++)
			{
				swap(j);
			}
			
			Boolean[] finalRow = new Boolean[c]; 
			for(int j = 0; j < c; j++) finalRow[j] = grid[r-1][j];
			
			if(!containsRow(finalRow)) combos.add(finalRow);
			
			for(int j = 0; j < r; j++) grid[j] = Arrays.copyOf(og[j], c);
		}
		System.out.println(combos.size());
	}
	
	static boolean containsRow(Boolean[] finalRow)
	{
		for(Boolean[] b : combos)
		{
			boolean isEqual = true;
			for(int i = 0; i < c; i++)
			{
				if(b[i] != finalRow[i]) { isEqual = false; break; }
			}
			if(isEqual) return true;
		}
		return false;
	}
	
	static void swap(int row)
	{
		//performs exclusive or on row and row-1
		for(int i = 0; i < c; i++)
		{
			grid[row][i] ^= grid[row-1][i];
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