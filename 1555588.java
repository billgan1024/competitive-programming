import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TestCases {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<String> restrictions = new ArrayList<String>();
	static int maxLength = 0;
	
	public static void printAllWords(String s, int lastCharLevel)
	{
		//check if the current word meets the length criteria
		if(s.length() <= maxLength)
		{
			System.out.println(s);
		}
		else
		{
			return;
		}
		
		//recursively loop thru all possible extra words stemming from this word
		//the next character starts at the character level below the
		//last character of this words
		for(int i = lastCharLevel+1; i < restrictions.size(); i++)
		{
			for(int j = 0; j < restrictions.get(i).length(); j++)
			{
				printAllWords(s + restrictions.get(i).charAt(j), i);
			}
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		maxLength = readInt();
		for(int i = 0; i < n; i++)
		{
			int m = readInt();
			char[] c = new char[m];
			for(int j = 0; j < m; j++)
			{
				c[j] = next().charAt(0);
			}
			Arrays.sort(c);
			String s = "";
			for(char x : c)
			{
				s += x;
			}
			restrictions.add(s);
		}
		for(int i = 0; i < restrictions.get(0).length(); i++)
		{
			printAllWords(restrictions.get(0).charAt(i) + "", 0);
		}
		//System.out.println(restrictions);
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
	static String readLine () throws IOException {
	    return br.readLine().trim();
	}

}