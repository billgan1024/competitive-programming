import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int days = Integer.parseInt(in.readLine());

		StringTokenizer st = new StringTokenizer(in.readLine());
		StringTokenizer st2 = new StringTokenizer(in.readLine());
		
		int sumA = 0, sumB = 0;
		int maxEqual = -1;
		for(int x = 0; x < days; x++)
		{
			sumA += Integer.parseInt(st.nextToken());
			sumB += Integer.parseInt(st2.nextToken());
			
			if(sumA == sumB) maxEqual = x;
		}
		
		System.out.println(maxEqual + 1);
	}
}