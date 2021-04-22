import java.io.*;
import java.util.*;
public class Test
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException
	{
		int n = readInt(), q = readInt();
		HashMap<Integer, ArrayList<Integer>> rows = new HashMap<Integer, ArrayList<Integer>>();
		HashMap<Integer, ArrayList<Integer>> cols = new HashMap<Integer, ArrayList<Integer>>();
		
		for(int i = 0; i < n; i++)
		{
			int c = readInt()-1, r = readInt()-1;
			ArrayList<Integer> row_temp = rows.getOrDefault(r, new ArrayList<Integer>());
			row_temp.add(c);
			rows.put(r, row_temp);
			ArrayList<Integer> col_temp = cols.getOrDefault(c, new ArrayList<Integer>());
			col_temp.add(r);
			cols.put(c, col_temp);
		}
		
		for(int i = 0; i < q; i++)
		{
			int cmd = readInt();
			if(cmd == 1)
			{
				int c = readInt()-1, r = readInt()-1;
				if(rows.getOrDefault(r, new ArrayList<Integer>()).contains(c)) System.out.println("salty");
				else System.out.println("bland");
			}
			else if(cmd == 2)
			{
				char dim = next().charAt(0);
				if(dim == 'X')
				{
					int col = readInt()-1;
					System.out.println(cols.getOrDefault(col, new ArrayList<Integer>()).size());
				}
				else if(dim == 'Y')
				{
					int row = readInt()-1;
					System.out.println(rows.getOrDefault(row, new ArrayList<Integer>()).size());
				}
			}
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
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}