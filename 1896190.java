import java.util.*;
import java.io.*;

public class RoyalGuard {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		//use the long's range to separate x and y values while still keeping them sortable
		//and efficient (unlike a HashMap with Integer to ArrayList<Integer>)
		//thus you can hash rows/columns using just the integer
		//and you can search any row and column faster
		
		//thus each entry will be in the range [1*1, 10^9*10^9] where 10^9*x+y represents
		//a particular building stored on a vertical (x=k) line and x+10^9*y represents a
		//building stored on a horizontal (y=k) line
		long sep = (long) 1e9;
		int n = readInt(); long[] x = new long[n], y = new long[n];
		for(int i = 0; i < n; i++)
		{
			int x0 = readInt(), y0 = readInt(); x[i] = sep*x0 + y0; y[i] = x0 + sep*y0;
		}
		
		Arrays.sort(x); Arrays.sort(y);
		
		int m = readInt(), px = readInt(), py = readInt(); long c = 0;
		for(int i = 1; i < m; i++)
		{
			int cx = readInt(), cy = readInt();
			if(cx == px)
			{
				//vertical movement
				long bot = sep*cx + Math.min(cy, py), top = sep*cx + Math.max(cy, py);
				int l = Arrays.binarySearch(x, bot), r = Arrays.binarySearch(x, top);
				if(l < 0) l = -(l+1); if(r < 0) r = -(r+1)-1;
				c += r-l+1;
			}
			else if(cy == py)
			{
				long bot = sep*cy + Math.min(cx, px), top = sep*cy + Math.max(cx, px);
				int l = Arrays.binarySearch(y, bot), r = Arrays.binarySearch(y, top);
				if(l < 0) l = -(l+1); if(r < 0) r = -(r+1)-1;
				c += r-l+1;
			}
			px = cx; py = cy;
		}
		System.out.println(c);
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