import java.util.*;
import java.io.*;

public class CountSquares {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int h = readInt(), v = readInt();
		
		if(h < 2 || v < 2) System.out.println(0);
		else
		{
			int[] h_lines = new int[h];
			int[] v_lines = new int[v];
			
			for(int i = 0; i < h; i++)
			{
				h_lines[i] = readInt();
			}
			for(int i = 0; i < v; i++)
			{
				v_lines[i] = readInt();
			}
			
			int result = 0;
			
			HashMap<Integer, Integer> horizontalDistances = new HashMap<Integer, Integer>();
			
			for(int i = 0; i < h_lines.length; i++)
			{
				for(int a = i + 1; a < h_lines.length; a++)
				{
					//get sum
					int sumHorizontal = h_lines[a]-h_lines[i];
					
					//map this horizontal sum to a frequency hashmap
					if(!horizontalDistances.containsKey(sumHorizontal))
					{
						horizontalDistances.put(sumHorizontal, 1);
					}
					else
					{
						horizontalDistances.put(sumHorizontal, horizontalDistances.get(sumHorizontal)+1);
					}
				}
			}
			
			HashMap<Integer, Integer> verticalDistances = new HashMap<Integer, Integer>();
			
			for(int j = 0; j < v_lines.length; j++)
			{
				for(int b = j+1; b < v_lines.length; b++)
				{
					int sumVertical = v_lines[b] - v_lines[j];
					
					if(!verticalDistances.containsKey(sumVertical))
					{
						verticalDistances.put(sumVertical, 1);
					}
					else
					{
						verticalDistances.put(sumVertical, verticalDistances.get(sumVertical)+1);
					}
				}
			}
			
			for(int i : verticalDistances.keySet())
			{
				if(horizontalDistances.containsKey(i))
				{
					result += verticalDistances.get(i) * horizontalDistances.get(i);
				}
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

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}