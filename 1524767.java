import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	public static boolean isVowel(char c)
	{
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
		else return false;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		for(int i = 0; i < 5; i++)
		{
			st = new StringTokenizer(in.readLine());
			String a = st.nextToken();
			String b = st.nextToken();
			
			a = a.toLowerCase();
			b = b.toLowerCase();
			
			String result = "";
			
			if(a.length() != b.length()) result = "different";
			else
			{
				for(int x = 0; x < a.length(); x++)
				{
					if(isVowel(a.charAt(x)) != isVowel(b.charAt(x)))
					{
						result = "different";
						break;
					}
				}
			}
			if(result == "") result = "same";
			System.out.println(result);
		}
		
	}

}