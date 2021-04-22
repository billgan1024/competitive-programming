import java.util.*;

import java.io.*;

public class PhoneBook {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Bruh
	{
		String name, num;
		int freq;
		public Bruh(String name, String num, int freq)
		{
			this.name = name;
			this.num = num;
			this.freq = freq;
		}
	}

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		Bruh[] book = new Bruh[n];
		for(int i = 0; i < n; i++)
		{
			String s = next(), num = next();
			book[i] = new Bruh(s, num, 0);
		}
		
		Comparator<Bruh> comp = new Comparator<Bruh>()
		{
			@Override
			public int compare(Bruh arg0, Bruh arg1) {
				// TODO Auto-generated method stub
				return Integer.parseInt(arg0.num) - Integer.parseInt(arg1.num);
			}
		};
		
		Arrays.sort(book, comp);
		int d = readInt();
		for(int i = 0; i < d; i++)
		{
			String number = readLine();
			Bruh b = new Bruh("", number, 0);
			int index = Arrays.binarySearch(book, b, comp);
			book[index].freq++;
		}
		
		int maxFreq = -1;
		int person = Integer.MAX_VALUE;
		String actualName = "";
		for(int i = 0; i < n; i++)
		{
			if(book[i].freq > maxFreq)
			{
				maxFreq = book[i].freq;
				person = Integer.parseInt(book[i].num);
				actualName = book[i].name;
			}
			else if(book[i].freq == maxFreq)
			{
				if(Integer.parseInt(book[i].num) < person)
				{
					person = Integer.parseInt(book[i].num);
					actualName = book[i].name;
				}
			}
		}
		
		System.out.println(actualName);
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