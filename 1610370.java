import java.util.*;
import java.io.*;

public class DegreesOfSeparation {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>();
		
		for(int i = 0; i < 49; i++)
		{
			adjList.add(new ArrayList<Integer>());
		}
		
		adjList.get(0).add(5);
		adjList.get(1).add(5);
		adjList.get(2).add(14); adjList.get(2).add(3); adjList.get(2).add(4); adjList.get(2).add(5);
		adjList.get(3).add(5); adjList.get(3).add(4); adjList.get(3).add(2);
		adjList.get(4).add(5); adjList.get(4).add(3); adjList.get(4).add(2);
		adjList.get(5).add(0); adjList.get(5).add(1); adjList.get(5).add(2); adjList.get(5).add(3); adjList.get(5).add(4); adjList.get(5).add(6);
		adjList.get(6).add(5); adjList.get(6).add(7);
		adjList.get(7).add(8); adjList.get(7).add(6);
		adjList.get(8).add(7); adjList.get(8).add(9); adjList.get(8).add(11);
		adjList.get(9).add(8); adjList.get(9).add(10);
		adjList.get(10).add(9); adjList.get(10).add(11);
		adjList.get(11).add(8); adjList.get(11).add(10); adjList.get(11).add(12);
		adjList.get(12).add(11); adjList.get(12).add(13); adjList.get(12).add(14);
		adjList.get(13).add(12);
		adjList.get(14).add(12); adjList.get(14).add(2);
		adjList.get(15).add(16); adjList.get(15).add(17);
		adjList.get(16).add(15); adjList.get(16).add(17);
		adjList.get(17).add(15); adjList.get(17).add(16);
		
		
		
		for(int i = 0;; i++)
		{
			String s = next();
			if(s.equals("i"))
			{
				int x = readInt()-1, y = readInt()-1;
				
				if(!adjList.get(x).contains(y))
				{
					adjList.get(x).add(y);
					adjList.get(y).add(x);
				}
			}
			else if(s.equals("d"))
			{
				int x = readInt()-1, y = readInt()-1;
				adjList.get(x).remove(new Integer(y));
				adjList.get(y).remove(new Integer(x));
			}
			else if(s.equals("n"))
			{
				int x = readInt()-1;
				System.out.println(adjList.get(x).size());
			}
			else if(s.equals("f"))
			{
				int x = readInt()-1;
				Queue<Integer> queue = new LinkedList<Integer>();
				boolean[] visited = new boolean[49];
				int[] distance = new int[49];
				
				queue.add(x);
				distance[x] = 0;
				visited[x] = true;
				int count = 0;
				

				while(!queue.isEmpty())
				{
					int currentVertex = queue.remove();
					
					for(int j = 0; j < adjList.get(currentVertex).size(); j++)
					{
						int neighbour = adjList.get(currentVertex).get(j);
						//if it is already visited, ignore
						if(visited[neighbour]) continue;
						//upon discovering a NEW unvisited vertex, mark it as visited and the
						//distance as this vertex's distance as 1 greater than the popped
						//vertex's distance
						visited[neighbour] = true;
						distance[neighbour] = distance[currentVertex] + 1;
						if(distance[neighbour] == 2) count++;
						//add the new vertex to the queue
						queue.add(neighbour);
					}
				}
				System.out.println(count);
			}
			else if(s.equals("s"))
			{
				int x = readInt()-1, y = readInt()-1;
				Queue<Integer> queue = new LinkedList<Integer>();
				boolean[] visited = new boolean[49];
				int[] distance = new int[49];
				
				queue.add(x);
				distance[x] = 0;
				visited[x] = true;
				

				while(!queue.isEmpty())
				{
					int currentVertex = queue.remove();
					
					for(int j = 0; j < adjList.get(currentVertex).size(); j++)
					{
						int neighbour = adjList.get(currentVertex).get(j);
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
				
				if(!visited[y]) System.out.println("Not connected");
				else System.out.println(distance[y]);
			}
			else if(s.equals("q"))
			{
				return;
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