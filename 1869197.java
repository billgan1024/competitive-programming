import java.util.*;
import java.io.*;

public class NailedIt {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(); HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
		int[] lengths = new int[4001]; //lengths[i] = length of the fence with height i
		
		for(int i = 0; i < n; i++)
		{
			int l = readInt();
			freq.put(l, freq.getOrDefault(l, 0) + 1);
		}
		
		for(int i = 2; i <= 4000; i++)
		{
			int count = 0;
			if(i % 2 == 0)
			{
				for(int x = 1; x < i/2; x++)
				{
					//add up the pairs that sum to height 'i'
					count += Math.min(freq.getOrDefault(x, 0), freq.getOrDefault(i-x, 0));
				}
				//add up pairs of i/2 (i floor divided by 2)
				count += freq.getOrDefault(i/2, 0)/2;
			}
			else
			{
				for(int x = 1; x <= i/2; x++)
				{
					//add up the pairs that sum to height 'i'
					count += Math.min(freq.getOrDefault(x, 0), freq.getOrDefault(i-x, 0));
				}
			}
			lengths[i] = count;
		}
		int maxLength = 0, count = 0;
		for(int i = 2; i <= 4000; i++)
		{
			if(lengths[i] > maxLength) { maxLength = lengths[i]; count = 1; }
			else if(lengths[i] == maxLength) count++;
		}
		System.out.println(maxLength + " " + count);
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