import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int x = Integer.parseInt(in.readLine());
		int m = Integer.parseInt(in.readLine());
		
		int n = 2;
		
		while((x * n) % m != 1)
		{
			if(n == 100) break;
			n++;
		}
		
		if(n == 100) System.out.println("No such integer exists.");
		else System.out.println(n);
		
	}
}