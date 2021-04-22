import java.io.*;
import java.util.*;

public class Main {
    public static void primeFactors(int n)
	{
		int limit = (int) Math.sqrt(n); //floored sqrt of n
		for(int x = 2; x <= limit; x++)
		{
			while(n % x == 0)
			{
				System.out.print(x + " ");
				n /= x;
			}
		}
		//only one prime factor greater than sqrt n
		if(n != 1) System.out.println(n); 
		else System.out.println();
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int count = Integer.parseInt(in.readLine());
		for(int x = 0; x < count; x++)
		{
			int n = Integer.parseInt(in.readLine());
			primeFactors(n);
		}
	}
}