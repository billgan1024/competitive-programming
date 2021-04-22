import java.util.*;
import java.io.*;

public class Ants {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt();
		
		ArrayList<Integer>[] adjList = new ArrayList[n];
		for(int i = 0; i < n; i++)
		{
			adjList[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0; i < m; i++)
		{
			int x = readInt()-1, y = readInt()-1;
			adjList[x].add(y);
			adjList[y].add(x);
		}
		
		//bfs using all ant locations as sources
		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] visited = new boolean[n];
		int[] antDistances = new int[n];
		Arrays.fill(antDistances, Integer.MAX_VALUE);
		
		int w = readInt();
		for(int i = 0; i < w; i++)
		{
			int a = readInt()-1;
			queue.add(a);
			visited[a] = true;
			antDistances[a] = 0;
		}
		
		while(!queue.isEmpty())
		{
			int currentVertex = queue.remove();
			
			for(int i = 0; i < adjList[currentVertex].size(); i++)
			{
				int neighbour = adjList[currentVertex].get(i);
				if(visited[neighbour]) continue;
				
				visited[neighbour] = true;
				antDistances[neighbour] = antDistances[currentVertex] + 4;
			}
		}
		
		
		//find a path from 1 to n
		queue = new LinkedList<Integer>();
		visited = new boolean[n];
		int[] distance = new int[n];
		
		queue.add(0);
		visited[0] = true;
		distance[0] = 0;
		
		while(!queue.isEmpty())
		{
			int currentVertex = queue.remove();
			
			for(int i = 0; i < adjList[currentVertex].size(); i++)
			{
				int neighbour = adjList[currentVertex].get(i);
				if(visited[neighbour]) continue;
				if(distance[currentVertex] + 1 >= antDistances[neighbour]) continue;
				
				visited[neighbour] = true;
				distance[neighbour] = distance[currentVertex] + 1;
				queue.add(neighbour);
			}
		}
		
		if(!visited[n-1]) System.out.println("sacrifice bobhob314");
		else System.out.println(distance[n-1]);

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