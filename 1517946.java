import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int a = Integer.parseInt(in.readLine());
		int b = Integer.parseInt(in.readLine());
		int c = Integer.parseInt(in.readLine());
		int d = Integer.parseInt(in.readLine());
		
		int cals = 0;
		
		switch(a)
		{
			case 1: cals += 461;
			break;
			case 2: cals += 431;
			break;
			case 3: cals += 420;
			break;
		}
		
		switch(b)
		{
			case 1: cals += 100;
			break;
			case 2: cals += 57;
			break;
			case 3: cals += 70;
			break;
		}
		
		switch(c)
		{
			case 1: cals += 130;
			break;
			case 2: cals += 160;
			break;
			case 3: cals += 118;
			break;
		}
		
		switch(d)
		{
			case 1: cals += 167;
			break;
			case 2: cals += 266;
			break;
			case 3: cals += 75;
			break;
		}
		
		System.out.println("Your total Calorie count is " + cals + ".");
	}
}