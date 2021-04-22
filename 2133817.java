import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		
		for(int i = 0; i < n; i++)
		{
			int problem = readInt(), correct = readInt(), loss = readInt(), target = readInt();
			
			long currentScore = (long) problem * (long) correct;
			int minCorrect = problem;
			//check if there is no way to reach target score
			if(currentScore < target) 
			{
				System.out.println(-1); continue;
			}
			
			long difference = currentScore - target;
			//calculate how many problems could be turned wrong and still have the currentScore above the target
			long overSteps = Math.floorDiv(difference, correct+loss);
			
			System.out.println(minCorrect-overSteps);
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