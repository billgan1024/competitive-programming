import java.util.*;
import java.io.*;

public class ExamDelay {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Point
	{
		int id, intersections; double time; //time is in hours
		//intersections tracks number of intersections that are required to go
		//to this point
		public Point(int id, double time, int intersections)
		{
			this.id = id; this.time = time; this.intersections = intersections;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		int v = readInt(), e = readInt();
		double[][] adj = new double[v][v];
		for(int i = 0; i < e; i++)
		{
			int m = readInt()-1, n = readInt()-1;
			double t = (double)readInt()/readInt();
			//each road will take the minimum time to traverse
			if(adj[m][n] == 0.0 || t < adj[m][n]) adj[m][n] = t;
			if(adj[n][m] == 0.0 || t < adj[n][m]) adj[n][m] = t;
		}
		
		Comparator<Point> comp = new Comparator<Point>()
		{
			@Override
			public int compare(Point arg0, Point arg1) {
				//if two paths to this point take the same amount of time, pick the one that goes thru less
				//intersections
				//otherwise return the path that takes the shortest amount of time 
				if(arg0.time == arg1.time) return arg0.intersections-arg1.intersections;
				else if(arg0.time < arg1.time) return -1;
				else return 1;
			}
		};
		
		PriorityQueue<Point> pq = new PriorityQueue<Point>(comp);
		//find the time needed for the shortest path between 0 and v-1 as well as the minimum # of nodes passed 
		//for this path (excluding the origin node)
		double[] time = new double[v]; int[] nodes = new int[v];
		Arrays.fill(time, Double.MAX_VALUE); Arrays.fill(nodes, Integer.MAX_VALUE);
		time[0] = 0.0; nodes[0] = 0; pq.add(new Point(0, time[0], nodes[0]));
		
		while(!pq.isEmpty())
		{
			Point p = pq.remove(), cur = new Point(p.id, time[p.id], nodes[p.id]);
			if(comp.compare(p, cur) > 0) continue; //if this current point is
			//worse than the already established point, continue
			for(int i = 0; i < v; i++)
			{
				if(adj[p.id][i] != 0)
				{
					Point orig = new Point(i, time[i], nodes[i]);
					Point alt = new Point(i, time[p.id] + adj[p.id][i], nodes[p.id] + 1);
					if(comp.compare(orig, alt) > 0)
					{
						//update node i's information
						time[i] = time[p.id] + adj[p.id][i];
						nodes[i] = nodes[p.id] + 1;
						pq.add(alt);
					}
				}
			}
		}
		
		//reducing speed by 25% means increasing time by 33% (print total time in mins/3)
		long timeReduced = Math.round((time[v-1]*60.0/3.0));
		System.out.println(nodes[v-1]);
		System.out.println(timeReduced);
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