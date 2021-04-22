import java.util.*;
import java.io.*;

public class Tractor {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt(), k = readInt();
		ArrayList<Integer> mushroom_x = new ArrayList<Integer>();
		ArrayList<Integer> mushroom_y = new ArrayList<Integer>();
		int[] col = new int[100000];
		int[] row = new int[100000];
		//the diagonal number is the mushroom's row + col #
		//left is r+c, right is r + (n-1)-c
		//basically maps a mushroom's diagonal to an index
		int[] diaDownLeft = new int[199999];
		int[] diaDownRight = new int[199999];
		boolean found = false;
				
		
		for(int i = 0; i < n; i++)
		{
			//loop until an element in any array reaches k
			//that means that k elements are in a column, row, or diagonal
			
			int c = readInt()-1, r = readInt()-1;
			
			row[r]++;
			if(row[r] == k) 
			{
				System.out.println(i+1); found = true; break;
			}
			col[c]++;
			if(col[c] == k) 
			{
				System.out.println(i+1); found = true; break;
			}
			diaDownLeft[r+c]++;
			if(diaDownLeft[r+c] == k)
			{
				System.out.println(i+1); found = true; break;
			}
			diaDownRight[r+99999-c]++;
			if(diaDownRight[r+99999-c] == k)
			{
				System.out.println(i+1); found = true; break;
			}
			
		}
		
		if(!found) System.out.println(-1);

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

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}