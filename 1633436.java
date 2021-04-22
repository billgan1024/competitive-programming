import java.util.*;
import java.io.*;

public class Dodgeball {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		HashMap<String, ArrayList<String>> adj = new HashMap<String, ArrayList<String>>();
		
		int n = readInt(), m = readInt();
		
		Queue<String> queue = new LinkedList<String>();
		HashMap<String, Boolean> vis = new HashMap<String, Boolean>();
		HashMap<String, Integer> dis = new HashMap<String, Integer>();
		
		adj.put("home", new ArrayList<String>());
		adj.put("Waterloo GO", new ArrayList<String>());
		
		vis.put("Waterloo GO", false);
		dis.put("Waterloo GO", 0);
		
		for(int i = 0; i < n; i++)
		{
			String s = readLine();
			adj.put(s, new ArrayList<String>());
			vis.put(s, false);
			dis.put(s, 0);
		}
		
		for(int i = 0; i < m; i++)
		{
			String[] s = readLine().split("-");
			ArrayList<String> temp = adj.get(s[0]);
			temp.add(s[1]);
			adj.put(s[0], temp);
			temp = adj.get(s[1]);
			temp.add(s[0]);
			adj.put(s[1], temp);
		}
		
		queue.add("home");
		vis.put("home", true);
		dis.put("home", 0);
		
		while(!queue.isEmpty())
		{
			String cur = queue.remove();
			for(String s : adj.get(cur))
			{
				if(vis.get(s)) continue;
				vis.put(s, true);
				dis.put(s, dis.get(cur) + 1);
				queue.add(s);
			}
		}
		
		if(vis.get("Waterloo GO")) System.out.println(dis.get("Waterloo GO"));
		else
		{
			System.out.println("RIP ACE");
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