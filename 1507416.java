import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int count = Integer.parseInt(st.nextToken());
		int dest = Math.abs(Integer.parseInt(st.nextToken()));
		
		int[] intervals = new int[count];
		
		st = new StringTokenizer(in.readLine());
		
		for(int x = 0; x < count; x++)
		{
			intervals[x] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(intervals); 
		
		boolean found = false;
		
		for(int x = intervals.length - 1; x >= 0; x--)
		{
			if(dest % intervals[x] == 0)
			{
				System.out.println((int) dest / intervals[x]);
				found = true;
				break;
			}
		}
		
		if(!found)
		{
			System.out.println("This is not the best time for a trip.");
		}
		
	}
}