import java.util.*;
import java.io.*;

public class Harambe {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		String[] words = new String[n];
		
		for(int i = 0; i < n; i++)
		{
			words[i] = next();
			int j = i;
			while(j > 0 && words[j].length() < words[j-1].length())
			{
				String temp = words[j];
				words[j] = words[j-1];
				words[j-1] = temp;
				j--;
			}
		}
	
		
		String s = readLine();
		String resultWord = "";
		
		for(int i = 0; i < n; i++)
		{
			if(words[i].length() <= s.length())
			{
				resultWord = words[i];
			}
			else
			{
				break;
			}
		}
		System.out.println(resultWord);

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