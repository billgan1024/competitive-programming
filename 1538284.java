import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class AddUpApples {
	
	static int n;
	static int total = 0;
	
	public static void getAllSums(ArrayList<Integer> nums)
	{
		//take apart last digit
		int lastDigit = nums.get(nums.size() - 1);
		if(nums.size() == 1)
		{
			for(int i = 1; i <= lastDigit/2; i++)
			{
				//print out the first batch of sums
				System.out.println(n + "=" + i + "+" + (lastDigit-i));
				//calls getallsums again on this new permutation
				ArrayList<Integer> temp = new ArrayList<Integer>();
				temp.add(i); temp.add(lastDigit-i);
				getAllSums(temp);
				total++;
			}
		}
		else
		{
			//take apart last digit
			//index loops starting from second last digit to lastDigit/2 (ensures that index will be at least the previous digit)
			for(int i = nums.get(nums.size() - 2); i <= lastDigit/2; i++)
			{
				//temp array for finding the next sum
				ArrayList<Integer> temp = new ArrayList<Integer>();
				//print all the numbers before it
				System.out.print(n + "=" + nums.get(0));
				temp.add(nums.get(0));
				for(int j = 1; j < nums.size() - 1; j++)
				{
					System.out.print("+" + nums.get(j));
					temp.add(nums.get(j));
				}
				
				//print this sum part
				System.out.print("+" + i);
				System.out.print("+" + (lastDigit-i));
				System.out.println();
				
				temp.add(i);
				temp.add(lastDigit-i);
				
				//get all the elements and put it in a new one
				getAllSums(temp);
				total++;
			}
		}
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		n = readInt();
		ArrayList<Integer> nums = new ArrayList<Integer>();
		nums.add(n);
		getAllSums(nums);
		System.out.println("total=" + total);
	}
	
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}

}