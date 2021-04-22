import java.util.*;
import java.io.*;

public class GeneratingNames {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static long factorial(int n) {
		long fact = 1;
		int i = 1;
		while(i <= n) {
			fact *= i;
			i++;
		}
		return fact;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(), k = readInt();
		String name = readLine();
		int[] freq = new int[26];
		for(int i = 0; i < n; i++)
		{
			if(name.charAt(i) != '*') freq[name.charAt(i)-'a']++;
		}
		
		long result = 0;
		if(k == 0)
		{
			result = factorial(n);
			for(int i = 0; i < 26; i++) result /= factorial(freq[i]);
			System.out.println(result);
		}
		else if(k == 1)
		{
			for(int i = 0; i < 26; i++)
			{
				freq[i]++;
				long temp = factorial(n);
				for(int j = 0; j < 26; j++) temp /= factorial(freq[j]);
				result += temp;
				freq[i]--;
			}
			System.out.println(result);
		}
		else
		{
			for(int i = 0; i < 26; i++)
			{
				freq[i]++;
				for(int j = i; j < 26; j++)
				{
					freq[j]++;
					long temp = factorial(n);
					for(int m = 0; m < 26; m++) temp /= factorial(freq[m]);
					result += temp;
					freq[j]--;
				}
				freq[i]--;
			}
			System.out.println(result);
		}
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