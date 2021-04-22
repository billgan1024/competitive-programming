import java.util.*;
import java.io.*;

public class StrategicBombing {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int[][] adj = new int[26][26];
		ArrayList<Integer> edge_start = new ArrayList<Integer>();
		ArrayList<Integer> edge_end = new ArrayList<Integer>();

		String input = next().trim();
		while(!input.equals("**"))
		{
			int start = input.toLowerCase().charAt(0)-'a';
			int end = input.toLowerCase().charAt(1)-'a';
			
			edge_start.add(start);
			edge_end.add(end);
			
			adj[start][end] = 1;
			adj[end][start] = 1;
			input = next().trim();
		}
		
		int count = 0;
		
		for(int i = 0; i < edge_start.size(); i++)
		{
			Queue<Integer> queue = new LinkedList<Integer>();
			boolean[] visited = new boolean[26];
			
			adj[edge_start.get(i)][edge_end.get(i)] = 0;
			adj[edge_end.get(i)][edge_start.get(i)] = 0;
			
			queue.add(0);
			visited[0] = true;
			
			//while the queue is not empty, pop the vertex from the top
			//at the first time, the top will be the start vertex
			//store current popped vertex as a temp variable
			
			while(!queue.isEmpty())
			{
				int currentVertex = queue.remove();
				
				
				for(int j = 0; j < adj[currentVertex].length; j++)
				{
					//loop thru ALL of this vertex's neighbours 
					if(adj[currentVertex][j] == 1)
					{
						//if it is already visited, ignore
						if(visited[j]) continue;
						visited[j] = true;
						queue.add(j);
					}
				}
			}
			
			if(!visited[1])
			{
				count++;
				String s = "";
				s += (char)(edge_start.get(i) + 'a');
				s += (char)(edge_end.get(i) + 'a');
				System.out.println(s.toUpperCase());
			}
			
			adj[edge_start.get(i)][edge_end.get(i)] = 1;
			adj[edge_end.get(i)][edge_start.get(i)] = 1;
		}
		System.out.println("There are " + count + " disconnecting roads.");
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