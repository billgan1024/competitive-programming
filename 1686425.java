import java.util.*;
import java.io.*;

public class ContestOfficial {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException
	{
		HashMap<String, String> pairs = new HashMap<String, String>();
		int n = readInt();
		if(n == 1)
		{
			System.out.println("bad");
			return;
		}
		String[] students = readLine().split(" ");
		
		for(int i = 0; i < n; i++)
		{
			String assign = next();
			if(assign.equals(students[i]))
			{
				System.out.println("bad"); return;
			}
			
			if(pairs.containsKey(students[i]))
			{
				if(!pairs.get(students[i]).equals(assign))
				{
					System.out.println("bad"); return;
				}
			}
			else
			{
				pairs.put(assign, students[i]);
			}
		}
		System.out.println("good");
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