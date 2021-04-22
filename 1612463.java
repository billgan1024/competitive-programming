import java.util.*;
import java.io.*;

public class AFK {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {

		int t = readInt();
		for(int i = 0; i < t; i++)
		{
			int col = readInt(), row = readInt();
			
			char[][] room = new char[row][col];
			
			int start_r = -1, start_c = -1;
			int end_r = -1, end_c = -1;
			
			for(int r = 0; r < row; r++)
			{
				String s = next();
				for(int c = 0; c < col; c++)
				{
					room[r][c] = s.charAt(c);
					if(s.charAt(c) == 'C')
					{
						start_r = r;
						start_c = c;
					}
					else if(s.charAt(c) == 'W')
					{
					    end_r = r;
					    end_c = c;
					}
				}
			}
			
			Queue<Integer> queue_r = new LinkedList<Integer>();
			Queue<Integer> queue_c = new LinkedList<Integer>();
			
			boolean[][] visited = new boolean[row][col];
			int[][] distance = new int[row][col];
			
			queue_r.add(start_r);
			queue_c.add(start_c);
			
			visited[start_r][start_c] = true;
			distance[start_r][start_c] = 0;
			
			boolean found = false;
			
			while(!queue_r.isEmpty() && !found)
			{
				int current_r = queue_r.remove();
				int current_c = queue_c.remove();
				
				int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
				
				for(int j = 0; j < dir.length; j++)
				{
					
					int new_r = current_r + dir[j][0];
					int new_c = current_c + dir[j][1];
					
					if(new_r >= 0 && new_r < row && new_c >= 0 && new_c < col)
					{
						
						if(visited[new_r][new_c]) continue;
						if(room[new_r][new_c] == 'X') continue;
						
						//add this new node
						queue_r.add(new_r);
						queue_c.add(new_c);
						visited[new_r][new_c] = true;
						distance[new_r][new_c] = distance[current_r][current_c] + 1;
					}
				}
			}
			
			if(!visited[end_r][end_c])
			{
			    System.out.println("#notworth");
			}
			else if(distance[end_r][end_c] >= 60)
			{
			    System.out.println("#notworth");
			}
			else System.out.println(distance[end_r][end_c]);
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