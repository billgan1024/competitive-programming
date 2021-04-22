import java.util.*;
import java.io.*;

public class PerfectTiming {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	@SuppressWarnings("deprecation")
	public static void main(String[] args) throws IOException {
		
		int xstart = readInt(), ystart = readInt(), xend = readInt(), yend = readInt();
		
		int seconds = Math.abs(xend-xstart) + Math.abs(yend-ystart);
		
		String[] curTime = readLine().split(":");
		Calendar cd = new GregorianCalendar
				(Integer.parseInt(curTime[0]), Integer.parseInt(curTime[1]),
				Integer.parseInt(curTime[2]), Integer.parseInt(curTime[3]),
				Integer.parseInt(curTime[4]), Integer.parseInt(curTime[5]));
		
		cd.add(Calendar.SECOND, seconds);
		
		String y = String.format("%04d", cd.get(Calendar.YEAR));
		String mo = String.format("%02d", cd.get(Calendar.MONTH));
		String d = String.format("%02d", cd.get(Calendar.DAY_OF_MONTH));
		String h = String.format("%02d", cd.get(Calendar.HOUR_OF_DAY));
		String m = String.format("%02d", cd.get(Calendar.MINUTE));
		String s = String.format("%02d", cd.get(Calendar.SECOND));
		
		if(y.equals("2014") && mo.equals("02") && d.equals("29"))
		{
			mo = "03"; d = "01";
		}
		
		
		System.out.println(y + ":" + mo + ":"
				+ d + ":" + h + ":"
				+ m + ":" + s);
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