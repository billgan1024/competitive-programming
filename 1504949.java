import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		
		for(int x = 1; x <= n; x++)
		{
			System.out.print(x + " ");
		}
		
	}
}