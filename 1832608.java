import java.util.*;
import java.io.*;

public class AKnightlyPursuit {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		for(int t = 0; t < n; t++)
		{
			int r = readInt(), c = readInt(), pr = r-readInt(), pc = readInt()-1, kr = r-readInt(), kc = readInt()-1;
			if(kr == pr-1 && kc == pc) { System.out.println("Stalemate in 0 knight move(s)."); continue; }
			int[][] dis = new int[r][c]; boolean[][] vis = new boolean[r][c];
			Queue<Integer> queue_r = new LinkedList<Integer>(), queue_c = new LinkedList<Integer>();
			boolean canMove = false;
			vis[kr][kc] = true; queue_r.add(kr); queue_c.add(kc);
			
			int[][] dir = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
			
			while(!queue_r.isEmpty()) {
				int cur_r = queue_r.remove(), cur_c = queue_c.remove();
				for(int i = 0; i < 8; i++)
				{
					int new_r = cur_r + dir[i][0], new_c = cur_c + dir[i][1];
					if(new_r >= 0 && new_r < r && new_c >= 0 && new_c < c)
					{
						if(vis[new_r][new_c]) continue;
						canMove = true;
						vis[new_r][new_c] = true; dis[new_r][new_c] = dis[cur_r][cur_c] + 1;
						queue_r.add(new_r); queue_c.add(new_c);
					}
				}
			}
			
			int count = 1; boolean found = false; 
			for(int cur_r = pr - 1; cur_r > 0; cur_r--)
			{
				if(vis[cur_r][pc] && dis[cur_r][pc] <= count && dis[cur_r][pc]%2 == count%2)
				{
					System.out.println("Win in " + (count) + " knight move(s).");
					found = true; break;
				}
				count++;
			}
			
			if(!found)
			{
				count = 1;
				for(int cur_r = pr - 2; cur_r >= 0; cur_r--)
				{
					if(vis[cur_r][pc] && dis[cur_r][pc] <= count && dis[cur_r][pc]%2 == count%2)
					{
						System.out.println("Stalemate in " + count + " knight move(s).");
						found = true; break;
					}
					count++;
				}
			}
			if(!found)
			{
				if(!canMove) System.out.println("Loss in 0 knight move(s)."); 
				else System.out.println("Loss in " + Math.max(pr-1, 0) + " knight move(s).");
			}
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