import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Perket {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static <T> T[][] combinations(T[] a) {

	    int len = a.length;
	    if (len > 31)
	        throw new IllegalArgumentException();

	    int numCombinations = (1 << len) - 1;

	    @SuppressWarnings("unchecked")
	    T[][] combinations = (T[][]) java.lang.reflect.Array.newInstance(a.getClass(), numCombinations);

	    // Start i at 1, so that we do not include the empty set in the results
	    for (int i = 1; i <= numCombinations; i++) {

	        @SuppressWarnings("unchecked")
	        T[] combination = (T[]) java.lang.reflect.Array.newInstance(a.getClass().getComponentType(),
	                Integer.bitCount(i));

	        for (int j = 0, ofs = 0; j < len; j++)
	            if ((i & (1 << j)) > 0)
	                combination[ofs++] = a[j];

	        combinations[i - 1] = combination;
	    }

	    return combinations;
	}
	
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		int[] sours = new int[n];
		int[] bitters = new int[n];
		//array for getting all combinations
		Integer[] test = new Integer[n];
		
		for(int x = 0; x < test.length; x++)
		{
			test[x] = x;
		}
		
		for(int i = 0; i < n; i++)
		{
			sours[i] = readInt();
			bitters[i] = readInt();
		}
		
		//Arrays.sort(sours);
		//Arrays.sort(bitters);
		Integer[][] testCombos = combinations(test);
		//loop through all combinations of test
		
		int minDifference = Integer.MAX_VALUE;
		for(int x = 0; x < testCombos.length; x++)
		{
			//loop thru this combination
			int sourProduct = 1;
			int bitterSum = 0;
			for(int y = 0; y < testCombos[x].length; y++)
			{
				sourProduct *= sours[testCombos[x][y]];
				bitterSum += bitters[testCombos[x][y]];
			}
			minDifference = Math.min(minDifference, Math.abs(sourProduct - bitterSum));
		}
			
			
		System.out.println(minDifference);
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