import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Bananas {
	
	public static boolean isAWord(String s)
	{
		if(s.equals("A")) return true;
		else if(s.length() >= 3 && s.indexOf('B') != -1 && s.indexOf('S') != -1)
		{
			if(s.charAt(0) == 'B' && isMonkeyWord(s.substring(1, s.length() - 1)) && s.charAt(s.length() - 1) == 'S')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	
	public static boolean isMonkeyWord(String s)
	{
		if(isAWord(s)) return true;
		else if(s.length() >= 3)
		{
			//loop through all the indexes of n
			int index = s.indexOf('N');
			while(index != -1 && index != 0 && index != s.length() - 1)
			{
				if(isAWord(s.substring(0, index)) && isMonkeyWord(s.substring(index + 1)))
				{
					return true;
				}
				
				index++;
				index = s.indexOf('N', index);
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		String input = readLine().toUpperCase();
		
		while(!input.equals("X"))
		{
			if(isMonkeyWord(input)) System.out.println("YES");
			else System.out.println("NO");
			
			input = readLine().toUpperCase();
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