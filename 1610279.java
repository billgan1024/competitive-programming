import java.util.*;
import java.io.*;

public class CrossingField {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), h = readInt();
		
		//queue for x and y coords
		
		int[][] field = new int[n][n];
		
		for(int y = 0; y < n; y++)
		{
			for(int x = 0; x < n; x++)
			{
				//update this height
				field[y][x] = readInt();
			}
		}
		
		
		
		boolean[][] visited = new boolean[n][n];
		Queue<Integer> queue_x = new LinkedList<Integer>();
		Queue<Integer> queue_y = new LinkedList<Integer>();
		
		queue_x.add(0); queue_y.add(0);
		visited[0][0] = true;
		
		//direction array
		int dir[][] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		
		while(!queue_x.isEmpty() || !queue_y.isEmpty())
		{
			int current_x = queue_x.remove();
			int current_y = queue_y.remove();
			
			//check all directions
			for(int i = 0; i < 4; i++)
			{
				//simulate moving in 4 directions
				int new_x = current_x + dir[i][0];
				int new_y = current_y + dir[i][1];
				
				//check bounds
				if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n)
				{
					//if already visited, ignore
					if(visited[new_x][new_y]) continue;
					
					if(Math.abs(field[new_y][new_x] - field[current_y][current_x]) <= h)
					{
						//only add this vertex if the height is small enough
						queue_x.add(new_x);
						queue_y.add(new_y);
						visited[new_x][new_y] = true;
					}
				}
			}
			
		}
		
		if(visited[n-1][n-1]) System.out.println("yes");
		else System.out.println("no");
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