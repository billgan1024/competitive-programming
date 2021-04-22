import java.util.*;
import java.io.*;
public class Veci {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String input = "";
    static String output = "";
    static boolean found = false;
    
    public static void printAllPermutations(String c, String str)
	{
    	if(!found)
    	{
			if(str.length() == 1)
			{
				if(Integer.parseInt(c + str) > Integer.parseInt(input))
				{
					System.out.println(c + str);
					found = true;
				}
			}
			else
			{
				for(int x = 0; x < str.length(); x++)
				{
					String temp = str.substring(0, x) + str.substring(x+1); //gets the new string w/o the chosen letter str[x]
					printAllPermutations(c + str.substring(x, x + 1), temp);
				}
		}
    	}
	}
    
    public static void main(String[] args) throws IOException 
    {
    	input = readLine();
        char[] ch = input.toCharArray();
        Arrays.sort(ch);
        
        String sortedInput = "";
		
		for(char x : ch)
		{
			sortedInput += x;
		}
        
        
        printAllPermutations("", sortedInput);
        if(!found) System.out.println("0");
        
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