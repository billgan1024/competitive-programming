import java.util.*;
import java.io.*;

public class BerryPicking {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), k = readInt(), b[] = new int[n], max = 0;
		for(int i = 0; i < n; i++)
		{
			b[i] = readInt(); max = Math.max(max, b[i]);
		}
		int ans = 0;
		for(int i = 1; i < max; i++)
		{
			//simulate using baskets containing i berries each
			int count = 0; for(int c : b) count += c/i;
			
			//cannot find more than k/2 baskets with i berries (meaning we give all of them)
			//this means that we cannot get more than k/2 baskets using more than i 
			//berries per basket so break
			if(count <= k/2) break;
			
			//if we have succeeded in getting k baskets update the max berry count
			if(count >= k) ans = Math.max(ans, i*(k/2));
			else
			{
				ArrayList<Integer> current = new ArrayList<Integer>();
				for(int j = 0; j < count; j++) current.add(i);
				int[] remainder = new int[n];
				for(int j = 0; j < n; j++)
				{
					remainder[j] = b[j] % i;
				}
				Arrays.sort(remainder);
				for(int j = n-1; j >= 0; j--)
				{
					if(current.size() == k) break;
					current.add(remainder[j]);
				} 
				while(current.size() < k) current.add(0);
				int total = 0;
				Collections.sort(current);
				for(int j = 0; j < k/2; j++) total += current.get(j);
				ans = Math.max(ans, total);
			}
		}
		System.out.println(ans);
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