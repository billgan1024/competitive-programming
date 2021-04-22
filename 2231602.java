import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException {
		int n = readInt(); ArrayList<String> s = new ArrayList<String>();
		for(int i = 0; i < n; i++) s.add(readLine());
		Comparator<String> cmp = new Comparator<String>()
		{
			@Override
			public int compare(String a, String b) {
				long c = Long.parseLong(a+b), d = Long.parseLong(b+a);
			    return Long.compare(d, c);
			}
		};
		Collections.sort(s, cmp);
		for(String st : s) System.out.print(st);
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}