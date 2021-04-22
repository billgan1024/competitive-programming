import java.io.*;
import java.util.*;

public class Main {
    public static String getNumberString(String number, int base) //base can be 3, 6, 9, etc.
	{
		if(Integer.parseInt(number) != 0)
		{
		String str = "";
		String baseStr = "";
		String firstStr = "";
		String secondStr = "";
		String thirdStr = "";
		
		
		switch(number.charAt(number.length() - 1))
		{
			case '1':
				thirdStr = "one";
			break;
			
			case '2':
				thirdStr = "two";
			break;
			
			case '3':
				thirdStr = "three";
			break;
			
			case '4':
				thirdStr = "four";
			break;
			
			case '5':
				thirdStr = "five";
			break;
			
			case '6':
				thirdStr = "six";
			break;
			
			case '7':
				thirdStr = "seven";
			break;
			
			case '8':
				thirdStr = "eight";
			break;
			
			case '9':
				thirdStr = "nine";
			break;
		}
		
		if(number.length() >= 2)
		{
			switch(number.charAt(number.length() - 2))
			{
				case '1':
					thirdStr = "";
					
					switch(number.charAt(number.length() - 1))
					{
						case '0':
							secondStr = "ten";
						break;
						
						case '1':
							secondStr = "eleven";
						break;
						
						case '2':
							secondStr = "twelve";
						break;
						
						case '3':
							secondStr = "thirteen";
						break;
						
						case '4':
							secondStr = "fourteen";
						break;
						
						case '5':
							secondStr = "fifteen";
						break;
						
						case '6':
							secondStr = "sixteen";
						break;
						
						case '7':
							secondStr = "seventeen";
						break;
						
						case '8':
							secondStr = "eighteen";
						break;
						
						case '9':
							secondStr = "nineteen";
						break;
					}
				break;
				
				case '2':
					secondStr = "twenty";
				break;
				
				case '3':
					secondStr = "thirty";
				break;
				
				case '4':
					secondStr = "forty";
				break;
				
				case '5':
					secondStr = "fifty";
				break;
				
				case '6':
					secondStr = "sixty";
				break;
				
				case '7':
					secondStr = "seventy";
				break;
				
				case '8':
					secondStr = "eighty";
				break;
				
				case '9':
					secondStr = "ninety";
				break;
			}
		}
		
		if(number.length() == 3)
		{
			switch(number.charAt(number.length() - 3))
			{
				case '1':
					firstStr = "onehundred";
				break;
				
				case '2':
					firstStr = "twohundred";
				break;
				
				case '3':
					firstStr = "threehundred";
				break;
				
				case '4':
					firstStr = "fourhundred";
				break;
				
				case '5':
					firstStr = "fivehundred";
				break;
				
				case '6':
					firstStr = "sixhundred";
				break;
				
				case '7':
					firstStr = "sevenhundred";
				break;
				
				case '8':
					firstStr = "eighthundred";
				break;
				
				case '9':
					firstStr = "ninehundred";
				break;
			}
		}
		
		switch(base)
		{
			case 3:
				baseStr = "thousand";
			break;
			
			case 6:
				baseStr = "million";
			break;
			
			case 9:
				baseStr = "billion";
				
		}
		
		str += firstStr;
		str += secondStr;
		str += thirdStr;
		str += baseStr;
		
		return str;
		}
		else
		{
			return "";
		}
		
	}
	
	public static String getLetterCount(String number)
	{
		String letters = "";
		String temp = "";
		int counter = 0;
		for(int i = number.length() - 1; i >= 0; i--)
		{
			if(counter == number.length() - 1)
			{
				if(counter % 3 == 0 && counter != 0)
				{
					letters = getNumberString(temp, counter - 3) + letters;
					temp = number.charAt(i) + "";
					
					letters = getNumberString(temp, counter) + letters;
				}
				else
				{
					temp = number.charAt(i) + temp;
					
					letters = getNumberString(temp, (int) Math.floor(counter/3) * 3) + letters;
				}
				
			}
			else if(counter % 3 == 0 && counter != 0)
			{
				letters = getNumberString(temp, counter - 3) + letters;
				temp = number.charAt(i) + "";
			}
			else 
			{
				temp = number.charAt(i) + temp;
			}
			
			counter++;
			
		}
		
		return letters.length() + "";
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String num = in.readLine();
		
		
		
		while(Integer.parseInt(getLetterCount(num)) != Integer.parseInt(num))
		{
			System.out.println(getLetterCount(num));
			
			num = getLetterCount(num);
		}
				
	}
}