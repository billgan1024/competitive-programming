import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		String list = "abcdefghijklmnopqrstuvwxyz";
		
		String s = readLine();
		
		ArrayList<Integer> sequences = new ArrayList<Integer>();
		
		for(int i = 0; i < s.length()-1; i++)
		{
			if(s.charAt(i+1)-s.charAt(i) == 1)
			{
				sequences.add(i);
			}
		}
		
		boolean found = false;
		for(int i = 0; i < list.length(); i++)
		{
			if(found) break;
			char c = list.charAt(i);
			int indOf = s.indexOf(c);
			int lastIndOf = s.lastIndexOf(c);
			for(int j = 0; j < sequences.size(); j++)
			{
				if(sequences.get(j) >= indOf && sequences.get(j) < lastIndOf)
				{
					found = true;
					break;
				}
			}
		}

		if(found) System.out.println("Sushi is Here!");
		else System.out.println("Better Luck Next Time.");
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