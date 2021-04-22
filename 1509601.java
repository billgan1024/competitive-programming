import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		long low = 1;
		long high = 2000000000;
		
		while(low <= high)
		{
			//try the guess between low and high
			int guess = (int) Math.floor((low + high) / 2);
			System.out.println(guess);
			System.out.flush();
			
			String result = in.readLine();
			if(result.equals("SINKS"))
			{
				low = guess + 1;
			}
			else if(result.equals("FLOATS"))
			{
				high = guess - 1;
			}
			else
			{
				break;
			}
		}

	}
}