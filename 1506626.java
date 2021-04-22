import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int count = Integer.parseInt(in.readLine());
		StringTokenizer st = new StringTokenizer(in.readLine());
		int written = 0;
		
		for(int x = 0; x < count; x++)
		{
			String str = st.nextToken();
			if(str.length() <= 10)
			{
				written++;
			}
		}
		
		System.out.println(written + "");

	}
}