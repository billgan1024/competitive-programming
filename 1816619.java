import java.util.*;
import java.io.*;

public class MedianProblem {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Point
	{
		int row, col;
		public Point(int row, int col) { this.row = row; this.col = col; }
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int c = readInt(), r = readInt(); char[][] grid = new char[r][c];
		Queue<Point> queue = new LinkedList<Point>(); boolean[][] vis = new boolean[r][c];
		for(int i = 0; i < r; i++) {
			String s = readLine();
			for(int j = 0; j < c; j++) {
				grid[i][j] = s.charAt(j);
				if(grid[i][j] == '1') { vis[i][j] = true; queue.add(new Point(i, j)); }
			}
		}
		ArrayList<Integer> spots = new ArrayList<Integer>(); spots.add(1);
		int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		while(!queue.isEmpty()) {
			Point p = queue.remove(); int cur_r = p.row, cur_c = p.col;
	        for(int i=0; i<4; i++){
	            int new_r = cur_r + dir[i][0], new_c = cur_c+dir[i][1];
	            if(new_r >= 0 && new_r < r && new_c >= 0 && new_c < c)
	            {
	                if(vis[new_r][new_c]) continue;
	                if(grid[new_r][new_c] == '#') continue;
	                vis[new_r][new_c] = true; queue.add(new Point(new_r, new_c));

	                if(grid[new_r][new_c] != 'O') {
		                spots.add(Character.getNumericValue(grid[new_r][new_c]));
	                }
	            }
	        }
		}
		Collections.sort(spots); for(int i : spots) System.out.print(i + " ");
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
}