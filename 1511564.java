import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int rows = Integer.parseInt(st.nextToken());
		int columns = Integer.parseInt(st.nextToken());
		ArrayList<Integer> xLocations = new ArrayList<Integer>();
		ArrayList<Integer> yLocations = new ArrayList<Integer>();
		
		for(int y = 0; y < rows; y++)
		{
			String row = in.readLine();
			for(int x = 0; x < columns; x++)
			{
				if(row.charAt(x) == 'X')
				{
					xLocations.add(x);
					yLocations.add(y);
				}
			}
		}
		
		Collections.sort(xLocations);
		
		
		int count = Integer.parseInt(in.readLine());
		for(int i = 0; i < count; i++)
		{
			st = new StringTokenizer(in.readLine());
			int x = Integer.parseInt(st.nextToken()) - 1;
			int y = Integer.parseInt(st.nextToken()) - 1;
			
			if(Collections.binarySearch(xLocations, x) >= 0 || Collections.binarySearch(yLocations, y) >= 0)
			{
				System.out.println("Y");
			}
			else
			{
				System.out.println("N");
			}
		}
	}
}