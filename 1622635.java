import java.util.*;
import java.io.*;

public class FloorPlan {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int flooring = readInt();
		int rows = readInt(), cols = readInt();
		
		ArrayList<Integer> rooms = new ArrayList<Integer>();
		
		char[][] grid = new char[rows][cols];
		for(int r = 0; r < rows; r++)
		{
			String s = readLine();
			for(int c = 0; c < cols; c++)
			{
				grid[r][c] = s.charAt(c);
			}
		}
		
		//breadth first search all the nodes to find the size of all the rooms
		boolean[][] vis = new boolean[rows][cols];
		
		for(int r = 0; r < rows; r++)
		{
			for(int c = 0; c < cols; c++)
			{
				if(vis[r][c] || grid[r][c] == 'I') continue;
				
				Queue<Integer> queue_r = new LinkedList<Integer>();
				Queue<Integer> queue_c = new LinkedList<Integer>();
				
				int nodesVisited = 0;
				
				//push start node into the queue
				queue_r.add(r);
				queue_c.add(c);
				vis[r][c] = true;
				
				while(!queue_r.isEmpty())
				{
					int cur_r = queue_r.remove(), cur_c = queue_c.remove();
					nodesVisited++;
					
					int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
					
					for(int i = 0; i < dir.length; i++)
					{
						int new_r = cur_r + dir[i][0];
						int new_c = cur_c + dir[i][1];
						
						if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols)
						{
							if(grid[new_r][new_c] == 'I') continue;
							if(vis[new_r][new_c]) continue;
							queue_r.add(new_r);
							queue_c.add(new_c);
							vis[new_r][new_c] = true;
						}
					}
				}
				
				//add the total square metres of this room to the arraylist
				rooms.add(nodesVisited);
			}
		}
		
		Collections.sort(rooms, Collections.reverseOrder());
		
		int canFill = -1;
		int remaining = -1;
		
		for(int i = 0; i < rooms.size(); i++)
		{
			if(flooring < rooms.get(i))
			{
				canFill = i;
				remaining = flooring;
				break;
			}
			
			flooring -= rooms.get(i);
		}
		
		if(canFill == -1)
		{
			canFill = rooms.size();
			remaining = flooring;
		}
		System.out.print(canFill + " room");
		if(canFill != 1) System.out.print("s");
		System.out.println(", " + remaining + " square metre(s) left over");
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