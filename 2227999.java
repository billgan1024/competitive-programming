import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		int[] factors = new int[100001];
		
		ArrayList<Integer>[] numFactors = new ArrayList[factors.length];
		//initialize empty arraylists
		for(int i = 1; i < numFactors.length; i++)
		{
			numFactors[i] = new ArrayList<Integer>();
		}
		//sieve method for determining the number of factors 1-100000 has
		for(int i = 1; i < factors.length; i++)
		{
			for(int j = i; j < factors.length; j += i)
			{
				factors[j]++; //add 1 to all multiples of this number
			}
			numFactors[factors[i]].add(i); //on this number, add it to the arraylist corresponding to how many factors it has
		}
		
		int count = Integer.parseInt(in.readLine());
		
		for(int x = 0; x < count; x++)
		{
			st = new StringTokenizer(in.readLine());
			
			int k = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			//binary search numFactors (the list of numbers with k factors
			int lowerIndex = Collections.binarySearch(numFactors[k], a);
			int higherIndex = Collections.binarySearch(numFactors[k], b);
			
			if(lowerIndex < 0) lowerIndex = -(lowerIndex + 1);
			if(higherIndex < 0) higherIndex = -(higherIndex + 1) - 1;
			
			System.out.println(higherIndex - lowerIndex + 1);
		}
	}
}