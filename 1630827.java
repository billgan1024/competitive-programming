import java.util.*;
import java.io.*;

public class Dodgeball {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		boolean[][] grid = new boolean[200][401];
		grid[0][200] = true;
		grid[1][200] = true;
		grid[2][200] = true; grid[2][201] = true; grid[2][202] = true; grid[2][203] = true; grid[2][205] = true; grid[2][206] = true; grid[2][207] = true;
		
		grid[3][203] = true; grid[3][203] = true; grid[3][204] = true; grid[3][207] = true;
		
		grid[4][199] = true; grid[4][203] = true; grid[4][204] = true; grid[4][205] = true; grid[4][207] = true;
		grid[5][199] = true; grid[5][207] = true;
		grid[6][199] = true; grid[6][200] = true; grid[6][201] = true; grid[6][202] = true; grid[6][203] = true; grid[6][204] = true; grid[6][205] = true; grid[6][206] = true; grid[6][207] = true;
		
		//row: +1, then multiply by -1
		//column: +200
		
		int start_r = 4, start_c = 199;
		
		char c = next().charAt(0);
		int amnt = readInt();
		boolean danger = false;
		
		while(c != 'q' && !danger)
		{
			switch(c)
			{
				case 'l':
					for(int i = 1; i <= amnt; i++)
					{
						if(grid[start_r][start_c-i])
						{
							danger = true;
							break;
						}
						else grid[start_r][start_c-i] = true;
					}
					start_c -= amnt;
					break;
				case 'r': 
					for(int i = 1; i <= amnt; i++)
					{
						if(grid[start_r][start_c+i])
						{
							danger = true;
							break;
						}
						else grid[start_r][start_c+i] = true;
					}
					start_c += amnt;
					break;
				case 'u':
					for(int i = 1; i <= amnt; i++)
					{
						if(grid[start_r-i][start_c])
						{
							danger = true;
							break;
						}
						else grid[start_r-i][start_c] = true;
					}
					start_r -= amnt;
					break;
				case 'd':
					for(int i = 1; i <= amnt; i++)
					{
						if(grid[start_r+i][start_c])
						{
							danger = true;
							break;
						}
						else grid[start_r+i][start_c] = true;
					}
					start_r += amnt;
					break;
			}
			
			int real_r = (-start_r) - 1, real_c = start_c - 200;
			if(!danger)
			{
				System.out.println(real_c + " " + real_r + " safe");
			}
			else
			{
				System.out.println(real_c + " " + real_r + " DANGER");
			}
			
			c = next().charAt(0);
			amnt = readInt();
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