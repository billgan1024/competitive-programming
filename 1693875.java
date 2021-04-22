import java.util.*;
import java.io.*;

public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static ArrayList<Integer>[] adj;
	static ArrayList<Integer> currentPath = new ArrayList<Integer>();
	static boolean exists = false;
	static boolean[] vis;
	
	static class Player
	{
		int pos, speed;
		public Player(int pos, int speed)
		{
			this.pos = pos; this.speed = speed;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		for(int i = 0; i < 5; i++)
		{
			char[] line = readLine().toCharArray();
			ArrayList<Player> players = new ArrayList<Player>();
			Comparator<Player> comp = new Comparator<Player>()
			{
				@Override
				public int compare(Player arg0, Player arg1) {
					return arg0.pos - arg1.pos;
				}
			};
			for(int j = 0; j < line.length; j++)
			{
				if(line[j] != '.') players.add(new Player(j, Character.getNumericValue(line[j])));
			}
			for(int j = 0; j < 5; j++)
			{
				
				printPlayers(players, line.length);
				
				for(int k = 0; k < players.size(); k++)
				{
					players.get(k).pos += players.get(k).speed;
					if(players.get(k).pos >= line.length)
					{
						players.remove(k);
						k--;
					}
				}
			}
		}
	}
	
	static void printPlayers(ArrayList<Player> players, int length)
	{
		int[] out = new int[length];
		for(int i = 0; i < length; i++) out[i] = -1;
		
		for(Player p : players)
		{
			if(out[p.pos] == -1) out[p.pos] = p.speed;
			else out[p.pos] += p.speed;
		}
		for(int i : out)
		{
			if(i == -1) System.out.print('.');
			else System.out.print(i);
		}
		System.out.println();
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

	public static int lower_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] >= x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}

	public static int upper_bound(int[] arr, int x) {
		int low = 0, high = arr.length, mid = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (arr[mid] > x)
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}
}