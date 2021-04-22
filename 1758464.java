import java.util.*;
import java.io.*;

public class InClass {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		String[] a = new String[5], b = new String[5];
		
		String k = readLine(), m = readLine();
		for(int i = 0; i < 5; i++)
		{
			a[i] = k.substring(2*i, 2*i+2);
			b[i] = m.substring(2*i, 2*i+2);
		}
		int x = readInt();
		for(int e = 0; e < x; e++) {
			String s = readLine();
			boolean possible = true;
			for(int i = 0; i < 5; i++) {
				boolean lower = false, upper = false;
				char allele = s.charAt(i);
				
				char a0 = a[i].charAt(0), a1 = a[i].charAt(1);
				char b0 = b[i].charAt(0), b1 = b[i].charAt(1);
				if(up(a0) || up(a1) || up(b0) || up(b1)) upper = true;
				if((lo(a0) || lo(a1)) && (lo(b0) || lo(b1))) lower = true;
				
				if(up(allele) && !upper) {
					System.out.println("Not their baby!"); possible = false; break;
				}
				if(lo(allele) && !lower)
				{
					System.out.println("Not their baby!"); possible = false; break;
				}
			}
			if(possible) System.out.println("Possible baby.");
		}
	}
	
	static boolean up(char c) {
		return Character.isUpperCase(c);
	}
	static boolean lo(char c) {
		return Character.isLowerCase(c);
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

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}