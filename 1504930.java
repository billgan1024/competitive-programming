import java.io.*;
import java.util.*;

public class Main {
    public static double distance(int x, int y)
	{
		long total = (long) x*x + (long) y*y;
		return Math.sqrt(total);
	}
	
	public static void main(String[] args) throws Exception
	{
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int houseCount = Integer.parseInt(st.nextToken());
		int radiiCount = Integer.parseInt(st.nextToken());
		int[] distances = new int[houseCount];
		
		
		for(int x = 0; x < houseCount; x++)
		{
			st = new StringTokenizer(in.readLine());
			int house_x = Integer.parseInt(st.nextToken());
			int house_y = Integer.parseInt(st.nextToken());
			
			distances[x] = (int) Math.ceil(distance(house_x, house_y));
		}
		
		int maxDistance = 0;
		for(int x = 0; x < distances.length; x++)
		{
			if(maxDistance < distances[x])
			{
				maxDistance = distances[x];
			}
		}
		
		int[] distanceFreq = new int[maxDistance+1];
	
		for(int x = 0; x < distances.length; x++)
		{
			distanceFreq[distances[x]]++;
		}
		
		for(int x = 1; x < distanceFreq.length; x++)
		{
			distanceFreq[x] += distanceFreq[x-1];
		}
		
		for(int x = 0; x < radiiCount; x++)
		{
			int radius = Integer.parseInt(in.readLine());
			
			if(radius > distanceFreq.length - 1)
			{
				System.out.println(distanceFreq[distanceFreq.length - 1]);
			}
			else
			{
				System.out.println(distanceFreq[radius]);
			}
		}
		
	}
}