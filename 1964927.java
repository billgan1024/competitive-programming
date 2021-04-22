import java.util.*;
import java.io.*;

public class CharlieConquest {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Action
	{
		char c; int d;
		public Action(char c, int d) { this.c = c; this.d = d; }
	}

	public static void main(String[] args) throws IOException {
		
		int n = readInt(), h = readInt(); Action[] player = new Action[n], bot = new Action[n];
		for(int i = 0; i < n; i++)
		{
			char c = next().charAt(0); int d = readInt(); player[i] = new Action(c, d);
		}
		for(int i = 0; i < n; i++)
		{
			char c = next().charAt(0); int d = readInt(); bot[i] = new Action(c, d);
		}
		int phealth = h, bhealth = h, phumility = 0, bhumility = 0; boolean pdodged = false, bdodged = false; 
		for(int i = 0; i < 2*n; i++)
		{
			Action pmove = player[i/2], bmove = bot[i/2];
			if(i%2 == 0)
			{
				if(pmove.c == 'A')
				{
					if(bdodged) { pmove.d = 0; bdodged = false; }
					bhealth -= pmove.d;
				}
				else
				{
					if(bdodged) { bhealth -= bhumility; bdodged = false; }
					pdodged = true; phumility = pmove.d;
				}
				if(bhealth <= 0) { System.out.println("VICTORY"); return; }
			}
			else
			{
				if(bmove.c == 'A')
				{
					if(pdodged) { bmove.d = 0; pdodged = false; }
					phealth -= bmove.d;
				}
				else
				{
					if(pdodged) { phealth -= phumility; pdodged = false; }
					bdodged = true; bhumility = bmove.d;
				}
				if(phealth <= 0) { System.out.println("DEFEAT"); return; }
			}
		}
		if(bdodged) { bhealth -= bhumility; bdodged = false; }
		if(bhealth <= 0) { System.out.println("VICTORY"); return; }
		System.out.println("TIE");
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

	static float readFloat() throws IOException {
		return Float.parseFloat(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}