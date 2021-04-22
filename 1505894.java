import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int count = Integer.parseInt(in.readLine());
		String str = in.readLine();
		
		int a = 0, b = 0;
		
		for(int x = 0; x < str.length(); x++)
		{
			if(str.charAt(x) == 'A')
			{
				a++;
			}
			else
			{
				b++;
			}
		}
		
		if(a > b) System.out.println("A");
		else if (b > a) System.out.println("B");
		else System.out.println("Tie");
    }
}