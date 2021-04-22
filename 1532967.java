import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Perket {
	
	@SuppressWarnings("unchecked")
	public static ArrayList<Integer>[] subsets(int[] set)
	{
		ArrayList<Integer>[] subset = new ArrayList[(int) Math.pow(2, set.length) - 1];
		for(int x = 0; x < subset.length; x++)
		{
			subset[x] = new ArrayList<Integer>();
			String binary = Integer.toBinaryString(x + 1);
			while(binary.length() < set.length)
			{
				binary = "0" + binary;
			}
			for(int c = 0; c < binary.length(); c++)
			{
				if(binary.charAt(c) == '1')
				{
					subset[x].add(set[c]);
				}
			}
		}
		return subset;
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		int[] sours = new int[n];
		int[] bitters = new int[n];
		//array for getting all combinations
		int[] test = new int[n];
		
		for(int x = 0; x < test.length; x++)
		{
			test[x] = x;
		}
		
		for(int i = 0; i < n; i++)
		{
			sours[i] = readInt();
			bitters[i] = readInt();
		}
		
		//Arrays.sort(sours);
		//Arrays.sort(bitters);
		ArrayList<Integer>[] testCombos = subsets(test);
		//loop through all combinations of test
		
		int minDifference = Integer.MAX_VALUE;
		for(int x = 0; x < testCombos.length; x++)
		{
			//loop thru this combination
			int sourProduct = 1;
			int bitterSum = 0;
			for(int y = 0; y < testCombos[x].size(); y++)
			{
				sourProduct *= sours[testCombos[x].get(y)];
				bitterSum += bitters[testCombos[x].get(y)];
			}
			minDifference = Math.min(minDifference, Math.abs(sourProduct - bitterSum));
		}
			
			
		System.out.println(minDifference);
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