import java.util.*;
import java.io.*;

public class WhenInRome {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		for(int i = 0; i < n; i++)
		{
			String s = next();
			
			String first = s.substring(0, s.indexOf('+'));
			String second = s.substring(s.indexOf('+') + 1, s.indexOf('='));
			int firstNum = 0, secondNum = 0;
			
			
			for(int j = 0; j < first.length(); j++)
			{
				if(first.charAt(j) == 'M')
				{
					firstNum += 1000;
				}
				else if(first.charAt(j) == 'D')
				{
					firstNum += 500;
				}
				else if(first.charAt(j) == 'C')
				{
					if(j != first.length()-1 && (first.charAt(j+1) == 'D' || first.charAt(j+1) == 'M'))
					{
						firstNum -= 100;
					}
					else firstNum += 100;
				}
				else if(first.charAt(j) == 'L')
				{
					firstNum += 50;
				}
				else if(first.charAt(j) == 'X')
				{
					if(j != first.length()-1 && (first.charAt(j+1) == 'L' || first.charAt(j+1) == 'C'))
					{
						firstNum -= 10;
					}
					else firstNum += 10;
				}
				else if(first.charAt(j) == 'V')
				{
					firstNum += 5;
				}
				else if(first.charAt(j) == 'I')
				{
					if(j != first.length()-1 && (first.charAt(j+1) == 'V' || first.charAt(j+1) == 'X'))
					{
						firstNum -= 1;
					}
					else firstNum += 1;
				}
			}
			
			for(int j = 0; j < second.length(); j++)
			{
				if(second.charAt(j) == 'M')
				{
					secondNum += 1000;
				}
				else if(second.charAt(j) == 'D')
				{
					secondNum += 500;
				}
				else if(second.charAt(j) == 'C')
				{
					if(j != second.length()-1 && (second.charAt(j+1) == 'D' || second.charAt(j+1) == 'M'))
					{
						secondNum -= 100;
					}
					else secondNum += 100;
				}
				else if(second.charAt(j) == 'L')
				{
					secondNum += 50;
				}
				else if(second.charAt(j) == 'X')
				{
					if(j != second.length()-1 && (second.charAt(j+1) == 'L' || second.charAt(j+1) == 'C'))
					{
						secondNum -= 10;
					}
					else secondNum += 10;
				}
				else if(second.charAt(j) == 'V')
				{
					secondNum += 5;
				}
				else if(second.charAt(j) == 'I')
				{
					if(j != second.length()-1 && (second.charAt(j+1) == 'V' || second.charAt(j+1) == 'X'))
					{
						secondNum -= 1;
					}
					else secondNum += 1;
				}
			}
			
			int sum = firstNum + secondNum;
			if(sum > 1000) System.out.println(s + "CONCORDIA CUM VERITATE");
			else
			{
				String result = "";
				while(sum > 0)
				{
					if(sum == 1000)
					{
						result += "M";
						sum -= 1000;
					}
					else if(sum >= 900)
					{
						result += "CM";
						sum -= 900;
					}
					else if(sum >= 500)
					{
						result += "D";
						sum -= 500;
					}
					else if(sum >= 400)
					{
						result += "CD";
						sum -= 400;
					}
					else if(sum >= 100)
					{
						result += "C";
						sum -= 100;
					}
					else if(sum >= 90)
					{
						result += "XC";
						sum -= 90;
					}
					else if(sum >= 50)
					{
						result += "L";
						sum -= 50;
					}
					else if(sum >= 40)
					{
						result += "XL";
						sum -= 40;
					}
					else if(sum >= 10)
					{
						result += "X";
						sum -= 10;
					}
					else if(sum >= 9)
					{
						result += "IX";
						sum -= 9;
					}
					else if(sum >= 5)
					{
						result += "V";
						sum -= 5;
					}
					else if(sum >= 4)
					{
						result += "IV";
						sum -= 4;
					}
					else
					{
						result += "I";
						sum -= 1;
					}
				}
				System.out.println(s + result);
			}
		}

	}

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}