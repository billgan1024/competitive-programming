import java.io.*;
import java.util.*;

public class Main {
    @SuppressWarnings({ "rawtypes", "unchecked" })
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int n = Integer.parseInt(st.nextToken()), p = Integer.parseInt(st.nextToken());
		ArrayList[] map = new ArrayList[n]; //array of arrayLists (each arrayList has 2 elements marking the name and minutes
		for(int x = 0; x < n; x++)
		{
			map[x] = new ArrayList();
			map[x].add(in.readLine()); //adds each name to the first spot in each arrayList
			map[x].add(0); //initializes the minutes (second index) of each student to 0
		}
		
		int maxIndex = -1;
		
		for(int x = 0; x < p; x++)
		{
			st = new StringTokenizer(in.readLine());
			for(int y = 0; y < n; y++)
			{
				//add minutes to the number index of this student's arrayList
				map[y].set(1, (int) map[y].get(1) + Integer.parseInt(st.nextToken()));
				if(maxIndex < (int) map[y].get(1)) maxIndex = (int) map[y].get(1);
			}
		}
		
		String[] sorted = new String[maxIndex + 1];
		
		for(int x = 0; x < map.length; x++)
		{
			sorted[(int) map[x].get(1)] = map[x].get(0).toString();
		}
		
		int order = 3;
		for(int x = sorted.length - 1; x >= 0; x--)
		{
			if(sorted[x] != null)
			{
				System.out.println(order + ". " + sorted[x]);
				order++;
			}
		}
	}
}