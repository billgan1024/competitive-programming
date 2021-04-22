import java.util.*;
import java.io.*;

public class PursuitOfKnowledge {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(), t = readInt();
		
		ArrayList<Integer>[] adjList = new ArrayList[n];
		for(int i = 0; i < n; i++)
		{
			adjList[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0; i < m; i++)
		{
			int a = readInt()-1, b = readInt()-1;
			adjList[a].add(b);
		}
		int q = readInt();
		for(int i = 0; i < q; i++)
		{
			Queue<Integer> queue = new LinkedList<Integer>();
			boolean[] vis = new boolean[n];
			int[] distance = new int[n];
			
			int a = readInt()-1, b = readInt()-1;
			
			queue.add(a);
			vis[a] = true;
			distance[a] = 0;
			
			int result = -1;
			
			while(!queue.isEmpty() && result == -1)
			{
				int cur = queue.remove();
				for(int j : adjList[cur])
				{
					if(vis[j]) continue;
					vis[j] = true;
					distance[j] = distance[cur] + 1;
					
					if(j == b) 
					{
						result = distance[j] * t;
						break;
					}
					
					queue.add(j);
				}
			}
			
			if(result == -1) System.out.println("Not enough hallways!");
			else System.out.println(result);
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