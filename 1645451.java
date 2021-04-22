import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.StringTokenizer;


public class Lol {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static class Champion
	{
		int val, index;
		public Champion(int val, int index)
		{
			this.val = val;
			this.index = index;
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		int n = readInt(), k = readInt();
		Champion[] champions = new Champion[n];
		
		for(int i = 0; i < n; i++)
		{
			champions[i] = new Champion(readInt(), i);
		}
		
		int[] friends = new int[n];
		
		int[] answers = new int[n];
		
		for(int i = 0; i < k; i++)
		{
			int a = readInt()-1, b = readInt()-1;
			if(champions[a].val > champions[b].val) friends[a]++;
			else if(champions[b].val > champions[a].val) friends[b]++;
		}
		
		Comparator<Champion> comp = new Comparator<Champion>()
		{
			@Override
			public int compare(Champion arg0, Champion arg1) {
				return arg0.val - arg1.val;
			}
		};
		
		Arrays.sort(champions, comp);
		
		String s = "";
		for(int i = 0; i < n; i++)
		{
			int index = i;
			//get the # of champions this champion can defeat
			while(index > 0 && champions[index-1].val == champions[index].val)
			{
				index--;
			}
			//also subtract friends
			index -= friends[champions[i].index];
			//update answer array for this champion
			answers[champions[i].index] = index;
		}
		for(int i : answers)
		{
			System.out.print(i + " ");
		}
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}

}