import java.util.*;
import java.io.*;

public class ChooseYourOwnPath {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(); //number of pages (nodes)
		//need an adjacency list for this one and this is a directed graph
		//max 10000 edges
		ArrayList<Integer>[] adjList = new ArrayList[n];
		for(int i = 0; i < n; i++)
		{
			adjList[i] = new ArrayList<Integer>();
		}
		
		//list of ending pages (nodes)
		//shortest path is the minimum distance to an ending page
		ArrayList<Integer> endingPages = new ArrayList<Integer>();
		
		for(int i = 0; i < n; i++)
		{
			int numChoices = readInt();
			if(numChoices == 0) endingPages.add(i); //this is an ending page
			else
			{
				for(int j = 0; j < numChoices; j++)
				{
					//adds this node's neighbours (only one way tho)
					adjList[i].add(readInt()-1);
				}
			}
		}
		//now that we have a graph, run BFS starting from page 1 (node 0)
		Queue<Integer> queue = new LinkedList<Integer>();
		int[] distance = new int[n];
		
		//visited array marking each vertex as visited or unvisited
		boolean[] visited = new boolean[n];
		
		//push page 1 (node 0) into the queue
		queue.add(0);
		visited[0] = true;
		distance[0] = 0;
		
		while(!queue.isEmpty())
		{
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
				distance[neighbour] = distance[currentVertex] + 1;
				//add the new vertex to the queue
				queue.add(neighbour);
			}
		}
		
		//check for any unvisited nodes
		boolean everyPage = true;
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				everyPage = false;
				break;
			}
		}
		
		if(everyPage) System.out.println("Y");
		else System.out.println("N");
		
		//print out shortest distance
		int shortestDistance = Integer.MAX_VALUE;
		for(int i = 0; i < endingPages.size(); i++)
		{
			if(!visited[endingPages.get(i)]) continue;
			shortestDistance = Math.min(shortestDistance, distance[endingPages.get(i)]);
		}
		
		System.out.println(shortestDistance + 1);

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