import java.io.*;
import java.util.*;
public class Test
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException
	{
		int n = readInt(), x = readInt();
		int[] calls = new int[n];
		for(int i = 0; i < n; i++)
		{
			calls[i] = readInt();
		}
		
		Arrays.sort(calls);
		long quality = 0;
		for(int i = 0; i < x; i++)
		{
			if(calls[n-1] == 0) break;
			quality += calls[n-1];
			calls[n-1]--;
			int j = n-1;
			while(j > 0 && calls[j] < calls[j-1])
			{
				int temp = calls[j];
				calls[j] = calls[j-1];
				calls[j-1] = temp;
				j--;
			}
		}
		
		System.out.println(quality);
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