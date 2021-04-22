import java.util.*;
import java.io.*;

public class HideAndSeek {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int minLength = Integer.MAX_VALUE;
	static int sum = 0;
	static ArrayList<Integer> currentPath = new ArrayList<Integer>();
	static int t;
	
	static class Hider
	{
		int r, c, id;
		public Hider(int r, int c, int id)
		{
			this.r = r; this.c = c; this.id = id;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int rows = readInt(), cols = readInt();
		t = readInt();
		
		char[][] grid = new char[rows][cols];
		
		ArrayList<Hider> hiderData = new ArrayList<Hider>();
		
		int id = 0;
		int start_r = -1, start_c = -1;
		for(int r = 0; r < rows; r++)
		{
			String s = readLine();
			for(int c = 0; c < cols; c++)
			{
				grid[r][c] = s.charAt(c);
				if(grid[r][c] == 'H')
				{
					hiderData.add(new Hider(r, c, id));
					id++;
				}
				if(grid[r][c] == 'G')
				{
					start_r = r; start_c = c;
				}
			}
		}
		
		int[] disToHiders = new int[t];
		Queue<Integer> queue_r = new LinkedList<Integer>();
		Queue<Integer> queue_c = new LinkedList<Integer>();
		boolean[][] vis = new boolean[rows][cols];
		int[][] dis = new int[rows][cols];
		
		queue_r.add(start_r); queue_c.add(start_c);
		vis[start_r][start_c] = true;
		
		
		while(!queue_r.isEmpty())
		{
			int cur_r = queue_r.remove(), cur_c = queue_c.remove();
			int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
			
			for(int i = 0; i < dir.length; i++)
			{
				int new_r = cur_r + dir[i][0];
				int new_c = cur_c + dir[i][1];
				
				if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols)
				{
					if(vis[new_r][new_c]) continue;
					if(grid[new_r][new_c] == 'X') continue;
					vis[new_r][new_c] = true;
					dis[new_r][new_c] = dis[cur_r][cur_c] + 1;
					if(grid[new_r][new_c] == 'H')
					{
						//update the distance from griffy to each of the hiders
						for(Hider h : hiderData)
						{
							if(h.r == new_r && h.c == new_c)
							{
								disToHiders[h.id] = dis[new_r][new_c];
								break;
							}
						}
					}
					queue_r.add(new_r); queue_c.add(new_c);
				}
			}
		}
		
		int[][] hiderDis = new int[t][t];
		
		for(Hider h : hiderData)
		{
			vis = new boolean[rows][cols];
			dis = new int[rows][cols];
			
			queue_r.add(h.r); queue_c.add(h.c);
			vis[h.r][h.c] = true;
			
			while(!queue_r.isEmpty())
			{
				int cur_r = queue_r.remove(), cur_c = queue_c.remove();
				int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
				
				for(int i = 0; i < dir.length; i++)
				{
					int new_r = cur_r + dir[i][0];
					int new_c = cur_c + dir[i][1];
					
					if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols)
					{
						if(vis[new_r][new_c]) continue;
						if(grid[new_r][new_c] == 'X') continue;
						vis[new_r][new_c] = true;
						dis[new_r][new_c] = dis[cur_r][cur_c] + 1;
						
						if(grid[new_r][new_c] == 'H')
						{
							//update the distance from this hider to each of the hiders
							for(Hider hider : hiderData)
							{
								if(hider.r == new_r && hider.c == new_c)
								{
									 hiderDis[h.id][hider.id] = dis[new_r][new_c];
									 break;
								}
							}
						}
						queue_r.add(new_r); queue_c.add(new_c);
					}
				}
			}
		}
		
		for(int i = 0; i < disToHiders.length; i++)
		{
			sum += disToHiders[i];
			currentPath.add(i);
			
			findMinSum(hiderDis);
			
			sum -= disToHiders[i];
			currentPath.remove(currentPath.size()-1);
		}
		
		System.out.println(minLength);

	}
	
	public static void findMinSum(int[][] hiderDis)
	{
		//base case
		if(currentPath.size() == t)
		{
			minLength = Math.min(minLength, sum);
		}
		else
		{
			for(int i = 0; i < hiderDis.length; i++)
			{
				if(currentPath.contains(i)) continue;
				//test this case
				sum += hiderDis[currentPath.get(currentPath.size()-1)][i];
				currentPath.add(i);
				
				findMinSum(hiderDis);
				
				sum -= hiderDis[currentPath.get(currentPath.size()-2)][i];
				currentPath.remove(currentPath.size()-1);
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

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}

	public static int lower_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] >= x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}

	public static int upper_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] > x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}
}