import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		int h = readInt(), w = readInt();
		String s = "";
		for(int i = 0; i < w+2; i++) s += "#";
		System.out.println(s);
		
		for(int i = 0; i < h; i++)
		{
			String t = readLine();
			t = "#" + t;
			t += "#";
			System.out.println(t);
		}
		
		System.out.println(s);
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
	static String readLine () throws IOException {
		return br.readLine().trim();
	}


}