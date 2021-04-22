import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Factory
	{
		int price, amnt;
		public Factory(int price, int amnt) {
			this.price = price; this.amnt = amnt;
		}
	}
	
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt();
		Factory[] factories = new Factory[n];
		for(int i = 0; i < n; i++) factories[i] = new Factory(readInt(), readInt());
		
		Comparator<Factory> comp = new Comparator<Factory>() {

			@Override
			public int compare(Factory arg0, Factory arg1) {
				return arg0.price-arg1.price;
			}
		};
		Arrays.sort(factories, comp);
		
		long totalspent = 0;
		int obtained = 0;
		for(Factory f : factories)
		{
			if(obtained + f.amnt < m)
			{
				totalspent += f.price*f.amnt; obtained += f.amnt;
			}
			else
			{
				totalspent += f.price*(m-obtained);
				obtained += m-obtained;
				break;
			}
		}
		System.out.println(totalspent);
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