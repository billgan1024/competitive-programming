import java.util.*;
import java.io.*;

public class NailedIt {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		int[] lengthFreq = new int[2001];
		
		//take frequency of lengths
		for(int i = 0; i < n; i++)
		{
			lengthFreq[readInt()]++;
		}
		//this array stores the # of DISTINCT (no duplicate boards used)
		//combinations of 2 pieces that 
		//combine to make a certain height
		//(combinations of 2, so max board is 4000)
		int[] boardHeightFreq = new int[4001];
		
		for(int i = 2; i <= 4000; i++)
		{
			//x loops until closest value strictly under i
			for(int x = 1; x * 2 < i; x++)
			{
				int y = i-x; //x is lower, y is higher (count distinct pieces of wood)
				//restrict bound to only 1 to 2000
				if(x <= 2000 && y <= 2000)
				{
					boardHeightFreq[i] += Math.min(lengthFreq[x], lengthFreq[y]);
				}
			}
			//consider even case for every even number
			//when (x and y can be the same)
			if(i % 2 == 0) boardHeightFreq[i] += lengthFreq[i/2]/2;
		}
		
		//get max length of the board (max # of combinations
		//that combine to make a certain height)
		int answer = 0, count = 0;
		for(int i = 1; i <= 4000; i++)
		{
			if(boardHeightFreq[i] > answer)
			{
				answer = boardHeightFreq[i];
				count = 1;
			}
			else if(boardHeightFreq[i] == answer) count++;
		}
		System.out.println(answer + " " + count);
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