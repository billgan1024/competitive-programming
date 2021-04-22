import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Nightmare {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		//prefix and suffix the max episode, when the query starts take prefix of a and suffix of b
		int n = readInt(), q = readInt();
		int[] ratings = new int[n];
		int[] pre = new int[n];
		int[] suf = new int[n];
		int[] maxPreCount = new int[n];
		int[] maxSufCount = new int[n];
		
		ratings[0] = readInt();
		pre[0] = ratings[0];
		
		int maxPreNum = ratings[0]; //the current max integer to store counts on
		
		maxPreCount[0] = 1; //there is 1 max element here
		
		for(int i = 1; i < n; i++)
		{
			ratings[i] = readInt();
			pre[i] = Math.max(ratings[i], pre[i-1]);
			if(ratings[i] < maxPreNum)
			{
				//maxPreNum is still the biggest so set it to the previous count
				maxPreCount[i] = maxPreCount[i-1];
			}
			else if(ratings[i] == maxPreNum)
			{
				maxPreCount[i] = maxPreCount[i-1] + 1;
			}
			else
			{
				maxPreCount[i] = 1;
				maxPreNum = ratings[i];
			}
		}
		
		//update suffix arrays
		int maxSufNum = ratings[ratings.length-1];
		suf[suf.length-1] = ratings[ratings.length-1];
		maxSufCount[maxSufCount.length-1] = 1;
		
		for(int i = n-2; i >= 0; i--)
		{
			suf[i] = Math.max(ratings[i], suf[i+1]);
			if(ratings[i] < maxSufNum)
			{
				//maxSufCount is still the biggest so set it to the previous count
				maxSufCount[i] = maxSufCount[i+1];
			}
			else if(ratings[i] == maxSufNum)
			{
				maxSufCount[i] = maxSufCount[i+1] + 1;
			}
			else
			{
				maxSufCount[i] = 1;
				maxSufNum = ratings[i];
			}
		}
		
		for(int x = 0; x < q; x++)
		{
			int a = readInt() - 1, b = readInt() - 1;
			int maxRating = 0, maxCount = 0;
			if(a == 0)
			{
				maxRating = suf[b+1];
				maxCount = maxSufCount[b+1];
			}
			else if(b == n-1)
			{
				maxRating = pre[a-1];
				maxCount = maxPreCount[a-1];
			}
			else
			{
				maxRating = Math.max(pre[a-1], suf[b+1]);
				if(pre[a-1] < suf[b+1]) maxCount = maxSufCount[b+1];
				else if(pre[a-1] > suf[b+1]) maxCount = maxPreCount[a-1];
				else maxCount = maxPreCount[a-1] + maxSufCount[b+1];
			}
			System.out.println(maxRating + " " + maxCount);
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