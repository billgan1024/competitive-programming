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

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		for(int i = 0; i < 5; i++)
		{
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int nextA = a - b;
			int sugarRushes = 0;
			int count = 0;
			
			while(a > 0)
			{
				a -= Math.pow(2, sugarRushes);
				if(a <= nextA)
				{
					sugarRushes++;
					nextA = a - b;
				}
				count++;
			}
			
			System.out.println(count);
		}
		
	}

}