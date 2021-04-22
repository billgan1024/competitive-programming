import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int count = Integer.parseInt(in.readLine());
		StringTokenizer st;
		
		for(int x = 0; x < count; x++)
		{
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			System.out.println(a+b);
		}
    }
}