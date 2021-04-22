import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void printAllCombinations(ArrayList<Integer> c)
	{
		c.set(0, 0);
	}
	
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		
		for(int i = 0; i < n; i++)
		{
			String s = readLine();
			char c = s.charAt(0);
			int count = 1;
			
			for(int j = 1; j < s.length(); j++)
			{
				if (s.charAt(j) == s.charAt(j-1)) count++;
				else
				{
					System.out.print(count  + " " + String.valueOf(c) + " ");
					count = 1;
					c = s.charAt(j);
				}
			}
			
			System.out.println(count  + " " + String.valueOf(c));
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