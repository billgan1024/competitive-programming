import java.util.*;
import java.io.*;

public class ContestOfficial5 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		int n = readInt();
		
		int[] roundedNums = new int[n];
		double minNumSum = 0;
		double maxNumSum = 0;
		
		for(int i = 0; i < n; i++)
		{
			roundedNums[i] = readInt();
			if(roundedNums[i] % 2 == 0)
			{
				minNumSum += roundedNums[i] - 0.5;
				maxNumSum += roundedNums[i] + 0.5;
			}
			else
			{

				minNumSum += roundedNums[i] - 0.4999999999999;
				maxNumSum += roundedNums[i] + 0.4999999999999;
			}
		}
		
		if(minNumSum % 1 == 0.5)
		{
			if((int) minNumSum % 2 == 0) minNumSum -= 0.5;
			else minNumSum += 0.5;
		}
		else
		{
			minNumSum = Math.round(minNumSum);
		}
		
		if(maxNumSum % 1 == 0.5)
		{
			if((int) maxNumSum % 2 == 0) maxNumSum -= 0.5;
			else maxNumSum += 0.5;
		}
		else
		{
			maxNumSum = Math.round(maxNumSum);
		}
		
		String a = minNumSum + "";
		String b = maxNumSum + "";
		
		System.out.println(String.format("%.0f", minNumSum));
		System.out.println(String.format("%.0f", maxNumSum));
		
		
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