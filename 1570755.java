import java.util.*;
import java.io.*;

public class ContestOfficial5 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		
		
		for(int i = 0; i < n; i++)
		{
			String input = readLine();
			if(!input.contains("N"))
			{
				System.out.println("0 0");
			}
			else if(input.contains("NN"))
			{
				System.out.println("0 0");
			}
			else if(input.charAt(0) == 'N')
			{
				System.out.println("1 1");
			}
			else if(input.charAt(0) == 'A')
			{
				System.out.println("0 1");
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