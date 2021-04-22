import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Vauvau {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException
	{
		int a = readInt(), b = readInt(), c = readInt(), d = readInt();
		for(int i = 0; i < 3; i++)
		{
			int person = readInt();
			int dog1 = 0, dog2 = 0;
			
			boolean mad1 = true;
			boolean mad2 = true;
			
			boolean attacked1 = false, attacked2 = false;
			
			while(dog1 < person)
			{
				if(mad1) dog1 += a;
				else dog1 += b;
				mad1 = !mad1;
			}
			if(mad1) attacked1 = true;
			
			while(dog2 < person)
			{
				if(mad2) dog2 += c;
				else dog2 += d;
				mad2 = !mad2;
			}
			
			if(mad2) attacked2 = true;
			
			if(attacked1 && attacked2)
			{
				System.out.println("none");
			}
			else if(attacked1 || attacked2)
			{
				System.out.println("one");
			}
			else
			{
				System.out.println("both");
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