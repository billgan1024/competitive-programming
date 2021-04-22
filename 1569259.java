import java.util.*;
import java.io.*;

public class ContestOfficial4 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		long n = readLong();
		
		long result = 0;
		
		
		String s = n+"";
		
		for(int j = 0; j < s.length()-1; j++)
		{
			result += Math.pow(2, j+1);
		}
		
		//last string
		for(int i = 0; i < Math.pow(2, s.length()); i++)
		{
			String bin = Integer.toBinaryString(i);
			while(bin.length() < s.length())
			{
				bin = "0" + bin;
			}
			bin = bin.replace('0', '2');
			bin = bin.replace('1', '3');
			if(Long.parseLong(bin) <= n)
			{
				result++;
			}
		}
		
		
		System.out.println(result);

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