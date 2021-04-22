import java.util.*;
import java.io.*;

public class SpreadSheet {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static String[][] grid = new String[10][9];
	static ArrayList<Integer> current_r, current_c;
	public static String dfs(int r, int c)
	{
		if(grid[r][c].equals("*")) 
		{
			for(int j = 0; j < current_r.size(); j++)
			{
				grid[current_r.get(j)][current_c.get(j)] = "*";
			}
			return "*";
		}
		else if(grid[r][c].matches("[0-9]+"))
		{
			//collect this value
			return String.valueOf(Integer.parseInt(grid[r][c]));
		}
		else
		{
			String[] s = grid[r][c].split("\\+");
			int sum = 0;
			
			for(int i = 0; i < s.length; i++)
			{
				int next_r = s[i].charAt(0) - 'A';
				int next_c = Character.getNumericValue(s[i].charAt(1)) - 1;
				
				//if a cycle exists, it is undefined
				for(int j = 0; j < current_r.size(); j++)
				{
					if(current_r.get(j) == next_r && current_c.get(j) == next_c)
					{
						for(int k = 0; k < current_r.size(); k++)
						{
							grid[current_r.get(k)][current_c.get(k)] = "*";
						}
						return "*";
					}
				}
				//if this does not create a cycle, add it to the list
				current_r.add(next_r);
				current_c.add(next_c);
				String t = dfs(next_r, next_c);
				
				if(t.equals("*"))
				{
					grid[next_r][next_c] = "*";
					sum = -1;
					break;
				}
				
				grid[next_r][next_c] = String.valueOf(t);
				sum += Integer.parseInt(grid[next_r][next_c]);
				
				current_r.remove(current_r.size()-1);
				current_c.remove(current_c.size()-1);
			}
			if(sum != -1) return String.valueOf(sum);
			else return "*";
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				grid[i][j] = next();
				
			}
		}
		
		//for all unknown nodes, run dfs and make sure there are no cycles (to determine the value)
		//if there is a cycle (an unknown requires a previous unknown) then it is undefined
		for(int r = 0; r < 10; r++)
		{
			for(int c = 0; c < 9; c++)
			{
				if(grid[r][c].matches("[0-9]+")) System.out.print(grid[r][c] + " ");
				else
				{
					//test for cycles with dfs to get the sum
					current_r = new ArrayList<Integer>();
					current_c = new ArrayList<Integer>();
					
					current_r.add(r);
					current_c.add(c);
					
					grid[r][c] = dfs(r, c);
					System.out.print(grid[r][c] + " ");
				}
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