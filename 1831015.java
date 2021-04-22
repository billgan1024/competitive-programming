import java.util.*;
import java.io.*;

public class LivestockLineup {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static HashMap<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
	static HashMap<String, Boolean> vis = new HashMap<String, Boolean>();
	
	static ArrayList<String> correctOrder = new ArrayList<String>();
	
	static void dfs(String cur)
	{
		vis.put(cur, true); correctOrder.add(cur);
		for(String s : map.get(cur))
		{
			if(vis.get(s)) continue;
			dfs(s);
		}
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {	
		int n = readInt(); 
		String[] names = { "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue" };
		
		for(String s : names) { map.put(s, new ArrayList<String>()); vis.put(s, false); }
		
		for(int i = 0; i < n; i++)
		{
			String[] s = readLine().split(" ");
			String a = s[0], b = s[5];
			
			ArrayList<String> sa = map.get(a), sb = map.get(b);
			sa.add(b); sb.add(a); map.put(a, sa); map.put(b, sb);
		}
		
		for(String s : names)
		{
			if(vis.get(s) || map.get(s).size() == 2) continue;
			dfs(s);
		}
		for(String s : correctOrder) System.out.println(s);
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