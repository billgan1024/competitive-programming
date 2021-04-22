import java.util.*;
import java.io.*;

public class EdwardsChain {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(); String chain = readLine();
		TreeSet<Integer> golds = new TreeSet<Integer>(), silvers = new TreeSet<Integer>();
		
		ArrayList<Integer> silverClone = new ArrayList<Integer>(), goldClone = new ArrayList<Integer>();
		
		for(int i = 0; i < n; i++) {
			if(chain.charAt(i) == 'g') {
				golds.add(i); goldClone.add(i);
			}
			else if(chain.charAt(i) == 's') { 
				silvers.add(i); silverClone.add(i);
			}
		}
		if(golds.size() == 0 || silvers.size() == 0) {
			System.out.println(n); return;
		}
		
		int maxSum = Integer.MIN_VALUE;
		
		for(int i : silverClone) {
			boolean flag = false;
			int topDis = 0, bottomDis = 0;
			
			Integer dis = golds.higher(i);
			if(dis == null) {
				dis = golds.first();
				topDis = n-i + dis;
			}
			else
			{
				topDis = dis-i;
			}
			
			int placeholder = dis-1 < 0 ? dis-1+n : dis-1;
			if(silvers.contains(placeholder)) {
				flag = true;
			}
			else
			{
				silvers.add(placeholder);
			}
			
			Integer dis2 = silvers.lower(i);
			if(dis2 == null) {
				dis2 = silvers.last();
				bottomDis = i + n-dis2-1;
			}
			else
			{
				bottomDis = i-dis2-1;
			}
			
			maxSum = Math.max(maxSum, topDis + bottomDis);
			
			if(!flag) silvers.remove(placeholder);
		}
		
		for(int i : goldClone) {
			boolean flag = false;
			int topDis = 0, bottomDis = 0;
			
			Integer dis = silvers.higher(i);
			if(dis == null) {
				dis = silvers.first();
				topDis = n-i + dis;
			}
			else
			{
				topDis = dis-i;
			}
			
			int placeholder = dis-1 < 0 ? dis-1+n : dis-1;
			if(golds.contains(placeholder)) {
				flag = true;
			}
			else
			{
				golds.add(placeholder);
			}
			
			Integer dis2 = golds.lower(i);
			if(dis2 == null) {
				dis2 = golds.last();
				bottomDis = i + n-dis2-1;
			}
			else
			{
				bottomDis = i-dis2-1;
			}
			
			maxSum = Math.max(maxSum, topDis + bottomDis);
			
			if(!flag) golds.remove(placeholder);
		}
		
		System.out.println(maxSum);
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