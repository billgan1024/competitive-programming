import java.util.*;
import java.io.*;

public class DigraphConnectivity {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt();
		
		ArrayList<ArrayList<Integer>> edgesToDelete = new ArrayList<ArrayList<Integer>>();
		//adj matrix
		int[][] adj = new int[n][n];
		
		for(int i = 0; i < m; i++)
		{
			//add edges
			int start = readInt()-1, dest = readInt()-1;
			adj[start][dest] = 1;
			ArrayList<Integer> temp = new ArrayList<Integer>();
			
			temp.add(start);
			temp.add(dest);
			edgesToDelete.add(temp);
		}
		
		for(int i = 0; i < edgesToDelete.size(); i++)
		{
			int startDelete = edgesToDelete.get(i).get(0);
			int endDelete = edgesToDelete.get(i).get(1);
			
			adj[startDelete][endDelete] = 0;
			
			Queue<Integer> queue = new LinkedList<Integer>();
			int[] distance = new int[n];
			boolean[] visited = new boolean[n];
			
			queue.add(0);
			visited[0] = true;
			distance[0] = 0;
			
			boolean found = false;
			while(!queue.isEmpty() && !found)
			{
				int currentVertex = queue.remove();
				
				for(int j = 0; j < adj[currentVertex].length; j++)
				{
					//loop thru ALL of this vertex's neighbours 
					if(adj[currentVertex][j] == 1)
					{
						if(j == n-1)
						{
							//found a path
							System.out.println("YES");
							found = true;
							break;
						}
						//if it is already visited, ignore
						if(visited[j]) continue;
						//upon discovering a NEW unvisited vertex, mark it as visited and the
						//distance as this vertex's distance as 1 greater than the popped
						//vertex's distance
						visited[j] = true;
						distance[j] = distance[currentVertex] + 1;
						//add the new vertex to the queue
						queue.add(j);
					}
				}
			}
			
			if(!found) System.out.println("NO");
			
			
			adj[startDelete][endDelete] = 1;
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