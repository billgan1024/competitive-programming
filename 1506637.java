import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		String count = in.readLine();
		StringTokenizer st = new StringTokenizer(in.readLine());
		int written = 0;
		
		for(int x = 0; x < Integer.parseInt(count); x++)
		{
			String str = st.nextToken();
			if(str.length() <= 10)
			{
				written++;
			}
		}
		
		System.out.println(String.valueOf(written));

	}
}