import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int low = 1;
		int high = 2000000000;
		
		while(low <= high)
		{
			//try the guess between low and high
			int guess = low + (high - low) / 2;
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