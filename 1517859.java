import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		int m = Integer.parseInt(in.readLine());
		
		String[] adj = new String[n];
		
		for(int x = 0; x < n; x++)
		{
			adj[x] = in.readLine();
		}
		
		for(int x = 0; x < m; x++)
		{
			String noun = in.readLine();
			for(int y = 0; y < adj.length; y++)
			{
				System.out.println(adj[y] + " as " + noun);
			}
		}
	}
}