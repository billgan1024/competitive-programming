import java.util.*;
import java.io.*;

public class Test {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;	
	
	public static void main(String[] args) throws IOException
	{
		double w = readDouble(), h = readDouble(), b = w/(h*h);
		if(b < 18.5) System.out.println("Underweight");
		else if(b >= 18.5 && b <= 25) System.out.println("Normal weight");
		else System.out.println("Overweight");
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

	static float readFloat() throws IOException {
		return Float.parseFloat(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}