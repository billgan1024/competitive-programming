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
			String hall = in.readLine();
			int position = hall.indexOf('*');
			for(int x = 0; x < 5; x++)
			{
				String s = in.readLine();
				if(s.equals("R")) position = Math.min(position + 1, hall.length() - 1);
				else position = Math.max(position - 1, 0);
			}
			
			String result = "";
			
			for(int x = 0; x < hall.length(); x++)
			{
				if(x == position) result += "*";
				else result += ".";
			}
			System.out.println(result);
			
		}
		
	}

}