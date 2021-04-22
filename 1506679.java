import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws NumberFormatException, Exception {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		String input = in.readLine();
		
		int lowerupper = 0;
		
		for(int x = 0; x < input.length(); x++)
		{
			if(Character.isUpperCase(input.charAt(x)))
			{
				lowerupper++;
			}
			else if(Character.isLowerCase(input.charAt(x)))
			{
				lowerupper--;
			}
			
		}
		
		if (lowerupper > 0)
		{
			input = input.toUpperCase();
		}
		else if(lowerupper < 0)
		{
			input = input.toLowerCase();
		}
		System.out.println(input);
	}
}