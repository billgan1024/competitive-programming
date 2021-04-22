import java.util.*;
import java.io.*;

public class TotalDestruction {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(), q = readInt();
		if(m >= q) { System.out.println(q); return; }
		
		int[] virus = new int[q];
		
		for(int i = 0; i < q; i++) {
			virus[i] = readInt();
		}
		Arrays.sort(virus);
		
		int oops = 0;
		
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(m-1);
		for(int i = 1; i < q; i++) {
			int dis = virus[i]-virus[i-1]-1;
			if(pq.size() == m-1) {
				if(dis > pq.peek()) {
					pq.remove(); pq.add(dis);
				}
			}
			else
			{
				pq.add(dis);
			}
			oops += dis;
		}
		for(int i : pq) oops -= i;
		System.out.println(q + oops);
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