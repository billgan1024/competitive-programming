import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		String s = readLine();
		int[][] prefix = new int[s.length()][26];
		prefix[0][s.charAt(0)-'a']++;
		for(int i = 1; i < s.length(); i++)
		{
			for(int j = 0; j < 26; j++)
			{
				prefix[i][j] = prefix[i-1][j];
			}
			if(s.charAt(i) != ' ')
			{
				prefix[i][s.charAt(i)-'a']++;
			}
		}
		int q = readInt();
		for(int i = 0; i < q; i++)
		{
			int a = readInt()-1, b = readInt()-1;
			char c = next().charAt(0);
			
			if(a == 0)
			{
				System.out.println(prefix[b][c-'a']);
			}
			else
			{
				System.out.println(prefix[b][c-'a'] - prefix[a-1][c-'a']);
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