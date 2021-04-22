import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Paradox {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		ArrayList<Boolean> arr = new ArrayList<Boolean>();
		
		int c = readInt();
		
		for(int i = 0; i < c; i++)
		{
			int cmdNum = readInt();
			
			switch(cmdNum)
			{
				case 1: 
					Boolean bool = Boolean.parseBoolean(next());
					if(arr.contains(bool)) System.out.println("false");
					else
					{
						arr.add(bool); 
						System.out.println("true");
					}
				break;
				
				case 2: 
					Boolean bool2 = Boolean.parseBoolean(next());
					if(!arr.contains(bool2)) System.out.println("false");
					else
					{
						arr.remove(bool2); 
						System.out.println("true");
					}
				break;
				
				case 3: 
					Boolean bool3 = Boolean.parseBoolean(next());
					System.out.println(arr.indexOf(bool3));
				break;
				
				case 4:
					ArrayList<Boolean> temp = arr;
					Collections.sort(temp);
					String s = "";
					for(int x = 0; x < temp.size(); x++)
					{
						s += temp.get(x) + " ";
					}
					s = s.trim();
					System.out.println(s);
				break;
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
	static String readLine () throws IOException {
		return br.readLine().trim();
	}


}