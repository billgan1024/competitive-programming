import java.io.*;
import java.util.*;
public class RectangleCounting {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt();
		long ans = 0;
		event e[] = new event[2*n];
		for(int i=0;i<2*n;i+=2) {
			int a = readInt(), b = readInt(), c = readInt(), d = readInt();
			e[i] = new event(a, b, d, i, 1);
			e[i+1] = new event(c, b, d, i, 2);
		}
		Arrays.sort(e);
		int top[] = new int[1000001], bot[] = new int[1000001];
		for(event i : e) {
			if(i.type == 1) {
				update(top, i.hi, 1);
				update(bot, i.lo, 1);
			}
			else {
				ans += query(bot, i.hi-1) - query(top, i.lo) - 1;
				update(top, i.hi, -1);
				update(bot, i.lo, -1);
			}
		}
		System.out.println(ans);
	}
	static void update(int bit[], int i, int val) {
		while(i < bit.length) {
			bit[i] += val;
			i += i & - i;
		}
	}
	static int query(int bit[], int x) {
		int sum = 0;
		while(x > 0) {
			sum += bit[x];
			x -= x & -x;
		}
		return sum;
	}
	static class event implements Comparable<event>{
		int x, lo, hi, idx, type;
		public event(int x0, int l, int h, int i, int t) {
			x = x0;
			lo = l;
			hi = h;
			idx = i;
			type = t;
		}
		@Override
		public int compareTo(event o) {
			if(x != o.x) return Integer.compare(x, o.x);
			return Integer.compare(o.type, type);
		}
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) 
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
}