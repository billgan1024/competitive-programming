import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Homework {
	
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		//list showing the primacity of each number
		int[] primacity = new int[10000001];
		//map each primacity number to a list of numbers (1-8 primacity)
		ArrayList<Integer>[] numPrimacity = new ArrayList[9];
		
		for(int i = 1; i < numPrimacity.length; i++)
		{
			numPrimacity[i] = new ArrayList<Integer>();
		}
		
		for(int x = 2; x < primacity.length; x++)
		{
			if(primacity[x] == 0)
			{
				for(int y = x; y < primacity.length; y += x)
				{
					primacity[y]++;
				}
			}
			
			//add and hash it to numPrimacity
			numPrimacity[primacity[x]].add(x);
		}
		
		//largest primacity is 8
		
		int t = readInt();
		for(int x = 1; x <= t; x++)
		{
			int a = readInt(), b = readInt(), k = readInt();
			int nums = 0;
			if(k <= 8)
			{
				int lowerIndex = Collections.binarySearch(numPrimacity[k], a);
				int higherIndex = Collections.binarySearch(numPrimacity[k], b);
				
				if(lowerIndex < 0) lowerIndex = -(lowerIndex + 1);
				if(higherIndex < 0) higherIndex = -(higherIndex + 1) - 1;
				
				nums = higherIndex - lowerIndex + 1;
			}
			
			System.out.println("Case #" + x + ": " + nums);
		}
		
	}
	
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}

}