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
			int a = Integer.parseInt(in.readLine());
			for(int x = 1; x <= a; x++)
			{
				for(int y = 1; y <= x; y++)
				{
					System.out.print("*");
				}
				System.out.println("");
			}
			for(int x = a - 1; x >= 1; x--)
			{
				for(int y = 1; y <= x; y++)
				{
					System.out.print("*");
				}
				System.out.println("");
			}
		}
		
	}

}