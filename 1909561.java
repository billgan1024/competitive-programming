import java.util.*;
import java.io.*;

public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(); TreeSet<Integer> set = new TreeSet<Integer>();
		String s = readLine(); int[] pre = new int[n], suf = new int[n];
		pre[0] = s.charAt(0) == '1' ? 0 : -1; 
		for(int i = 1; i < n; i++)
		{
			if(s.charAt(i) == '1')
			{
				pre[i] = 0;
			}
			else
			{
				if(pre[i-1] == -1) pre[i] = -1;
				else pre[i] = pre[i-1]+1;
			}
		}
		
		suf[n-1] = s.charAt(n-1) == '1' ? 0 : -1;
		for(int i = n-2; i >= 0; i--)
		{
			if(s.charAt(i) == '1')
			{
				suf[i] = 0;
			}
			else
			{
				if(suf[i+1] == -1) suf[i] = -1;
				else suf[i] = suf[i+1]+1;
			}
		}
		long count = 0;
		for(int i = 0; i < n; i++)
		{
			if(pre[i] == -1) count += suf[i];
			else if(suf[i] == -1) count += pre[i];
			else count += Math.min(pre[i], suf[i]);
		}
		System.out.println(count);
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