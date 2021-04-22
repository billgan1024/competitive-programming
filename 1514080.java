import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int height = Integer.parseInt(in.readLine());
		
		int count = 1;
		int dir = 1;
		for(int x = 0; x < height; x++)
		{
			String line = "";
			for(int y = 0; y < count; y++)
			{
				line += "*";
			}
			
			for(int y = 0; y < (2 * height) - (2 * count); y++)
			{
				line += " ";
			}
			
			for(int y = 0; y < count; y++)
			{
				line += "*";
			}
			
			if(count == height) dir *= -1;
			count += dir * 2;
			
			System.out.println(line);
		}
	}
}