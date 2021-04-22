import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Deforestation {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		int[] trees = new int[n];
		int[] treeSums = new int[n];
		
		trees[0] = readInt();
		treeSums[0] = trees[0];
		for(int x = 1; x < n; x++)
		{
			trees[x] = readInt();
			treeSums[x] = trees[x] + treeSums[x-1];
		}
		
		int queries = readInt();
		for(int x = 0; x < queries; x++)
		{
			int a = readInt(), b = readInt();
			if(a == 0) System.out.println(treeSums[b]);
			else
			{
				System.out.println(treeSums[b] - treeSums[a-1]);
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