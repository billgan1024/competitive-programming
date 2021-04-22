import java.util.*;
import java.io.*;

public class Maze {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int t = readInt();
		
		for(int i = 0; i < t; i++)
		{
			int row = readInt(), col = readInt();
			
			char[][] maze = new char[row][col];
			for(int r = 0; r < row; r++)
			{
				String s = next();
				for(int c = 0; c < col; c++)
				{
					maze[r][c] = s.charAt(c);
				}
			}
			
			//start 2d bfs
			Queue<Integer> queue_r = new LinkedList<Integer>();
			Queue<Integer> queue_c = new LinkedList<Integer>();
			
			boolean[][] visited = new boolean[row][col];
			
			int[][] distance = new int[row][col];
			
			queue_r.add(0);
			queue_c.add(0);
			visited[0][0] = true;
			distance[0][0] = 0;
			
			while(!queue_r.isEmpty())
			{
				int current_r = queue_r.remove();
				int current_c = queue_c.remove();
				
				int[][] dir = new int[1][1];
				switch(maze[current_r][current_c])
				{
					case '+': dir = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
					break;
					
					case '-': dir = new int[][]{{0, -1}, {0, 1}};
					break;
					
					case '|': dir = new int[][]{{-1, 0}, {1, 0}};
					break;
				}
				
				for(int j = 0; j < dir.length; j++)
				{
					int new_r = current_r + dir[j][0];
					int new_c = current_c + dir[j][1];
					
					if(new_r >= 0 && new_r < row && new_c >= 0 && new_c < col)
					{
						if(visited[new_r][new_c]) continue;
						if(maze[new_r][new_c] == '*') continue;
						//add this new node
						queue_r.add(new_r);
						queue_c.add(new_c);
						visited[new_r][new_c] = true;
						distance[new_r][new_c] = distance[current_r][current_c] + 1;
					}
				}
			}
			
			if(!visited[row-1][col-1]) System.out.println(-1);
			else System.out.println(distance[row-1][col-1] + 1);
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