import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class FavouriteTimes {
	
	public static boolean isSequence(int h, int m)
	{
		String hour = h + "", min = m + "";
		if(min.length() == 1) min = "0" + min;
		String hm = hour + min;
		int d = 0;
		for(int x = 1; x < hm.length(); x++)
		{
			int t = Character.getNumericValue(hm.charAt(x)) - Character.getNumericValue(hm.charAt(x-1));
			if(x == 1) d = t;
			else if(t != d)
			{
				return false;
			}
		}
		return true;
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws Exception
	{
		int duration = readInt();
		
		int hour = 12;
		int minute = 0;
		int result = 0;
		
		while(duration >= 1440)
		{
			duration -= 1440;
			result += 62;
		}
		
		for(int x = 0; x <= duration; x++)
		{
			if(isSequence(hour, minute)) result++;
			
			minute++;
			if(minute == 60)
			{
				minute = 0;
				hour++;
				if(hour == 13) hour = 1;
			}
			
		}
		System.out.println(result);
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