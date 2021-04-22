import java.util.*;
import java.io.*;

public class Race {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		long k = readLong(), n = readLong();
		for(int i = 0; i < n; i++)
		{
			long x = readLong(), spd = (long)Math.sqrt(k+x*(x+1)/2);
			double base = (Math.sqrt(1+8*k)-1)/2;
			if(x >= Math.floor(base)) { System.out.println((long)Math.ceil(base)); continue; }
			long remainder = k-(long)Math.pow(spd, 2)+x*(x-1)/2;
			long time = 2*spd-x+(long)Math.ceil((double)remainder/(double)spd);
			System.out.println(time);
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