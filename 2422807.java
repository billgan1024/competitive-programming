import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BattlePositions {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		int[] stations = new int[n];
		//set up the difference array
		int[] dif = new int[n];
		
		//the threshold (each station must have >= this number of troops)
		int thres = readInt();
		
		int waves = readInt();
		
		for(int x = 0; x < waves; x++)
		{
			//start, end, and amnt to add
			int i = readInt() - 1, f = readInt() - 1, k = readInt();
			dif[i] += k;
			if(f != dif.length - 1) dif[f+1] -= k;
		}
		
		//calculate the updated array by taking sum of difference array
		int count = 0;
		stations[0] = dif[0];
		if(stations[0] < thres) count++;
		for(int x = 1; x < stations.length; x++)
		{
			//stations is the total change in the troops
			stations[x] = dif[x] + stations[x-1];
			if(stations[x] < thres) count++;
		}
		System.out.println(count);
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