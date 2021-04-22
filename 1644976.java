import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Contest {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Score
	{
		int r1, r2, index;
		public Score(int r1, int r2, int index)
		{
			this.r1 = r1;
			this.r2 = r2;
			this.index = index;
		}
	}
	
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public static void main(String[] args) throws IOException
	{
		int n = readInt(), k = readInt();
		Score[] scores = new Score[n];
		for(int i = 0; i < n; i++)
		{
			scores[i] = new Score(readInt(), readInt(), i);
		}
		
		Comparator<Score> comp = new Comparator<Score>()
		{
			@Override
			public int compare(Score arg0, Score arg1) {
				// TODO Auto-generated method stub
				return arg0.r1 - arg1.r1;
			}
		};
		
		Arrays.sort(scores, comp);
		
		int max = -1;
		int maxIndex = -1;
		
		for(int i = 0; i < k; i++)
		{
			if(scores[n-1-i].r2 > max)
			{
				max = scores[n-1-i].r2;
				maxIndex = scores[n-1-i].index;
			}
		}
		
		System.out.println(maxIndex + 1);
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