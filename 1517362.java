import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int a = Integer.parseInt(in.readLine());
		int b = Integer.parseInt(in.readLine());
		int m = 4;
		int t = 2; 
		int c = 3;
		int d = 5;
		
		for(int x = a; x <= b; x++)
		{
			if(m == 4 && t == 2 && c == 3 && d == 5)
			{
				System.out.println("All positions change in year " + x);
			}
			if(m == 4) m = 1; else m++;
			if(t == 2) t = 1; else t++;
			if(c == 3) c = 1; else c++;
			if(d == 5) d = 1; else d++;
		}
	}
}