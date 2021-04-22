import java.io.*;
import java.util.*;

public class Main {
    public static boolean rotateResult(int n)
	{
		String str = String.valueOf(n);
		String reverse = "";
		for(int x = str.length() - 1; x >= 0; x--)
		{
			char c = str.charAt(x);
			if(c == '6')
			{
				reverse += '9';
			}
			else if(c == '9')
			{
				reverse += '6';
			}
			else if(c == '0' || c == '1' || c == '8')
			{
				reverse += c;
			}
			else
			{
				return false;
			}
		}
		
		if(str.equals(reverse))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int m = Integer.parseInt(in.readLine());
		int n = Integer.parseInt(in.readLine());
		
		int num = 0;
		
		for(int x = m; x <= n; x++)
		{
			if(rotateResult(x))
			{
				num++;
			}
		}
		
		System.out.println(num);
		
	}
}