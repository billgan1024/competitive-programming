import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int batchCount = Integer.parseInt(in.readLine());
		StringTokenizer st;

		int[] startCases = new int[batchCount];
		int[] endCases = new int[batchCount];
		int[] points = new int[batchCount];
		
		for(int x = 0; x < batchCount; x++)
		{
			st = new StringTokenizer(in.readLine());
			
			startCases[x] = Integer.parseInt(st.nextToken());
			
			endCases[x] = Integer.parseInt(st.nextToken());
			
			points[x] = Integer.parseInt(st.nextToken());
			
		}
		
		int failCount = Integer.parseInt(in.readLine());
		int[] fails = new int[failCount];
		
		for(int x = 0; x < failCount; x++)
		{
			fails[x] = Integer.parseInt(in.readLine());
		}
		//sort fails
		Arrays.sort(fails);
		
		int score = 0;
		//loop thru startCases
		for(int x = 0; x < startCases.length; x++)
		{
			//binary search each startcase in fails
			int index = Arrays.binarySearch(fails, startCases[x]);	
			if(index < 0) index = -(index + 1);
			if(index == fails.length)
			{
				score += points[x];
			}
			else if(fails[index] > startCases[x])
			{
				if(fails[index] > endCases[x])
				{
					score += points[x];
				}
			}
		}
		
		System.out.println(score);
	}
}