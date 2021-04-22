import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class LoveGuru {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException
	{
		String a = readLine();
		String b = readLine();
		
		int lastA = 0, lastB = 0;
		
		for(int x = 0; x < a.length(); x++)
		{
			int c = (Character.getNumericValue(a.charAt(x)) - 9) % 10;//ending digit of the char-to-int letter
			//calculate the ending digit based on the exponent
			int end = 0;
			int exp = x + 1;
			switch(c)
			{
				case 1: end = 1;
				break;
				
				case 2: 
				switch(exp % 4)
				{
					case 0:
						end = 6;
					break;
					
					case 1:
						end = 2;
					break;
					
					case 2:
						end = 4;
					break;
					
					case 3:
						end = 8;
					break;
				}
				break;
				
				case 3: 
				switch(exp % 4)
				{
					case 0:
						end = 1;
					break;
					
					case 1:
						end = 3;
					break;
					
					case 2:
						end = 9;
					break;
					
					case 3:
						end = 7;
					break;
				}
				break;
				
				case 4: 
				switch(exp % 2)
				{
					case 0:
						end = 6;
					break;
					
					case 1:
						end = 4;
					break;
				}
				break;
				
				case 5: end = 5;
				break;
				
				case 6: end = 6;
				break;
				
				case 7: 
				switch(exp % 4)
				{
					case 0:
						end = 1;
					break;
					
					case 1:
						end = 7;
					break;
					
					case 2:
						end = 9;
					break;
					
					case 3:
						end = 3;
					break;
				}
				break;
				
				case 8: 
				switch(exp % 4)
				{
					case 0:
						end = 6;
					break;
					
					case 1:
						end = 8;
					break;
					
					case 2:
						end = 4;
					break;
					
					case 3:
						end = 2;
					break;
				}
				break;
				
				case 9: 
				switch(exp % 2)
				{
					case 0:
						end = 1;
					break;
					
					case 1:
						end = 9;
					break;
				}
				break;
				
			}
			lastA += end;
		}
		
		for(int x = 0; x < b.length(); x++)
		{
			int c = (Character.getNumericValue(b.charAt(x)) - 9) % 10;//ending digit of the char-to-int letter
			//calculate the ending digit based on the exponent
			int end = 0;
			int exp = x + 1;
			switch(c)
			{
				case 1: end = 1;
				break;
				
				case 2: 
				switch(exp % 4)
				{
					case 0:
						end = 6;
					break;
					
					case 1:
						end = 2;
					break;
					
					case 2:
						end = 4;
					break;
					
					case 3:
						end = 8;
					break;
				}
				break;
				
				case 3: 
				switch(exp % 4)
				{
					case 0:
						end = 1;
					break;
					
					case 1:
						end = 3;
					break;
					
					case 2:
						end = 9;
					break;
					
					case 3:
						end = 7;
					break;
				}
				break;
				
				case 4: 
				switch(exp % 2)
				{
					case 0:
						end = 6;
					break;
					
					case 1:
						end = 4;
					break;
				}
				break;
				
				case 5: end = 5;
				break;
				
				case 6: end = 6;
				break;
				
				case 7: 
				switch(exp % 4)
				{
					case 0:
						end = 1;
					break;
					
					case 1:
						end = 7;
					break;
					
					case 2:
						end = 9;
					break;
					
					case 3:
						end = 3;
					break;
				}
				break;
				
				case 8: 
				switch(exp % 4)
				{
					case 0:
						end = 6;
					break;
					
					case 1:
						end = 8;
					break;
					
					case 2:
						end = 4;
					break;
					
					case 3:
						end = 2;
					break;
				}
				break;
				
				case 9: 
				switch(exp % 2)
				{
					case 0:
						end = 1;
					break;
					
					case 1:
						end = 9;
					break;
				}
				break;
				
			}
			lastB += end;
		}
		
		lastA = lastA % 10;
		if(lastA == 0) lastA = 10;
		lastB = lastB % 10;
		if(lastB == 0) lastB = 10;

		
		System.out.println(lastA + lastB);
	}
	
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}

}