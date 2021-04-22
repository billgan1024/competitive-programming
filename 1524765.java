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
			int weight = Integer.parseInt(in.readLine());
			int closestDistance = Integer.MAX_VALUE;
			String closestItem = "";
			int closestItemWeight = 0;
			
			for(int x = 0; x < 4; x++)
			{
				st = new StringTokenizer(in.readLine());
				String item = st.nextToken();
				int thisWeight = Integer.parseInt(st.nextToken());
				
				if(closestDistance > Math.abs(weight - thisWeight))
				{
					closestDistance = Math.abs(weight - thisWeight);
					closestItem = item;
					closestItemWeight = thisWeight;
				}
				else if(closestDistance == Math.abs(weight - thisWeight))
				{
					if(thisWeight > closestItemWeight)
					{
						closestDistance = Math.abs(weight - thisWeight);
						closestItem = item;
						closestItemWeight = thisWeight;
					}
				}
			}
			
			System.out.println(closestItem);
		}
		
	}

}