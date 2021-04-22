import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int[] locations = new int[Integer.parseInt(in.readLine())];
		
		for(int x = 0; x < locations.length; x++)
		{
			locations[x] = Integer.parseInt(in.readLine());
		}
		
		Arrays.sort(locations);
		
		double minDistance = -1;
		
		for(int x = 1; x < locations.length - 1; x++)
		{
			double d = (locations[x] - locations[x-1])/2.0 + (locations[x+1] - locations[x])/2.0;
			if(d < minDistance || minDistance == -1)
			{
				minDistance = d;
			}
		}
		
		System.out.printf("%.1f", minDistance);
		
	}
}