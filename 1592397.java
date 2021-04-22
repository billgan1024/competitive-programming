import java.util.*;
import java.io.*;

public class KnightHop {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		//adjacency list with 64x64 cells
		int[][] adj = new int[64][64];
		
		//loop thru chess grid, assigning edges to all available squares
		//a knight can jump to from each square
		//to turn a square (2D coordinate) into a node (1D number), 
		//take (8*y) + x (refer to diagram)
		for(int y = 0; y < 8; y++)
		{
			for(int x = 0; x < 8; x++)
			{
				//add edges to all applicable nodes
				int node = 8 * y + x;
				
				//test all 8 directions
				if(y-2 >= 0)
				{
					if(x-1 >= 0)
					{
						adj[node][8 * (y-2) + (x-1)] = 1;
					}
					if(x+1 < 8)
					{
						adj[node][8 * (y-2) + (x+1)] = 1;
					}
				}
				if(y+2 < 8)
				{
					if(x-1 >= 0)
					{
						adj[node][8 * (y+2) + (x-1)] = 1;
					}
					if(x+1 < 8)
					{
						adj[node][8 * (y+2) + (x+1)] = 1;
					}
				}
				
				if(x-2 >= 0)
				{
					if(y-1 >= 0)
					{
						adj[node][8 * (y-1) + (x-2)] = 1;
					}
					if(y+1 < 8)
					{
						adj[node][8 * (y+1) + (x-2)] = 1;
					}
				}
				if(x+2 < 8)
				{
					if(y-1 >= 0)
					{
						adj[node][8 * (y-1) + (x+2)] = 1;
					}
					if(y+1 < 8)
					{
						adj[node][8 * (y+1) + (x+2)] = 1;
					}
				}
			}
		}
		
		//read start node and end node
		int x = readInt()-1, y = readInt()-1;
		int x2 = readInt()-1, y2 = readInt()-1;
		if(x2 == x && y2 == y) System.out.println("0");
		else
		{
			int start = 8 * y + x;
			int end = 8 * y2 + x2;
			
			//start a BFS from start node
			Queue<Integer> queue = new LinkedList<Integer>();
			int[] distance = new int[64];
			
			//visited array marking each vertex as visited or unvisited
			boolean[] visited = new boolean[64];
			
			//push starting node into the queue
			queue.add(start);
			visited[start] = true;
			distance[start] = 0;
			
			while(!queue.isEmpty())
			{
				int currentVertex = queue.remove();
				
				for(int i = 0; i < adj[currentVertex].length; i++)
				{
					//loop thru ALL of this vertex's neighbours 
					if(adj[currentVertex][i] == 1)
					{
						//if it is already visited, ignore
						if(visited[i]) continue;
						//upon discovering a NEW unvisited vertex, mark it as visited and the
						//distance as this vertex's distance as 1 greater than the popped
						//vertex's distance
						visited[i] = true;
						distance[i] = distance[currentVertex] + 1;
						if(i == end)
						{
							System.out.println(distance[i]);
							return;
						}
						//add the new vertex to the queue
						queue.add(i);
					}
				}
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
}