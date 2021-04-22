import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int daytime = Integer.parseInt(in.readLine());
		int evening = Integer.parseInt(in.readLine());
		int weekend = Integer.parseInt(in.readLine());
		
		double totalA = ((Math.max(daytime - 100, 0) * 25) + (evening * 15) + (weekend * 20))/100.0;
		double totalB = ((Math.max(daytime - 250, 0) * 45) + (evening * 35) + (weekend * 25))/100.0;
		
		
		
		System.out.printf("Plan A costs %.2f\n", totalA);
		System.out.printf("Plan B costs %.2f\n", totalB);
		
		if(totalA < totalB)
		{
			System.out.println("Plan A is cheapest.");
		}
		else if(totalA == totalB)
		{
			System.out.println("Plan A and B are the same price.");
		}
		else
		{
			System.out.println("Plan B is cheapest.");
		}
	}
}