import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int a = Integer.parseInt(in.readLine());
		int b = (int) Math.floor(Math.sqrt(a));
		System.out.println("The largest square has side length " + b + ".");
	}
}