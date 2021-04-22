import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException
	{
		int quarters = readInt();
		
		int first = readInt(), second = readInt(), third = readInt();
		int machine = 0;
		
		while(quarters > 0)
		{
			quarters--;
			switch(machine % 3)
			{
			case 0:
				first++;
				if(first == 35)
				{
					first = 0;
					quarters += 30;
				}
				break;
				
			case 1:
				second++;
				if(second == 100)
				{
					second = 0;
					quarters += 60;
				}
				break;
				
			case 2:
				third++;
				if(third == 10)
				{
					third = 0;
					quarters += 9;
				}
				break;
				
			}
			machine++;
		}
		
		System.out.println("Martha plays " + machine + " times before going broke.");
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