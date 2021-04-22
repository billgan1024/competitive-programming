import java.util.*;
import java.io.*;

public class Spiral {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int x = readInt(), y = readInt();
		
		if(x == y) {
			System.out.println(x); return;
		}
		
		int difference = y-x + 1;
		
		int size = (int) Math.ceil(Math.sqrt(difference));
		
		int[][] grid = new int[size][size];
		
		int cur_r = (size-1)/2, cur_c = (size-1)/2;
		//direction 1 = down, 2 = right, 3 = up, 4 = left
		int dir = 4;
		
		for(int i = x; i <= y; i++)
		{
			grid[cur_r][cur_c] = i;
			switch(dir)
			{
			case 1: if(grid[cur_r][cur_c+1] == 0) dir = 2;
				break;
				
			case 2: if(grid[cur_r-1][cur_c] == 0) dir = 3;
				break;
				
			case 3: if(grid[cur_r][cur_c-1] == 0) dir = 4;
				break;
				
			case 4:  if(grid[cur_r+1][cur_c] == 0) dir = 1;
				break;
			}
			
			switch(dir)
			{
			case 1: cur_r++;
				break;
				
			case 2: cur_c++;
				break;
				
			case 3: cur_r--;
				break;
				
			case 4: cur_c--;
				break;
			}
		}
		
		int start_r = 1, end_r = size-1, start_c = 1, end_c = size-1;
		
		for(int i = 0; i < size; i++)
		{
			if(grid[0][i] != 0)
			{
				start_r = 0;
				break;
			}
		}
		
		for(int i = 0; i < size; i++)
		{
			if(grid[i][0] != 0)
			{
				start_c = 0;
				break;
			}
		}
		
		for(int i = 0; i < size; i++)
		{
			if(grid[size-1][i] != 0)
			{
				end_r = size;
				break;
			}
		}
		
		for(int i = 0; i < size; i++)
		{
			if(grid[i][size-1] != 0)
			{
				end_c = size;
				break;
			}
		}
		
		for(int i = start_r; i < end_r; i++)
		{
			for(int j = start_c; j < end_c; j++)
			{
				if(grid[i][j] != 0) System.out.print(grid[i][j]);
				System.out.print(" ");
			}
			System.out.println();
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

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}