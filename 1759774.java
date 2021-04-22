import java.util.*;
import java.io.*;

public class DijkstraPriorityQueue {
	
	static class House
	{
		int id, dis;
		public House(int id, int dis) {
			this.id = id; this.dis = dis;
		}
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	//Dijkstra optimization (ElogV)
	//use a dis array and a priority queue
	//start off with origin dis 0, everything else dis infinity
	//find ordered pair with min dis and push into the queue
	//If this ordered pair has a distance greater than the dis array, skip
	//remove it, get the dis and current vertex, and update distances
	//when u update a distance, always push that update into the pq
	
	//stop when pq is empty
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt(), b = readInt()-1, q = readInt();
		int[][] adj = new int[n][n];
		for(int i = 0; i < m; i++)
		{
			int u = readInt()-1, v = readInt()-1, w = readInt();
			adj[u][v] = w; adj[v][u] = w;
		}
		
		Comparator<House> comp = new Comparator<House>() {
			@Override
			public int compare(House arg0, House arg1) {
				// TODO Auto-generated method stub
				return arg0.dis-arg1.dis;
			}
		};
		
		PriorityQueue<House> pq = new PriorityQueue<House>(comp);
		int[] dis = new int[n]; Arrays.fill(dis, Integer.MAX_VALUE);
		dis[b] = 0; pq.add(new House(b, dis[b]));
		
		while(!pq.isEmpty())
		{
			House h = pq.remove(), cur = new House(h.id, dis[h.id]);
			if(comp.compare(h, cur) > 0) continue;
			
			for(int i = 0; i < n; i++)
			{
				if(adj[h.id][i] != 0 && dis[i] > dis[h.id] + adj[h.id][i]) {
					dis[i] = dis[h.id] + adj[h.id][i];
					pq.add(new House(i, dis[i]));
				}
			}
		}
		for(int i = 0; i < q; i++)
		{
			int k = readInt()-1;
			System.out.println(dis[k] == Integer.MAX_VALUE ? -1 : dis[k]);
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