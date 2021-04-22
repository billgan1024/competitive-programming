import java.util.*;
import java.io.*;

public class Herding {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int rows = readInt(), cols = readInt();
		if(rows == 1 && cols == 1) 
		{
			System.out.println(1); return;
		}
		char[][] grid = new char[rows][cols];
		
		for(int r = 0; r < rows; r++)
		{
			String s = readLine();
			for(int c = 0; c < cols; c++)
			{
				grid[r][c] = s.charAt(c);
			}
		}
		
		//find all connected components
		int components = 0;
		boolean[][] vis = new boolean[rows][cols];
		Queue<Integer> queue_r = new LinkedList<Integer>();
		Queue<Integer> queue_c = new LinkedList<Integer>();
		ArrayList<Integer> path_r = new ArrayList<Integer>();
		ArrayList<Integer> path_c = new ArrayList<Integer>();
		
		for(int r = 0; r < rows; r++)
		{
			for(int c = 0; c < cols; c++)
			{
				if(vis[r][c]) continue;
				components++;
				queue_r = new LinkedList<Integer>();
				queue_c = new LinkedList<Integer>();
				
				path_r = new ArrayList<Integer>();
				path_c = new ArrayList<Integer>();
				
				queue_r.add(r);
				queue_c.add(c);
				path_r.add(r);
				path_c.add(c);
				vis[r][c] = true;
				
				
				while(!queue_r.isEmpty())
				{
					int cur_r = queue_r.remove(), cur_c = queue_c.remove();
					switch(grid[cur_r][cur_c])
					{
						case 'N': cur_r--;
						break;
						case 'S': cur_r++;
						break;
						case 'E': cur_c++;
						break;
						case 'W': cur_c--;
						break;
					}
					if(vis[cur_r][cur_c]) {
						boolean yes = false;
						for(int i = 0; i < path_r.size(); i++)
						{
							if(cur_r == path_r.get(i) && cur_c == path_c.get(i))
							{
								yes = true;
								break;
							}
						}
						if(!yes) components--;
						continue;
					}
					vis[cur_r][cur_c] = true;
					queue_r.add(cur_r);
					queue_c.add(cur_c);
					path_r.add(cur_r);
					path_c.add(cur_c);
				}
			}
		}
		
		System.out.println(components);

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