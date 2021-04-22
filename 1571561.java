import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException
	{
		String s = readLine();
		String clubs = s.substring(s.indexOf('C')+1, s.indexOf('D'));
		String diamonds = s.substring(s.indexOf('D')+1, s.indexOf('H'));
		String hearts = s.substring(s.indexOf('H')+1, s.indexOf('S'));
		String spades = s.substring(s.indexOf('S')+1);
		
		int cpts = 0, dpts = 0, hpts = 0, spts = 0;
		
		if(clubs.contains("A")) cpts += 4;
		if(clubs.contains("K")) cpts += 3;
		if(clubs.contains("Q")) cpts += 2;
		if(clubs.contains("J")) cpts += 1;
		
		cpts += Math.max(3 - clubs.length(), 0);
		
		if(diamonds.contains("A")) dpts += 4;
		if(diamonds.contains("K")) dpts += 3;
		if(diamonds.contains("Q")) dpts += 2;
		if(diamonds.contains("J")) dpts += 1;
		
		dpts += Math.max(3 - diamonds.length(), 0);
		
		if(hearts.contains("A")) hpts += 4;
		if(hearts.contains("K")) hpts += 3;
		if(hearts.contains("Q")) hpts += 2;
		if(hearts.contains("J")) hpts += 1;
		
		hpts += Math.max(3 - hearts.length(), 0);
		
		if(spades.contains("A")) spts += 4;
		if(spades.contains("K")) spts += 3;
		if(spades.contains("Q")) spts += 2;
		if(spades.contains("J")) spts += 1;
		
		spts += Math.max(3 - spades.length(), 0);
		
		System.out.println("Cards Dealt              Points");
		System.out.print("Clubs ");
		for(int i = 0; i < clubs.length(); i++)
		{
			System.out.print(clubs.charAt(i) + " ");
		}
		System.out.println("     " + cpts);
		
		System.out.print("Diamonds ");
		for(int i = 0; i < diamonds.length(); i++)
		{
			System.out.print(diamonds.charAt(i) + " ");
		}
		System.out.println("     " + dpts);
		
		System.out.print("Hearts ");
		for(int i = 0; i < hearts.length(); i++)
		{
			System.out.print(hearts.charAt(i) + " ");
		}
		System.out.println("     " + hpts);
		
		System.out.print("Spades ");
		for(int i = 0; i < spades.length(); i++)
		{
			System.out.print(spades.charAt(i) + " ");
		}
		System.out.println("     " + spts);
		System.out.println("Total " + (cpts + dpts + hpts + spts));
		
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