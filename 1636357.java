import java.util.*;
import java.io.*;

public class Bridges {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		for(int e = 0; e < 5; e++)
		{
			int n = readInt(), m = readInt();
			int[][] adj = new int[n][n];
			
			int[] startEdges = new int[m];
			int[] endEdges = new int[m];
			for(int i = 0; i < m; i++)
			{
				int a = readInt()-1, b = readInt()-1;
				startEdges[i] = a;
				endEdges[i] = b;
				adj[a][b] = 1;
				adj[b][a] = 1;
			}
			
			int bridges = 0;
			for(int i = 0; i < m; i++)
			{
				adj[startEdges[i]][endEdges[i]] = 0;
				adj[endEdges[i]][startEdges[i]] = 0;
				
				//bfs from start edge to end edge (check visited)
				Queue<Integer> queue = new LinkedList<Integer>();
				boolean[] vis = new boolean[n];
				queue.add(startEdges[i]);
				vis[startEdges[i]] = true;
				boolean found = false;
				
				while(!queue.isEmpty() && !found)
				{
					int cur = queue.remove();
					for(int j = 0; j < adj[cur].length; j++)
					{
						if(adj[cur][j] == 1)
						{
							if(j == endEdges[i])
							{
								found = true;
								break;
							}
							if(vis[j]) continue;
							vis[j] = true;
							queue.add(j);
						}
					}
				}
				
				if(!found) bridges++;
				
				adj[startEdges[i]][endEdges[i]] = 1;
				adj[endEdges[i]][startEdges[i]] = 1;
			}
			System.out.println(bridges);
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