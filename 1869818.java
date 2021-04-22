import java.util.*;
import java.io.*;

public class BeautifulTrees {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(); ArrayList<Integer>[] adj = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<Integer>();
		boolean[] invalid = new boolean[n+1]; ArrayList<Integer> endpoints = new ArrayList<Integer>();
		
		for(int i = 1; i <= n; i++)
		{
			long y = readLong(), s = (long) Math.sqrt((double)y);
			if(s*(s+1) != y) invalid[i] = true;
		}
		
		for(int i = 0; i < n-1; i++)
		{
			int a = readInt(), b = readInt(); adj[a].add(b); adj[b].add(a);
		}
		
		boolean[] vis = new boolean[n+1]; Queue<Integer> q = new LinkedList<Integer>(); int[] dis = new int[n+1];
		
		for(int i = 1; i <= n; i++)
		{
			if(vis[i] || invalid[i]) continue;
			int end = i; vis[i] = true; q.add(i);
			while(!q.isEmpty())
			{
				int cur = q.remove();
				for(int neighbour : adj[cur])
				{
					if(vis[neighbour] || invalid[neighbour]) continue;
					vis[neighbour] = true; dis[neighbour] = dis[cur] + 1; end = neighbour;
					q.add(neighbour);
				}
			}
			endpoints.add(end);
		}
		int ans = -1; vis = new boolean[n+1];
		for(int i : endpoints)
		{
			int max = 0; vis[i] = true; dis[i] = 0; q.add(i);
			while(!q.isEmpty())
			{
				int cur = q.remove();
				for(int neighbour : adj[cur])
				{
					if(vis[neighbour] || invalid[neighbour]) continue;
					vis[neighbour] = true; dis[neighbour] = dis[cur] + 1; max = dis[neighbour];
					q.add(neighbour);
				}
			}
			ans = Math.max(ans, max);
		}
		System.out.println(ans+1);
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