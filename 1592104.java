import java.util.*;
import java.io.*;

public class Shahir {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		//BFS requires a queue to keep track of the next vertex to visit
		Queue<Integer> queue = new LinkedList<Integer>();
		
		int n = readInt();
		int m = readInt();
		
		int start = readInt()-1;
		int dest = readInt()-1;
		
		//adjacency matrix representing the array
		int[][] adj = new int[n][n];
		
		for(int i = 0; i < m; i++)
		{
			//add all the edges
			int from = readInt()-1;
			int to = readInt()-1;
			
			adj[from][to] = 1;
			adj[to][from] = 1;
		}
		
		//distance array showing the "levels" of each vertex from the starting vertex
		//note: distance from start vertex to itself is level 0.
		
		int[] distance = new int[n];
		for(int i = 0; i < distance.length; i++)
		{
			distance[i] = -1;
		}
		
		//visited array marking each vertex as visited or unvisited
		boolean[] visited = new boolean[n];
	
		
		//whenever we discover a NEW vertex u:
		//push u to the end of the queue
		//mark u as visited in the visited array
		//update the distance ("level") of vertex u
		
		//Start by pushing the start vertex into the queue and updating
		//visited and distance array
		queue.add(start);
		visited[start] = true;
		distance[start] = 0;
		
		//while the queue is not empty, pop the vertex from the top
		//at the first time, the top will be the start vertex
		//store current popped vertex as a temp variable
		
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
					//add the new vertex to the queue
					queue.add(i);
				}
			}
		}
		
		//check if destination is reachable
		if(distance[dest] == -1)
		{
			System.out.println("NO SHAHIR!");
		}
		else
		{
			System.out.println("GO SHAHIR!");
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