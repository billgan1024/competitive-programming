import java.util.*;
import java.io.*;

public class TestLol {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), q = readInt(); 
		int[] a = new int[n+2], pmax = new int[n+2], smax = new int[n+2], pfreq = new int[n+2], sfreq = new int[n+2];
		for(int i = 1; i <= n; i++)
		{
			a[i] = readInt();
			if(a[i] > pmax[i-1]) { pmax[i] = a[i]; pfreq[i] = 1; }
			else if(a[i] == pmax[i-1]) { pmax[i] = a[i]; pfreq[i] = pfreq[i-1]+1; }
			else { pmax[i] = pmax[i-1]; pfreq[i] = pfreq[i-1]; }
		}
		
		for(int i = n; i >= 1; i--)
		{
			if(a[i] > smax[i+1]) { smax[i] = a[i]; sfreq[i] = 1; }
			else if(a[i] == smax[i+1]) { smax[i] = a[i]; sfreq[i] = sfreq[i+1]+1; }
			else { smax[i] = smax[i+1]; sfreq[i] = sfreq[i+1]; }
		}
		
		for(int i = 0; i < q; i++)
		{
			int c = readInt(), d = readInt();
			int maxl = pmax[c-1], maxr = smax[d+1], freql = pfreq[c-1], freqr = sfreq[d+1];
			System.out.print(Math.max(maxl, maxr) + " ");
			if(maxl == maxr) System.out.println(freql + freqr);
			else System.out.println(maxl > maxr ? freql : freqr);
		}
	}

	static String readLine() throws IOException
	{
		return br.readLine().trim();
	}
	
	static String next() throws IOException
	{
		while(st == null || !st.hasMoreTokens())
		{
			st = new StringTokenizer(readLine());
		}
		return st.nextToken();
	}
	
	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}
}