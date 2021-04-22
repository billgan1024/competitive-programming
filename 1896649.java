import java.util.*;
import java.io.*;

public class Geometry {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int maxl = 0, index = 0, s[][] = new int[3][2];
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 2; j++) 
			{ 
				s[i][j] = readInt(); 
				if(maxl < s[i][j]) { maxl = s[i][j]; index = i; }
			}
		}
		int curw = Math.min(s[index][0], s[index][1]);
		
		int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
		for(int i = 0; i < 3; i++)
		{
			if(i == index) continue;
			if(a0 == 0 && a1 == 0) { a0 = s[i][0]; a1 = s[i][1]; }
			else { b0 = s[i][0]; b1 = s[i][1]; }
		}
		if((a0 == maxl-curw || a1 == maxl-curw) && (b0 == maxl-curw || b1 == maxl-curw))
		{
			int d = a0 == maxl-curw ? a1 : a0, e = b0 == maxl-curw ? b1 : b0;
			if(d+e == maxl) System.out.println("YES");
			else System.out.println("NO");
		}
		else
		{
			System.out.println("NO");
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