import java.util.*;
import java.io.*;
public class Free {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		int count = readInt();
		
		for(int i = 0; i < count; i++)
		{
			int num = readInt();
			if(num == 0)
			{
				System.out.println("0000");
			}
			else
			{
				int[] sequence = null;
				while(num > 0)
				{
					//biggest power that can be subtracted from num
					int maxPower = (int) (Math.log(num) / Math.log(2));
					if(sequence == null)
					{
						sequence = new int[maxPower + 1];
					}
					
					sequence[maxPower] = 1;
					num -= Math.pow(2, maxPower);
				}
				
				//build the string
				String str = "";
				String output = "";
				for(int x = 0; x < sequence.length; x++)
				{
					str = sequence[x] + str;
					if(str.length() == 4)
					{
						output = " " + str + output;
						str = "";
					}
				}
				
				while(str.length() < 4 && str.length() > 0) str = "0" + str;
				output = str + output;
				output.trim();
				System.out.println(output);
			}
		}
		
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