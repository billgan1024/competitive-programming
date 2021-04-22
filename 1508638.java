import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		ArrayList<String> text = new ArrayList<String>();
		
		while(st.hasMoreTokens())
		{
			text.add(st.nextToken());
		}
		for (int x = 1; x < text.size(); x++)
		{
			if(Character.isUpperCase(text.get(x).charAt(0)))
			{
				//add a period to the previous word
				text.set(x - 1, text.get(x - 1) + ".");
			}
			System.out.print(text.get(x - 1) + " ");
		}
		System.out.print(text.get(text.size() - 1) + ".");
	}
}