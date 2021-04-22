import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException
	{
		String firstNum = readLine();
		char operation = readLine().charAt(0);
		String secondNum = readLine();
		
		if(firstNum.length() < secondNum.length())
		{
			String temp = firstNum;
			firstNum = secondNum;
			secondNum = temp;
		}
		
		if(operation == '*')
		{
			int numZeros = firstNum.length()-1;
			int numZeros2 = secondNum.length()-1;
			
			System.out.print(1);
			for(int i = 0; i < numZeros+numZeros2; i++)
			{
				System.out.print(0);
			}
		}
		else
		{
			while(secondNum.length() < firstNum.length())
			{
				secondNum = "0" + secondNum;
			}
			for(int i = 0; i < firstNum.length(); i++)
			{
				if(firstNum.charAt(i) == '1' && secondNum.charAt(i) == '1')
				{
					System.out.print(2);
				}
				else if(firstNum.charAt(i) == '1' || secondNum.charAt(i) == '1')
				{
					System.out.print(1);
				}
				else
				{
					System.out.print(0);
				}
			}
		}
	}

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}