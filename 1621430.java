import java.util.*;
import java.io.*;

@SuppressWarnings({ "unchecked", "rawtypes" })
public class DFSExample {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;		
	static ArrayList<Integer>[] adjList = new ArrayList[10000];
	static ArrayList<Integer> currentPath = new ArrayList<Integer>();
	static boolean[] vis = new boolean[10000];
	static int result;
	
	
	public static void dfs(int n, int root, int target)
	{
		if(result != -1) return;
		for(int i : adjList[n])
		{
			if(!vis[i])
			{
				vis[i] = true;
				currentPath.add(i);
				dfs(i, root, target);
				currentPath.remove(currentPath.size()-1);
			}
			else if(i == root)
			{
				for(int j = 0; j < currentPath.size(); j++)
				{
					if(currentPath.get(j) == target)
					{
						result = j-1;
						break;
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		//maintain a visited array (just like bfs)
		//Applications of dfs
		//since all advancing arrows point to new vertices,
		//the graph with only the dfs advancing arrows must be a tree
		//since no advancing arrows point to a previously visited vertex
		
		//start dfs on a particular node
		//loop thru all of a node's unvisited neighbours
		//for each unvisited neighbour, set visited to true and dfs 
		//on that neighbour
		
		//To check if there is a cycle on an UNDIRECTED graph,
		//start dfs on any node
		//maintain a previous node (just like for finding a path with bfs)
		//when searching for unvisited neighbours, if
		//a neigbour is visited AND the neighbour is not the previous node visited,
		//this only works with an undirected graph
		
		//you can use dfs(currentVertex, prevVertex)
		
		//for a directed graph, maintain 3 states for the visited array
		//visited[u] = 0: not visited
		//visited[u] = 1: visited, in stack (pending)
		//visited[u] = 2: visited, out of stack (complete
		//when discovering an unvisited neighbour, mark it as 1
		//when u have discovered all unvisited neighbours, mark current vertex as 2
		//when u find an already visited vertex that is pending, that means
		//there is a cycle
		//however, if visited = 2, it is already complete and there isn't a cycle
		//You can also maintain a stack to get the collection of nodes
		//that form the cycle upon discovering it
		
		for(int i = 0; i < adjList.length; i++)
		{
			adjList[i] = new ArrayList<Integer>();
		}
		
		int n = readInt();
		for(int i = 0; i < n; i++) 
		{
			int x = readInt()-1, y = readInt()-1;
			adjList[x].add(y);
		}
		
		for(int k = 0; ; k++)
		{
			int x = readInt()-1, y = readInt()-1;
			if(x == -1 && y == -1) break;
			
			//start dfs on x
			//only search for cycles that lead back to the origin
			//once a cycle has been found, check the current path for the target node
			//print out the separation (distance from bottom (original) - 1)
			currentPath = new ArrayList<Integer>();
			vis = new boolean[10000];
			result = -1;
			
			vis[x] = true;
			currentPath.add(x);
			dfs(x, x, y);
			
			if(result != -1) System.out.println("Yes " + result);
			else System.out.println("No");
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