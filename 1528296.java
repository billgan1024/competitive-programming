import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ExactlyElectrical {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws Exception
	{
		
		int x1 = readInt(), y1 = readInt(), x2 = readInt(), y2 = readInt();
		int e = readInt();
		
		//min distance
		int xd = Math.abs(x2 - x1);
		int yd = Math.abs(y2 - y1);
		int d = xd + yd;
		if(e >= d && (e-d) % 2 == 0)
		{
			System.out.println("Y");
		}
		else
		{
			System.out.println("N");
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