import java.util.*;
import java.io.*;

public class QuantumOperations {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		int r = readInt(), c = readInt();
		long ans[][] = new long[r][c];
		
		for(int i = 0; i < r; i++) 
		{
			for(int j = 0; j < c; j++) ans[i][j] = readLong();
		}
		for(int t = 1; t < n; t++)
		{
			int r0 = readInt(), c0 = readInt();
			long[][] temp = new long[r0][c0], original = ans.clone();
			for(int i = 0; i < r0; i++)
			{
				for(int j = 0; j < c0; j++) temp[i][j] = readLong();
			}
			ans = new long[r*r0][c*c0];
			//merge temp with original
			for(int i = 0; i < r*r0; i += r0)
			{
				for(int j = 0; j < c*c0; j += c0)
				{
					for(int k = 0; k < r0; k++)
					{
						for(int l = 0; l < c0; l++)
						{
							ans[k+i][l+j] = temp[k][l]*original[i/r0][j/c0];
						}
					}
				}
			}
			r *= r0; c *= c0;
		}
		long max = Long.MIN_VALUE, min = Long.MAX_VALUE;
		long[] rsum = new long[r], csum = new long[c];
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				long element = ans[i][j];
				max = Math.max(max, element); min = Math.min(min, element);
				rsum[i] += element; csum[j] += element;
			}
		}
		long maxr = Long.MIN_VALUE, minr = Long.MAX_VALUE;
		long maxc = Long.MIN_VALUE, minc = Long.MAX_VALUE;
		for(long i : rsum) { maxr = Math.max(maxr, i); minr = Math.min(minr, i); }
		for(long i : csum) { maxc = Math.max(maxc, i); minc = Math.min(minc, i); }
		
		System.out.printf("%d\n%d\n%d\n%d\n%d\n%d\n", max, min, maxr, minr, maxc, minc);
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