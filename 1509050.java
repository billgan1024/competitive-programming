import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		ArrayList<String> original = new ArrayList<String>();
		ArrayList<String> copy = new ArrayList<String>();
		
		while(st.hasMoreTokens())
		{
			original.add(st.nextToken());
		}
		
		st = new StringTokenizer(in.readLine());
		
		while(st.hasMoreTokens())
		{
			copy.add(st.nextToken());
		}
		
		int threshold = Integer.parseInt(in.readLine());
		boolean exposed = true;
		int changed = 0;
		
		for(int x = 0; x < original.size(); x++)
		{
			String og = original.get(x);
			String cp = copy.get(x);
			if(og.length() != cp.length())
			{
				exposed = false;
				break;
			}
			else
			{
				for(int y = 0; y < og.length(); y++)
				{
					if(og.charAt(y) != cp.charAt(y))
					{
						changed++;
						if(changed == threshold)
						{
							exposed = false;
							break;
						}
					}
				}
			}
		}
		
		System.out.println(exposed ? "Plagiarized" : "No plagiarism");
		
	}
}