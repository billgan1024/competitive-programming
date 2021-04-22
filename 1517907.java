import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int a = Integer.parseInt(in.readLine());
		int b = Integer.parseInt(in.readLine());
		
		int result = 0;
		
		for(int y = a; y <= b; y++)
		{
			int factors = 0;
			for(int z = 1; z <= (int) Math.sqrt(y); z++)
			{
				if(y % z == 0)
				{
					if(z == Math.sqrt(y))
					{
						factors++;
					}
					else 
					{
						factors += 2;
					}
				}
			}
				
			if(factors == 4)
			{
				result++;
			}
		}
		
		System.out.println("The number of RSA numbers between " + a + " and " + b + " is " + result);
	}
}