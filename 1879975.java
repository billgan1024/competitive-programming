import java.util.*;
import java.io.*;

public class VampireTunnels {
	
	static class Edge implements Comparable<Edge>
	{
		int v, w, g;
		public Edge(int v, int w, int g) { this.v = v; this.w = w; this.g = g; }
		@Override
		public int compareTo(Edge e) { return w-e.w; }
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int s = readInt(), n = readInt(), e = readInt();
		ArrayList<Edge>[] adj = new ArrayList[n]; for(int i = 0; i < n; i++) adj[i] = new ArrayList<Edge>();
		
		for(int i = 0; i < e; i++)
		{
			int u = readInt(), v = readInt(), w = readInt(), g = readInt();
			adj[u].add(new Edge(v, w, g)); adj[v].add(new Edge(u, w, g));
		}
		
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>(); int[][] dis = new int[n][s+1];
		for(int i = 0; i < n; i++) Arrays.fill(dis[i], Integer.MAX_VALUE);
		
		//dis[i][j] = shortest distance from 0 to i while sustaining j seconds of sunlight
		//Edge(v, w, g) = able to travel to vertex v with distance w and g seconds of sunlight
		dis[0][0] = 0; pq.add(new Edge(0, dis[0][0], 0));
		while(!pq.isEmpty())
		{
			Edge cur = pq.remove(); 
			
			//check if we can break early (instantly recover the minimum distance)
			if(cur.v == n-1) { System.out.println(dis[cur.v][cur.g]); exit(); }
			if(dis[cur.v][cur.g] < cur.w) continue;
			
			for(Edge neighbour : adj[cur.v])
			{
				if(cur.g + neighbour.w * neighbour.g > s) continue;
				if(cur.w + neighbour.w < dis[neighbour.v][cur.g + neighbour.w * neighbour.g])
				{
					dis[neighbour.v][cur.g + neighbour.w * neighbour.g] = cur.w + neighbour.w;
					pq.add(new Edge(neighbour.v, dis[neighbour.v][cur.g + neighbour.w * neighbour.g], cur.g + neighbour.w * neighbour.g));
				}
			}
		}
		System.out.println(-1);
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesread = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static String readLine() throws IOException {
		byte[] buf = new byte[1024];
		int cnt = 0, c;
		while ((c = read()) != -1) {
			if (c == '\n')
				break;
			buf[cnt++] = (byte) c;
		}
		return new String(buf, 0, cnt);
	}

	public static String next() throws IOException {
		byte[] ret = new byte[1024];
		int idx = 0;
		byte c = read();
		while (c <= ' ') {
			c = read();
		}
		do {
			ret[idx++] = c;
			c = read();
		} while (c != -1 && c != ' ' && c != '\n' && c != '\r');
		return new String(ret, 0, idx);
	}

	public static int readInt() throws IOException {
		int ret = 0;
		byte c = read();
		while (c <= ' ')
			c = read();
		boolean neg = (c == '-');
		if (neg)
			c = read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = read()) >= '0' && c <= '9');

		if (neg)
			return -ret;
		return ret;
	}

	public static long readLong() throws IOException {
		long ret = 0;
		byte c = read();
		while (c <= ' ')
			c = read();
		boolean neg = (c == '-');
		if (neg)
			c = read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = read()) >= '0' && c <= '9');
		if (neg)
			return -ret;
		return ret;
	}

	public static double readDouble() throws IOException {
		double ret = 0, div = 1;
		byte c = read();
		while (c <= ' ')
			c = read();
		boolean neg = (c == '-');
		if (neg)
			c = read();

		do {
			ret = ret * 10 + c - '0';
		} while ((c = read()) >= '0' && c <= '9');

		if (c == '.') {
			while ((c = read()) >= '0' && c <= '9') {
				ret += (c - '0') / (div *= 10);
			}
		}

		if (neg)
			return -ret;
		return ret;
	}

	private static void fillBuffer() throws IOException {
		bytesread = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesread == -1)
			buffer[0] = -1;
	}

	private static byte read() throws IOException {
		if (bufferPointer == bytesread)
			fillBuffer();
		return buffer[bufferPointer++];
	}

	public void close() throws IOException {
		if (din == null)
			return;
		din.close();
	}

	static void print(Object o) {
		pr.print(o);
	}

	static void println(Object o) {
		pr.println(o);
	}

	static void flush() {
		pr.flush();
	}

	static void println() {
		pr.println();
	}

	static void exit() throws IOException {
		din.close();
		pr.close();
		System.exit(0);
	}
}