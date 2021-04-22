import java.io.*;
import java.util.*;

public class Main {
    public static boolean isVowel(char c)
	{
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		while(true)
		{
			String input = in.readLine();
			if(input.equalsIgnoreCase("quit!")) break;
			
			if(input.length() > 4)
			{
				if(input.substring(input.length() - 2).equalsIgnoreCase("or") && !isVowel(input.charAt(input.length() - 3)))
				{
					StringBuilder sb = new StringBuilder(input);
					sb.insert(sb.length() - 1, 'u');
					
					System.out.println(sb);
				}
				else
				{
					System.out.println(input);
				}
			}
			else
			{
				System.out.println(input);
			}
		}
		
	}
}