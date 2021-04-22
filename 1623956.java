import java.util.*;
import java.io.*;

public class PyramidScheme {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		for(int u = 0; u < n; u++)
		{
			int a = readInt(), b = readInt(), c = readInt();
			String[] subjects = new String[a];
			String[] verbs = new String[b];
			String[] objects = new String[c];
			
			for(int i = 0; i < a; i++)
			{
				subjects[i] = readLine();
			}
			for(int i = 0; i < b; i++)
			{
				verbs[i] = readLine();
			}
			for(int i = 0; i < c; i++)
			{
				objects[i] = readLine();
			}
			
			for(int x = 0; x < a; x++)
			{
				for(int y = 0; y < b; y++)
				{
					for(int z = 0; z < c; z++)
					{
						System.out.println(subjects[x] + " " + verbs[y] + " " + objects[z] + ".");
					}
				}
			}
			System.out.println("");
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