import java.util.*;
import java.io.*;

public class Counterattack {
	
	static class Edge implements Comparable<Edge>
	{
		int v, w;
		public Edge(int v, int w) { this.v = v; this.w = w; }
		@Override
		public int compareTo(Edge e) { return w-e.w; }
	}
	
	static void shortestPath(int o, ArrayList<Edge>[] adj, int[] dis)
	{
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
		Arrays.fill(dis, Integer.MAX_VALUE); dis[o] = 0; pq.add(new Edge(o, dis[o]));
		while(!pq.isEmpty())
		{
			Edge cur = pq.remove(); if(dis[cur.v] < cur.w) continue;
			for(Edge neighbour : adj[cur.v])
			{
				if(cur.w + neighbour.w < dis[neighbour.v])
				{
					dis[neighbour.v] = cur.w + neighbour.w;
					pq.add(new Edge(neighbour.v, dis[neighbour.v]));
				}
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), m = readInt(); ArrayList<Edge>[] adj = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<Edge>();
		
		for(int i = 0; i < m; i++)
		{
			int a = readInt(), b = readInt(), w = readInt();
			adj[a].add(new Edge(b, w)); adj[b].add(new Edge(a, w));
		}
		int[] dis = new int[n+1], dis2 = new int[n+1];
		shortestPath(1, adj, dis); shortestPath(n, adj, dis2);
		
		int shortest = dis[n], ans = Integer.MAX_VALUE;
		for(int i = 1; i <= n; i++)
		{
			for(Edge e : adj[i])
			{
				if(dis[i] == Integer.MAX_VALUE || dis2[e.v] == Integer.MAX_VALUE) continue;
				int len = dis[i] + e.w + dis2[e.v];
				if(len > shortest) ans = Math.min(ans, len);
			}
		}
		System.out.println(ans);
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesread = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static String readLine() throws IOException {
		byte[] buf = new byte[64]; 
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