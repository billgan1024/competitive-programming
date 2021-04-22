import java.util.*;
import java.io.*;

public class ChristmasBreak {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Present
	{
		int price, ship;
		public Present(int price, int ship) {
			this.price = price; this.ship = ship;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), b = readInt();
		Present[] p = new Present[n];
		
		for(int i = 0; i < n; i++) {
			p[i] = new Present(readInt(), readInt());
		}
		
		Comparator<Present> comp = new Comparator<Present>() {
			@Override
			public int compare(Present arg0, Present arg1) {
				return (arg0.price+arg0.ship) - (arg1.price+arg1.ship);
			}
		};
		
		Arrays.sort(p, comp);
		int maxPrice = -1; boolean used = false;
		int friends = 0;
		
		for(Present cur : p) {
			maxPrice = Math.max(maxPrice, cur.price);
			if(b < cur.price + cur.ship)
			{
				if(!used) {
					b += maxPrice/2; used = true;
					if(b < cur.price + cur.ship)
					{
						break;
					}
				}
				else break;
			}
			friends++; b -= cur.price + cur.ship;
		}
		System.out.println(friends);
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