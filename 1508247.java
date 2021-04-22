import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int size = Integer.parseInt(in.readLine());
		ArrayList<Integer> array = new ArrayList<Integer>(0);
		
		for(int x = 0; x < size; x++)
		{
			int a = Integer.parseInt(in.readLine());
			array.add(x, a);
		}
		
		Collections.sort(array);
		
		for(int x = 0; x < array.size(); x++)
		{
			System.out.println(array.get(x));
		}
    }
}