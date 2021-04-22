import java.util.*;
import java.io.*;

public class ChancesOfWinning {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int winOutcomes = 0;
	static int[] teams = new int[4];
	static int root;
	
	static ArrayList<Game> games = new ArrayList<Game>();
	
	static class Game
	{
		int team1, team2;
		public Game(int team1, int team2)
		{
			this.team1 = team1;
			this.team2 = team2;
		}
	}
	
	public static void getAllOutcomes()
	{
		//base case
		Game game = games.remove(0);
		if(games.size() == 0)
		{
			int a = game.team1, b = game.team2;
			int[][] result = {{3, 0}, {0, 3}, {1, 1}};
			for(int i = 0; i < result.length; i++)
			{
				teams[a] += result[i][0];
				teams[b] += result[i][1];
				
				boolean best = true;
				
				for(int j = 0; j < teams.length; j++)
				{
					if(j != root && teams[j] >= teams[root])
					{
						best = false; break;
					}
				}
				
				if(best) winOutcomes++;
				
				teams[a] -= result[i][0];
				teams[b] -= result[i][1];
			}
		}
		else
		{
			int a = game.team1, b = game.team2;
			int[][] result = {{3, 0}, {0, 3}, {1, 1}};
			for(int i = 0; i < result.length; i++)
			{
				teams[a] += result[i][0];
				teams[b] += result[i][1];
				
				getAllOutcomes();
				
				teams[a] -= result[i][0];
				teams[b] -= result[i][1];
			}
		}
		games.add(0, game);
		
	}

	public static void main(String[] args) throws IOException {
		
		root = readInt()-1;
		int g = readInt();

		games.add(new Game(0, 1)); 
		games.add(new Game(0, 2)); 
		games.add(new Game(0, 3));
		games.add(new Game(1, 2));
		games.add(new Game(1, 3));
		games.add(new Game(2, 3));
	
		for(int i = 0; i < g; i++)
		{
			int a = readInt()-1, b = readInt()-1, sa = readInt()-1, sb = readInt()-1;
			for(int j = 0; j < games.size(); j++)
			{
				if(games.get(j).team1 == a && games.get(j).team2 == b)
				{
					games.remove(j);
					break;
				}
			}
			if(sa > sb)
			{
				teams[a] += 3;
			}
			else if(sb > sa)
			{
				teams[b] += 3;
			}
			else
			{
				teams[a]++; teams[b]++;
			}
		}
		
		getAllOutcomes();
		System.out.println(winOutcomes);

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