import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("rawtypes")
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		
		for(int i = 0; i < n; i++)
		{
			String s = readLine();
			if(map.containsKey(s))
			{
				map.put(s, map.get(s)+1);
			}
			else
			{
				map.put(s, 1);
			}
		}
		
		for(int i = 0; i < n-1; i++)
		{
			String s = readLine();
			map.put(s, map.get(s)-1);
		}
		
		for (Iterator iterator = map.keySet().iterator(); iterator.hasNext();) {
			String s = (String) iterator.next();
			if(map.get(s) == 1)
			{
				System.out.println(s);
				break;
			}
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