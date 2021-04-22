import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Marathon {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		int eps = readInt(), queries = readInt();
		int[] ratings = new int[eps];
		
		int sum = 0;
		for(int x = 0; x < ratings.length; x++)
		{
			ratings[x] = readInt();
			sum += ratings[x];
		}
		
		int[] belows = new int[eps];
		int[] aboves = new int[eps];
		
		int previousTotal = 0;
		for(int x = 0; x < ratings.length; x++)
		{
			belows[x] = previousTotal;
			previousTotal += ratings[x];
			aboves[x] = sum - belows[x] - ratings[x];
		}
		
		for(int x = 0; x < queries; x++)
		{
			int a = readInt(), b = readInt();
			System.out.println(belows[a-1] + aboves[b-1]);
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