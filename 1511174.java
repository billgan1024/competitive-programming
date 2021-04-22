import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception 
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int[] measures = new int[Integer.parseInt(in.readLine())];
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		for(int x = 0; x < measures.length; x++)
		{
			measures[x] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(measures);
		
		int index = (int) Math.floor((measures.length - 1) / 2); //index of what to print
		int change = 1; //how much the index changes 
		int sign = 1;
		
		for(int x = 0; x < measures.length; x++)
		{
			System.out.print(measures[index] + " ");
			index += change * sign;
			change += 1;
			sign *= -1;
		}
		
	}
}