import java.util.*;
import java.io.*;

public class ChairStacking {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt();
		int[] xcoords = new int[n], ycoords = new int[n];
		
		double avg_x = 0.0, avg_y = 0.0;
		double mid = (double)(m-1)/2 + 1.0;
		
		for(int i = 0; i < n; i++)
		{
			xcoords[i] = readInt(); ycoords[i] = readInt();
			avg_x += xcoords[i]; avg_y += ycoords[i];
		}
		avg_x /= (double)n; avg_y /= (double)n;
		
		int target_x = 0, target_y = 0;
		long profit = 0;
		
		if(avg_x > mid) target_x = 1; else target_x = m;
		
		if(avg_y > mid) target_y = 1; else target_y = m;
		
		for(int i = 0; i < n; i++) {
			profit += Math.abs(target_x-xcoords[i]);
			profit += Math.abs(target_y-ycoords[i]);
		}
		System.out.println(profit);
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