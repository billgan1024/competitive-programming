import java.io.*;
import java.util.*;

public class Main {
    @SuppressWarnings({ "rawtypes", "unchecked" })
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int len = Integer.parseInt(in.readLine());
		int[] numbers = new int[len];
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		ArrayList[] ones = new ArrayList[10];
		
		//initialize the primitive list of dynamic ArrayLists
		for(int x = 0; x < ones.length; x++)
		{
			ones[x] = new ArrayList();
		}
		
		for(int x = 0; x < numbers.length; x++)
		{
			numbers[x] = Integer.parseInt(st.nextToken());
			
			int lastDigit = numbers[x] % 10;
			ones[lastDigit].add(numbers[x]);
		}
		
		for(int x = 0; x < ones.length; x++)
		{
			Collections.sort(ones[x], Collections.reverseOrder()); // sorts each ArrayList in the list "ones"
		}

		//prints all of the elements (numbers) in ones (loops thru all the ArrayLists, loops thru all the numbers in each ArrayList)
		for(int x = 0; x < ones.length; x++)
		{
			for(int y = 0; y < ones[x].size(); y++)
			{
				System.out.print(ones[x].get(y) + " ");
			}
		}
		
	}
}