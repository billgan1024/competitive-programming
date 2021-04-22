import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		int[][] grid = new int[1000][1000];
		
		int x1 = readInt(), y1 = readInt(), x2 = readInt(), y2 = readInt();
		int x3 = readInt(), y3 = readInt(), x4 = readInt(), y4 = readInt();
		
		if(x1 > x2) {
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		
		if(y1 > y2)
		{
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}
		
		if(x3 > x4) {
			int temp = x3;
			x3 = x4;
			x4 = temp;
		}
		
		if(y3 > y4)
		{
			int temp = y3;
			y3 = y4;
			y4 = temp;
		}
		x1--; x2--; y1--; y2--; x3--; y3--; x4--; y4--;
		int area = 0;
		
		for(int y = 0; y < 1000; y++)
		{
			for(int x = 0; x < 1000; x++)
			{
				if(x >= x1 && x < x2 && y >= y1 && y < y2)
				{
					area++;
				}
				else if(x >= x3 && x < x4 && y >= y3 && y < y4)
				{
					area++;
				}
			}
		}
		System.out.println(area);
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