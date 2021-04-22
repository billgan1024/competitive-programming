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
			
			
			int[] h_diff = new int[h-1];
			int[] h_diff_sum = new int[h-1];
			int[] v_diff = new int[v-1];
			int[] v_diff_sum = new int[v-1];
			
			int sum = 0;
			
			for(int i = 1; i < h; i++)
			{
				h_diff[i-1] = h_lines[i] - h_lines[i-1];
				sum += h_diff[i-1];
				h_diff_sum[i-1] = sum;
			}
			
			sum = 0;
			for(int i = 1; i < v; i++)
			{
				v_diff[i-1] = v_lines[i] - v_lines[i-1];
				sum += v_diff[i-1];
				v_diff_sum[i-1] = sum;
			}
			
			int result = 0;
			
			HashMap<Integer, Integer> horizontalDistances = new HashMap<Integer, Integer>();
			
			for(int i = 0; i < h_diff.length; i++)
			{
				for(int a = 0; a + i < h_diff.length; a++)
				{
					//get sum
					int sumHorizontal = 0;
					if(a == 0) sumHorizontal = h_diff_sum[a+i];
					else sumHorizontal = h_diff_sum[a+i] - h_diff_sum[a-1];
					
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
			
			for(int j = 0; j < h_diff.length; j++)
			{
				for(int b = 0; b + j < v_diff.length; b++)
				{
					int sumVertical = 0;
					if(b == 0) sumVertical = v_diff_sum[b+j];
					else sumVertical = v_diff_sum[b+j] - v_diff_sum[b-1];
					
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