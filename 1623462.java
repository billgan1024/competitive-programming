import java.util.*;
import java.io.*;

public class PyramidScheme {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("rawtypes")
	public static void main(String[] args) throws IOException {
		
		int l = readInt();
		for(int u = 0; u < l; u++)
		{
			int n = readInt();
			int time = n * 10;
			
			HashMap<String, ArrayList<String>> adjList = new HashMap<String, ArrayList<String>>();
			
			String prev = readLine();
			String original = prev;
			String end = "";
			
			for(int i = 1; i < n; i++)
			{
				String s = readLine();
				//connect prev to s
				ArrayList<String> temp = new ArrayList<String>();
				
				if(adjList.containsKey(prev)) temp = adjList.get(prev);
				else adjList.put(prev, temp);
				
				//add this recipient to prev's neighbour nodes
				temp.add(s);
				
				adjList.put(prev, temp);
				
				prev = s;
				if(i == n-1) end = s;
			}
			
			//connect the end to the first recipient
			
			ArrayList<String> temp = new ArrayList<String>();
			
			if(adjList.containsKey(end)) temp = adjList.get(end);
			else adjList.put(end, temp);
			
			//add this recipient to prev's neighbour nodes
			temp.add(original);
			
			adjList.put(end, temp);
			
			//start bfs on the first node
			Queue<String> queue = new LinkedList<String>();
			HashMap<String, Boolean> vis = new HashMap<String, Boolean>();
			HashMap<String, Integer> dis = new HashMap<String, Integer>();
			//fill visited with the nodes obtained in the adjList
			for (Iterator it = adjList.keySet().iterator(); it.hasNext();) {
				String s = (String) it.next();
				vis.put(s, false);
				dis.put(s, 0);
			}
			
			queue.add(end);
			vis.put(end, true);
			dis.put(end, 0);
			
			int maxDistance = Integer.MIN_VALUE;
			//then bfs from start node and find max distance
			//print maxdistance * 2 * 10s
			while(!queue.isEmpty())
			{
				String cur = queue.remove();
				
				for(String s : adjList.get(cur))
				{
					if(vis.get(s)) continue;
					vis.put(s, true);
					dis.put(s, dis.get(cur) + 1);
					queue.add(s);
					maxDistance = Math.max(maxDistance, dis.get(s));
				}
			}
			
			int savedTime = maxDistance * 20;
			System.out.println(time - savedTime);
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