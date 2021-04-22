import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int c = readInt(), r = readInt(), x = 0, y = 0;
		int px = readInt(), py = readInt();
		while(px != 0 || py != 0)
		{
			x = Math.max(Math.min(x+px, c), 0);
			y = Math.max(Math.min(y+py, r), 0);
			System.out.println(x + " " + y);
			px = readInt(); py = readInt();
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