import java.util.*;
import java.io.*;

public class StrategicBombing {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int[][] adj = new int[26][26];
		ArrayList<Integer> edge_start = new ArrayList<Integer>();
		ArrayList<Integer> edge_end = new ArrayList<Integer>();

		String input = next();
		while(!input.equals("**"))
		{
			int start = input.toLowerCase().charAt(0)-'a';
			int end = input.toLowerCase().charAt(1)-'a';
			
			edge_start.add(start);
			edge_end.add(end);
			
			adj[start][end] = 1;
			adj[end][start] = 1;
			input = next();
		}
		
		int count = 0;
		
		for(int i = 0; i < edge_start.size(); i++)
		{
			Queue<Integer> queue = new LinkedList<Integer>();
			boolean[] visited = new boolean[26];
			
			adj[edge_start.get(i)][edge_end.get(i)] = 0;
			adj[edge_end.get(i)][edge_start.get(i)] = 0;
			
			queue.add(0);
			visited[0] = true;
			
			//while the queue is not empty, pop the vertex from the top
			//at the first time, the top will be the start vertex
			//store current popped vertex as a temp variable
			
			while(!queue.isEmpty())
			{
				int currentVertex = queue.remove();
				
				
				for(int j = 0; j < adj[currentVertex].length; j++)
				{
					//loop thru ALL of this vertex's neighbours 
					if(adj[currentVertex][j] == 1)
					{
						//if it is already visited, ignore
						if(visited[j]) continue;
						visited[j] = true;
						queue.add(j);
					}
				}
			}
			
			if(!visited[1])
			{
				count++;
				String s = "";
				s += (char)(edge_start.get(i) + 'a');
				s += (char)(edge_end.get(i) + 'a');
				System.out.println(s.toUpperCase());
			}
			
			adj[edge_start.get(i)][edge_end.get(i)] = 1;
			adj[edge_end.get(i)][edge_start.get(i)] = 1;
		}
		System.out.println("There are " + count + " disconnecting roads.");
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