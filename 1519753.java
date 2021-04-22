import java.io.*;
import java.util.*;

public class Main {
    public static boolean isPrime(int n)
	{
		if(n == 2 || n == 5) return true;
		int last = n % 10;
		if(last == 2 || last == 5 || last == 0 || n == 1) return false;
		int limit = (int) Math.sqrt(n); //limit is floor of sqrt(n)
		
		for(int x = 2; x <= limit; x++) //loop from 2 
		{
			if(n % x == 0)
			{
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		while(!isPrime(n))
		{
			n++;
		}
		System.out.println(n);
	}
}