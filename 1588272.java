import java.util.*;
import java.io.*;

public class Acidiclul {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		
		int[][] freq = new int[1001][2];
		
		//hash the data to map each index (value of the sensor) to a frequency
		
		for(int i = 0; i < n; i++)
		{
			int k = readInt();
			freq[k][0]++;
		}
		
		//apply indexes
		for(int i = 0; i < freq.length; i++)
		{
			freq[i][1] = i;
		}
		
		
		//sort by frequency
		Arrays.sort(freq, new Comparator<int[]>() { 
			@Override
			public int compare(int[] o1, int[] o2)
			{
				//sort by first column ONLY
				return o1[0] - o2[0];
			}
	    }); 
		
		//take group of highest freq and group of second highest freq, determine the greatest difference
		ArrayList<Integer> mostFrequent = new ArrayList<Integer>();
		ArrayList<Integer> secondFrequent = new ArrayList<Integer>();
		
		mostFrequent.add(freq[freq.length-1][1]);
		int j = freq.length-2;
		while(j > 0 && freq[j][0] == freq[freq.length-1][0])
		{
			mostFrequent.add(freq[j][1]);
			j--;
		}
		if(freq[j][0] == 0) //no more second frequent numbers
		{
			//get max difference from the only list
			Collections.sort(mostFrequent);
			System.out.println(mostFrequent.get(mostFrequent.size()-1) - mostFrequent.get(0));
		}else
		{
			secondFrequent.add(freq[j][1]);
			int k = j-1;
			while(k > 0 && freq[k][0] == freq[j][0])
			{
				secondFrequent.add(freq[k][1]);
				k--;
			}
			
			//get max difference from the two lists
			Collections.sort(mostFrequent);
			Collections.sort(secondFrequent);
			if(mostFrequent.size() > 1) System.out.println(mostFrequent.get(mostFrequent.size()-1) - mostFrequent.get(0));
			else
			{
				int dist1 = Math.abs(mostFrequent.get(0) - secondFrequent.get(secondFrequent.size()-1));
				int dist2 = Math.abs(mostFrequent.get(0) - secondFrequent.get(0));
				System.out.println(Math.max(dist1, dist2));
			}
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