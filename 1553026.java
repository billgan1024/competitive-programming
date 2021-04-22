import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Maraton {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static ArrayList<Character> letters = new ArrayList<Character>();
	static ArrayList<Integer> xLocations = new ArrayList<Integer>();
	static ArrayList<Integer> yLocations = new ArrayList<Integer>();
	
	public static void main(String[] args) throws IOException 
	{
		int n = readInt();
		char[][] grid = new char[n][n];
		for(int x = 0; x < n; x++)
		{
			String s = readLine();
			for(int y = 0; y < n; y++)
			{
				char c = s.charAt(y);
				if(c != '.')
				{
					//add the target to the arraylists
					letters.add(c);
					xLocations.add(x);
					yLocations.add(y);
					
				}
				grid[x][y] = c;
			}
		}
		
		String result = "ongoing";
		
		//loop thru all letter locations
		for(int i = 0; i < letters.size(); i++)
		{
			char c = letters.get(i);
			int x = xLocations.get(i), y = yLocations.get(i);
			
			//loop 2 squares in all 8 directions
			if(x + 2 < n)
			{
				if(grid[x+1][y] == c && grid[x+2][y] == c)
				{
					result = c + "";
					break;
				}
				
				if(y - 2 >= 0)
				{
					if(grid[x+1][y-1] == c && grid[x+2][y-2] == c)
					{
						result = c + "";
						break;
					}
				}
				
				if(y + 2 < n)
				{
					if(grid[x+1][y+1] == c && grid[x+2][y+2] == c)
					{
						result = c + "";
						break;
					}
				}
			}
			
			//loop 2 squares in all 8 directions
			if(x - 2 >= 0)
			{
				if(grid[x-1][y] == c && grid[x-2][y] == c)
				{
					result = c + "";
					break;
				}
				
				if(y - 2 >= 0)
				{
					if(grid[x-1][y-1] == c && grid[x-2][y-2] == c)
					{
						result = c + "";
						break;
					}
				}
				
				if(y + 2 < n)
				{
					if(grid[x-1][y+1] == c && grid[x-2][y+2] == c)
					{
						result = c + "";
						break;
					}
				}
			}
			
			if(y - 2 >= 0)
			{
				if(grid[x][y-1] == c && grid[x][y-2] == c)
				{
					result = c + "";
					break;
				}
			}
			
			if(y + 2 < n)
			{
				if(grid[x][y+1] == c && grid[x][y+2] == c)
				{
					result = c + "";
					break;
				}
			}
		}
		System.out.println(result);
	}
	
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}

}