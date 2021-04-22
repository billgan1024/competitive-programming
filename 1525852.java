import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Granica {

	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st;
		int[] numbers = new int[Integer.parseInt(br.readLine())];
		for(int x = 0; x < numbers.length; x++)
		{
			numbers[x] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(numbers);
		
		int minDifference = Integer.MAX_VALUE;
		int[] difference = new int[numbers.length - 1];
		for(int x = 0; x < numbers.length; x++)
		{
			if(x != 0)
			{
				difference[x-1] = numbers[x] - numbers[x-1];
				minDifference = Math.min(minDifference, difference[x-1]);
			}
		}
		
		String result = "";
		
		//find all factors of minDifference
		for(int x = 1; x <= Math.sqrt(minDifference); x++)
		{
			if(minDifference % x == 0)
			{
				if(x != 1)
				{
					boolean goesIn = true;
					for(int y = 0; y < difference.length; y++)
					{
						if(difference[y] % x != 0)
						{
							goesIn = false;
							break;
						}
					}
					if(goesIn) result += x + " ";
				}
				if((double) x != Math.sqrt(minDifference))
				{
					boolean goesIn = true;
					for(int y = 0; y < difference.length; y++)
					{
						if(difference[y] % (minDifference/x) != 0)
						{
							goesIn = false;
							break;
						}
					}
					if(goesIn) result += (minDifference/x) + " ";
				}
			}
		}
		
		result = result.trim();
		System.out.println(result);
	}
}