import java.util.*;
import java.io.*;

public class BadBunnies {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt(), r = readInt();
		
		@SuppressWarnings("unchecked")
		ArrayList<Integer>[] adjList = new ArrayList[n];
		for(int i = 0; i < n; i++)
		{
			adjList[i] = new ArrayList<Integer>();
		}
		
		//nodes that contain rabbits
		int[] rabbits = new int[r];
		
		for(int i = 0; i < n-1; i++)
		{
			int a = readInt()-1, b = readInt()-1;
			adjList[a].add(b);
			adjList[b].add(a);
		}
		
		for(int i = 0; i < r; i++)
		{
			rabbits[i] = readInt()-1;
		}
		
		int start = readInt()-1, end = readInt()-1;
		
		//push all rabbit nodes into the queue (multiple sources)
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] visited = new boolean[n];
		//shortest distance from a node to a rabbit
		int[] rabbitDistance = new int[n];
		
		
		for(int i = 0; i < r; i++)
		{
			queue.add(rabbits[i]);
			visited[rabbits[i]] = true;
			rabbitDistance[rabbits[i]] = 0;
		}
		
		while(!queue.isEmpty())
		{
			int currentVertex = queue.remove();
			
			for(int i = 0; i < adjList[currentVertex].size(); i++)
			{
				int neighbour = adjList[currentVertex].get(i);
				//if it is already visited, ignore
				if(visited[neighbour]) continue;
				
				//update prev array when discovering a new vertex
				visited[neighbour] = true;
				rabbitDistance[neighbour] = rabbitDistance[currentVertex] + 1;
				//add the new vertex to the queue
				queue.add(neighbour);
			}
		}
		
		queue = new LinkedList<Integer>();
		//start bfs from start to end node, recall the path
		//on each node of the path, update min distance to any rabbit
		visited = new boolean[n];
		int[] prev = new int[n];
		
		queue.add(start);
		visited[start] = true;
		prev[start] = -1;
		
		while(!queue.isEmpty())
		{
			int currentVertex = queue.remove();
			
			for(int i = 0; i < adjList[currentVertex].size(); i++)
			{
				int neighbour = adjList[currentVertex].get(i);
				//if it is already visited, ignore
				if(visited[neighbour]) continue;
				
				//update prev array when discovering a new vertex
				visited[neighbour] = true;
				prev[neighbour] = currentVertex;
				//add the new vertex to the queue
				queue.add(neighbour);
			}
		}
		
		int minDistance = Integer.MAX_VALUE;
		
		//retrace path
		for(int i = end; i != -1; i = prev[i])
		{
			minDistance = Math.min(minDistance, rabbitDistance[i]);
		}
		System.out.println(minDistance);
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