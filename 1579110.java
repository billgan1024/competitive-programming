import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class GraphExample
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		int[][] adjMatrix = new int[4][4];
		//edges tracker; tree must have n-1 edges
		int numEdges = 0;
		//also check if all rows are filled (each edge must be connected with the graph)
		boolean rowFilled = false;
		
		for(int x = 0; x < 4; x++)
		{
			rowFilled = false;
			for(int y = 0; y < 4; y++)
			{
				int val = readInt();
				if(val == 1)
				{
					rowFilled = true;
					if(adjMatrix[x][y] != 1)
					{
						adjMatrix[x][y] = 1;
						adjMatrix[y][x] = 1;
						numEdges++;
					}
				}
			}
			if(!rowFilled) break;
		}
		
		if(numEdges >= 4 || !rowFilled) System.out.println("No");
		else System.out.println("Yes");
		
		
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