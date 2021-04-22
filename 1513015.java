import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int count = Integer.parseInt(st.nextToken());
		int limit = Integer.parseInt(st.nextToken());
		int[] numbers = new int[count];
		long sum = 0;
		
		st = new StringTokenizer(in.readLine());
		
		for(int x = 0; x < count; x++)
		{
			numbers[x] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(numbers);
		
		for(int x = 0; x < numbers.length; x++)
		{
			if(limit - numbers[x] >= numbers[x])
			{
				int index = Arrays.binarySearch(numbers, limit - numbers[x]);
				if(index < 0)
				{
					index = -(index + 1) - 1;
				}
				
				sum += index - x;
				
				for(int y = index + 1; y < numbers.length; y++)
				{
					if(numbers[x] + numbers[y] <= limit)
					{
						sum++;
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
		
		System.out.println(sum);
	}
}