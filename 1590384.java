import java.util.*;
import java.io.*;

public class TrailBuilding {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int k = readInt();
		
		if(k == 0)
		{
			//no connected pairs
			System.out.println("1 0");
		}
		else
		{
			//List of cycles
			ArrayList<Integer> maxNodeCycles = new ArrayList<Integer>();
			int edges = 0;
			while(k > 0)
			{
				//find largest n(n-1)/2 that is less than or equal to k
				//remember, a graph with n edges and n vertices can be connected
				//in a circle to create n(n-1)/2 beautifully connected pairs
				double sol = (1.0 + Math.sqrt(1.0+8.0*k))/2;
				int n = (int) Math.floor(sol);
				
				maxNodeCycles.add(n);
				edges += n;
				
				//this will take care of n(n-1)/2 connected pairs
				k -= n*(n-1)/2;
			}
			int vertices = edges;
			edges += maxNodeCycles.size()-1;
			
			
			//print number of nodes and edges
			System.out.println(vertices + " " + edges);
			
			int nodeCounter = 1;
			
			//print out all the cycles
			for(int i = 0; i < maxNodeCycles.size(); i++)
			{
				//connect the previous cycle to this one
				if(i > 0)
				{
					System.out.println((nodeCounter - 1) + " " + nodeCounter);
				}
				//construct this cycle
				for(int j = 0; j < maxNodeCycles.get(i) - 1; j++)
				{
					System.out.println(nodeCounter + " " + (nodeCounter + 1));
					nodeCounter++;
				}
				//link the last node back 
				System.out.println(nodeCounter + " " + (nodeCounter-maxNodeCycles.get(i)+1));
				nodeCounter++;
				
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