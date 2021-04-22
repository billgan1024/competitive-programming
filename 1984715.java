import java.util.*;
import java.io.*;

public class WhoIsTaller {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		//construct a digraph adding a directed edge from a to b if b is taller than a
		//when checking the query, do BFS on a to b (if b is taller than a)
		//and then b to a (if a is taller than b)
		//if no result at the end, output is indeterminate
		
		int n = readInt(), m = readInt();
		ArrayList<Integer>[] adjList = new ArrayList[n];
		
		for(int i = 0; i < n; i++)
		{
			adjList[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0; i < m; i++)
		{
			int x = readInt()-1, y = readInt()-1;
			adjList[y].add(x);
		}
		
		int a = readInt()-1, b = readInt()-1;
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] visited = new boolean[n];
		
		queue.add(a);
		visited[a] = true; boolean a0 = false, b0 = false;
		
		while(!queue.isEmpty())
		{
		    if(a0) break;
			int currentVertex = queue.remove();
			for(int i = 0; i < adjList[currentVertex].size(); i++)
			{
				int neighbour = adjList[currentVertex].get(i);
				//if it is already visited, ignore
				if(visited[neighbour]) continue;
				//upon discovering a NEW unvisited vertex, mark it as visited and the
				//distance as this vertex's distance as 1 greater than the popped
				//vertex's distance
				visited[neighbour] = true; 
				if(visited[b]) { a0 = true; break; }
				//add the new vertex to the queue
				queue.add(neighbour);
			}
		}
		
		if(visited[b])
		{
			System.out.println("no"); return;
		}
		
		queue = new LinkedList<Integer>();
		visited = new boolean[n];
		
		queue.add(b);
		visited[b] = true;
		
		while(!queue.isEmpty())
		{
		    if(b0) break;
			int currentVertex = queue.remove();
			for(int i = 0; i < adjList[currentVertex].size(); i++)
			{
				int neighbour = adjList[currentVertex].get(i);
				//if it is already visited, ignore
				if(visited[neighbour]) continue;
				//upon discovering a NEW unvisited vertex, mark it as visited and the
				//distance as this vertex's distance as 1 greater than the popped
				//vertex's distance
				visited[neighbour] = true; if(visited[a]) { b0 = true; break; }
				//add the new vertex to the queue
				queue.add(neighbour);
			}
		}
		
		if(visited[a])
		{
			System.out.println("yes"); return;
		}
		
		System.out.println("unknown");

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