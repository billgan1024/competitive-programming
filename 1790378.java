import java.util.*;
import java.io.*;

public class AthenaIsland {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int min = Integer.MAX_VALUE, low = Integer.MAX_VALUE, high = Integer.MAX_VALUE;
	
	static class Point
	{
		int val, index;
		public Point(int val, int index) {
			this.val = val; this.index = index;
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		int n = readInt(); 
		ArrayList<Point> pos = new ArrayList<Point>(), neg = new ArrayList<Point>();
		for(int i = 1; i <= n; i++) {
			int a = readInt();
			if(a >= 0) pos.add(new Point(a, i));
			else neg.add(new Point(a, i));
		}
	
		Comparator<Point> posComp = new Comparator<Point>() {
			@Override
			public int compare(Point arg0, Point arg1) {
				if(arg0.val == arg1.val) return arg0.index-arg1.index;
				return arg0.val-arg1.val;
			}
		};
		
		Comparator<Point> negComp = new Comparator<Point>() {
			@Override
			public int compare(Point arg0, Point arg1) {
				if(arg0.val == arg1.val) return arg0.index-arg1.index;
				return arg1.val-arg0.val;
			}
		};
		
		Collections.sort(pos, posComp); Collections.sort(neg, negComp);
		
		if(pos.size() == 0) {
			int a = neg.get(0).val, b = neg.get(1).val;
			System.out.println(Math.abs(a+b));
			if(neg.get(0).index < neg.get(1).index) 
				System.out.println(neg.get(0).index + " " + neg.get(1).index);
			else
			{
				System.out.println(neg.get(1).index + " " + neg.get(0).index);
			}
			return;
		}
		
		if(neg.size() == 0) {
			int a = pos.get(0).val, b = pos.get(1).val;
			System.out.println(Math.abs(a+b));
			if(pos.get(0).index < pos.get(1).index) 
				System.out.println(pos.get(0).index + " " + pos.get(1).index);
			else
			{
				System.out.println(pos.get(1).index + " " + pos.get(0).index);
			}
			return;
		}
		
		if(pos.size() >= 2) {
			int c = pos.get(0).val, d = pos.get(1).val;
			int lower = pos.get(0).index, higher = pos.get(1).index;
			if(lower > higher) {
				int temp = lower; lower = higher; higher = temp;
			}
			if(Math.abs(c+d) < min) {
				min = Math.abs(c+d); low = lower; high = higher;
			}
			else if(Math.abs(c+d) == min) {
				if(lower < low || (lower == low && higher < high))
				{
					low = lower; high = higher;
				}
			}
		}
		
		if(neg.size() >= 2) {
			int c = neg.get(0).val, d = neg.get(1).val;
			int lower = neg.get(0).index, higher = neg.get(1).index;
			if(lower > higher) {
				int temp = lower; lower = higher; higher = temp;
			}
			if(Math.abs(c+d) < min) {
				min = Math.abs(c+d); low = lower; high = higher;
			}
			else if(Math.abs(c+d) == min) {
				if(lower < low || (lower == low && higher < high))
				{
					low = lower; high = higher;
				}
			}
		}
		
		int i = 0, j = 0; 
		while(true) {
			//size()-1 is the "finished" state
			if(i == pos.size() || j == neg.size()) break;
			Point a = pos.get(Math.min(i, pos.size()-1));
			Point b = neg.get(Math.min(j, neg.size()-1));
			
			int lower = a.index, higher = b.index;
			if(lower > higher) {
				int temp = lower; lower = higher; higher = temp;
			}

			if(Math.abs(a.val+b.val) < min) {
				min = Math.abs(a.val+b.val); low = lower; high = higher;
			}
			else if(Math.abs(a.val+b.val) == min) {
				if(lower < low || (lower == low && higher < high))
				{
					low = lower; high = higher;
				}
			}
			
			if(Math.abs(a.val) <= Math.abs(b.val) || j == neg.size())
				i++;
			else
				j++;
		}
		
		System.out.println(min);
		System.out.println(low + " " + high);
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

	static float readFloat() throws IOException {
		return Float.parseFloat(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}