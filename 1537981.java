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
	
	public static void printAllCombinations(String c, String str)
	{
		if(str.length() == 1)
		{
			System.out.println(c + str);
		}
		else
		{
			for(int x = 0; x < str.length(); x++)
			{
				String temp = "";
				for(int y = 0; y < str.length(); y++)
				{
					if(y != x) temp += str.charAt(y);
				}
				printAllCombinations(c + str.substring(x, x + 1), temp);
			}
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		char[] c = readLine().toCharArray();
		Arrays.sort(c);
		String input = "";
		
		for(char x : c)
		{
			input += x;
		}
		
		printAllCombinations("", input);
		
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