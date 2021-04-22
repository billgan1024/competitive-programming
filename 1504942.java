import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(in.readLine());
		
		for(int x = 0; x < cases; x++)
		{
			StringTokenizer st = new StringTokenizer(in.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			long p = Long.parseLong(st.nextToken());
			
			if((long) a*b == p)
			{
				System.out.println("POSSIBLE DOUBLE SIGMA");
			}
			else
			{
				System.out.println("16 BIT S/W ONLY");
			}
		}
	}
}