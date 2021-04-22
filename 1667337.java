import java.util.*;
import java.io.*;

public class Surfing {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		HashMap<String, ArrayList<String>> adj = new HashMap<String, ArrayList<String>>();
		
		for(int i = 0; i < n; i++)
		{
			String origin = readLine();
			ArrayList<String> links = new ArrayList<String>();
			String line = readLine();
			for(int j = 0; ; j++)
			{
				int index = 0;
				while(line.indexOf("<A HREF=", index) != -1)
				{
					index = line.indexOf("<A HREF=", index) + 9;
					String link = line.substring(index, line.indexOf("\"", index));
					System.out.println("Link from " + origin + " to " + link);
					links.add(link);
				}
				
				if(line.contains("</HTML>")) break;
				line = readLine();
			}
			adj.put(origin, links);
		}
		
		String from = "", to = "";
		for(int i = 0; ; i++)
		{
			from = readLine();
			if(from.equals("The End")) return;
			to = readLine();
			
			Queue<String> queue = new LinkedList<String>();
			HashMap<String, Boolean> vis = new HashMap<String, Boolean>();
			for(String s : adj.keySet()) vis.put(s, false);
			
			queue.add(from);
			vis.put(from, true);
			
			while(!queue.isEmpty())
			{
				String cur = queue.remove();
				if(adj.containsKey(cur))
				{
					for(String s : adj.get(cur))
					{
						if(!vis.containsKey(s) || vis.get(s)) continue;
						vis.put(s, true);
						queue.add(s);
					}
				}
			}
			if(!vis.containsKey(to) || !vis.get(to)) System.out.println("Can't surf from " + from + " to " + to + ".");
			else System.out.println("Can surf from " + from + " to " + to + ".");
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

	public static int lower_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] >= x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}

	public static int upper_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] > x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}
}