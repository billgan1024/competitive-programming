import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Poetry {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException
	{
		int count = readInt();
		
		for(int i = 0; i < count; i++)
		{
			String[] syllables = new String[4];
			for(int x = 0; x < 4; x++)
			{
				String str = "";
				st = new StringTokenizer(br.readLine());
				while(st.hasMoreTokens()) str = st.nextToken(); //str is the last token
				str = str.toLowerCase();
				boolean added = false;
				
				for(int y = str.length() - 1; y >= 0; y--)
				{
					char c = str.charAt(y);
					if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
					{
						//add the "last syllable" to syllables
						syllables[x] = str.substring(y);
						added = true;
						break;
					}
				}
				if(!added) syllables[x] = str;
			}
			
			String result = "";
			
			//check form
			if(syllables[0].equals(syllables[1]) && syllables[0].equals(syllables[2]) && syllables[0].equals(syllables[3]))
			{
				result = "perfect";
			}
			else if(syllables[0].equals(syllables[1]) && syllables[2].equals(syllables[3]))
			{
				result = "even";
			}
			else if(syllables[0].equals(syllables[2]) && syllables[1].equals(syllables[3]))
			{
				result = "cross";
			}
			else if(syllables[0].equals(syllables[3]) && syllables[1].equals(syllables[2]))
			{
				result = "shell";
			}
			else
			{
				result = "free";
			}
			System.out.println(result);
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
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}


}