import java.util.*;
import java.io.*;

public class AllRoads {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int m = readInt(), n = readInt();
		ArrayList<Integer>[] adjList = new ArrayList[26];
		
		for(int i = 0; i < adjList.length; i++)
		{
			adjList[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0; i < m; i++)
		{
			int s = next().toLowerCase().charAt(0) - 'a', e = next().toLowerCase().charAt(0) - 'a';
			adjList[s].add(e);
			adjList[e].add(s);
		}
		
		for(int i = 0; i < n; i++)
		{
			int s = next().toLowerCase().charAt(0) - 'a', e = next().toLowerCase().charAt(0) - 'a';
			
			Queue<Integer> queue = new LinkedList<Integer>();
			boolean[] visited = new boolean[26];
			int[] prev = new int[26];
			
			queue.add(s);
			visited[s] = true;
			prev[s] = -1;
			
			while(!queue.isEmpty())
			{
				int currentVertex = queue.remove();
				
				for(int j = 0; j < adjList[currentVertex].size(); j++)
				{
					int neighbour = adjList[currentVertex].get(j);
					if(visited[neighbour]) continue;
					
					visited[neighbour] = true;
					prev[neighbour] = currentVertex;
					queue.add(neighbour);
				}
			}
			
			String path = "";
			//recall this path
			for(int j = e; j != -1; j = prev[j])
			{
				path = (char)(j + 'a') + path;
			}
			
			path = path.toUpperCase();
			System.out.println(path);
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