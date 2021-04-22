import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		while(true)
		{
			int c = Integer.parseInt(in.readLine());
			if(c == 0) break;
			
			int limit = (int) Math.sqrt(c); //limit is floor of sqrt(c)
			int cf1  = 0;
			int cf2 = 0;
			int perimeter = 0;
			
			for(int x = limit; x >= 1; x--) //loop from 2 
			{
				if(c % x == 0)
				{
					cf1 = x;
					cf2 = c / x;
					perimeter = 2*cf1 + 2*cf2;
					break;
				}
			}
			
			System.out.println("Minimum perimeter is " + perimeter + " with dimensions " + cf1 + " x " + cf2);
		}
		
	}
}