import java.util.*;
import java.io.*;

public class Blindfold {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int r = readInt(), c = readInt();
		char[][] grid = new char[r][c];
		for(int i = 0; i < r; i++) {
			String s = readLine();
			for(int j = 0; j < c; j++) grid[i][j] = s.charAt(j);
		}
		
		//add moves to the direction, if the move is 0 then move forward
		int m = readInt(), moves[] = new int[m];
		for(int i = 0; i < m; i++) {
			char a = next().charAt(0);
			switch(a) {
			case 'L': moves[i] = -1; break;
			case 'R': moves[i] = 1; break;
			}
		}
		
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				if(grid[i][j] == 'X') continue;
				//start finding the final positions for this square
				//0 = up, 1 = right, 2 = down, 3 = left (mod 4)
				for(int start = 0; start < 4; start++)
				{
					int cur_r = i, cur_c = j, dir = start;
					boolean invalid = false;
					for(int move : moves)
					{
						if(invalid) break;
						if(move == 0)
						{
							switch(dir%4)
							{
							case 0:
								cur_r--;
								if(!in(grid, cur_r, cur_c, r, c)) { invalid = true; break; }
								break;
							case 1:
								cur_c++;
								if(!in(grid, cur_r, cur_c, r, c)) { invalid = true; break; }
								break;
							case 2:
								cur_r++;
								if(!in(grid, cur_r, cur_c, r, c)) { invalid = true; break; }
								break;
							case 3:
								cur_c--;
								if(!in(grid, cur_r, cur_c, r, c)) { invalid = true; break; }
								break;
							}
						}
						else
						{
							dir += move;
							if(dir == -1) dir = 3;
						}
					}
					
					if(!invalid) grid[cur_r][cur_c] = '*';
				}
			}
		}
		
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) System.out.print(grid[i][j]);
			System.out.println();
		}
	}
	
	static boolean in(char[][] grid, int cur_r, int cur_c, int r, int c)
	{
		return cur_r >= 0 && cur_r < r && cur_c >= 0 && cur_c < c && grid[cur_r][cur_c] != 'X';
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