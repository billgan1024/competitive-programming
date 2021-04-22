import java.util.*;
import java.io.*;

public class LookingGlass {
	
	static class Point
	{
		int x, y;
		public Point(int x, int y) { this.x = x; this.y = y; }
		@Override
		public boolean equals(Object o)
		{
			Point p = (Point) o; return x == p.x && y == p.y;
		}
	}
	
	static ArrayList<Point> crystals = new ArrayList<Point>();
	static ArrayList<Point> empty = new ArrayList<Point>();

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		crystals.add(new Point(1, 0)); crystals.add(new Point(2, 0));
		crystals.add(new Point(3, 0)); crystals.add(new Point(2, 1));
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5; j++) empty.add(new Point(i, j));
		}
		empty.remove(new Point(1, 0)); empty.remove(new Point(2, 0));
		empty.remove(new Point(3, 0)); empty.remove(new Point(2, 1));
		empty.remove(new Point(1, 1)); empty.remove(new Point(2, 2)); 
		empty.remove(new Point(3, 1));
		int t = readInt();
		for(int i = 0; i < t; i++)
		{
			int m = readInt(), x = readInt(), y = readInt();
			find(m, x, y);
		}
	}
	static boolean eval(int x, int y)
	{
		//checks if this coordinate is definitely a crystal
		return crystals.contains(new Point(x, y));
	}
	static boolean empty(int x, int y)
	{
		//checks if this coordinate is definitely empty
		return empty.contains(new Point(x, y));
	}
	
	static void find(int level, int x, int y)
	{
		int scaled_x = x / (int)Math.pow(5, level-1);
		int scaled_y = y / (int)Math.pow(5, level-1);
		if(eval(scaled_x, scaled_y)) System.out.println("crystal");
		else if(level == 1 || empty(scaled_x, scaled_y)) System.out.println("empty");
		else 
		{
			find(level-1, x-(int)Math.pow(5, level-1)*scaled_x, y-(int)Math.pow(5, level-1)*scaled_y);
		}
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