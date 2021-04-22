import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class MimiBinary {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		String str = readLine();
		int[] input = new int[str.length()];
		for(int i = 0; i < str.length(); i++)
		{
			input[i] = Character.getNumericValue(str.charAt(i));
		}
		
		int[] preCountZero = new int[input.length];
		int[] preCountOne = new int[input.length];
		
		preCountZero[0] = input[0] == 0 ? 1 : 0;
		preCountOne[0] = input[0] == 1 ? 1 : 0;
		
		for(int i = 1; i < input.length; i++)
		{
			preCountZero[i] = preCountZero[i-1] + (input[i] == 0 ? 1 : 0);
			preCountOne[i] = preCountOne[i-1] + (input[i] == 1 ? 1 : 0);
		}
		
		int q = readInt();
		for(int i = 0; i < q; i++)
		{
			int x = readInt()-1, y = readInt(), z = readInt();
			if(z == 0)
			{
				//binary search pre zero count for y + prezerocount[x-1] if index != 0
				if(x == 0)
				{
					int index = Arrays.binarySearch(preCountZero, y);
					if(index < 0)
					{
						//not found
						System.out.println(-1);
					}
					else
					{
						//find leftmost index
						while(index-1 >= 0 && preCountZero[index-1] == preCountZero[index]) index--;
						System.out.println(index + 1);
					}
				}
				else
				{
					int index = Arrays.binarySearch(preCountZero, y + preCountZero[x-1]);
					if(index < 0)
					{
						//not found
						System.out.println(-1);
					}
					else
					{
						//find leftmost index
						while(index-1 >= 0 && preCountZero[index-1] == preCountZero[index]) index--;
						System.out.println(index + 1);
					}
				}
			}
			else
			{
				if(x == 0)
				{
					int index = Arrays.binarySearch(preCountOne, y);
					if(index < 0)
					{
						//not found
						System.out.println(-1);
					}
					else
					{
						//find leftmost index
						while(index-1 >= 0 && preCountOne[index-1] == preCountOne[index]) index--;
						System.out.println(index + 1);
					}
				}
				else
				{
					int index = Arrays.binarySearch(preCountOne, y + preCountOne[x-1]);
					if(index < 0)
					{
						//not found
						System.out.println(-1);
					}
					else
					{
						//find leftmost index
						while(index-1 >= 0 && preCountOne[index-1] == preCountOne[index]) index--;
						System.out.println(index + 1);
					}
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
	static String readLine () throws IOException {
	    return br.readLine().trim();
	}

}