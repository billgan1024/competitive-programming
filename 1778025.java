import java.util.*;
import java.io.*;

public class JamesPosters {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n, totalArea; static Rectangle[] rects;
	static int multiplier = 1; static ArrayList<Integer> currentSet = new ArrayList<Integer>();
	
	static void combinations(int level, int k) {
		if(level == k) totalArea += area()*multiplier;
		else
		{
			int start;
			if(level == 0) start = 0;
			else start = currentSet.get(currentSet.size()-1) + 1;
			
			for(int i = start; i < n; i++) {
				currentSet.add(i);
				combinations(level+1, k);
				currentSet.remove(currentSet.size()-1);
			}
		}
	}
	
	static int area() {
		Rectangle cur = rects[currentSet.get(0)];
		
		for(int i = 1; i < currentSet.size(); i++) {
			cur = intersection(cur, rects[currentSet.get(i)]);
		}
		return cur.getArea();
	}
	
	static class Rectangle
	{
		int x1, y1, x2, y2;
		public Rectangle(int x1, int y1, int x2, int y2) {
			if(x1 >= x2 || y1 <= y2) 
			{
				this.x1 = 0; this.y1 = 0; this.x2 = 0; this.y2 = 0;
			}
			else
			{
				this.x1 = x1; this.y1 = y1; this.x2 = x2; this.y2 = y2;
			}
		}
		
		@Override
		public boolean equals(Object r) {
			Rectangle o = (Rectangle) r;
			return this.x1 == o.x1 && this.y1 == o.y1 && this.x2 == o.x2 && this.y2 == o.y2;
		}
		
		public int getArea() {
			return (x2-x1)*(y1-y2);
		}
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		n = readInt(); rects = new Rectangle[n];
		for(int i = 0; i < n; i++) {
			rects[i] = new Rectangle(readInt(), readInt(), readInt(), readInt());
		}
		
		for(int i = 1; i <= n; i++) {
			combinations(0, i);
			multiplier *= -1;
		}
		
		System.out.println(totalArea);
	}
	
	static Rectangle intersection(Rectangle r, Rectangle s) {
		Rectangle invalid = new Rectangle(0, 0, 0, 0);
		if(r.equals(invalid) || s.equals(invalid)) return invalid;
		else
		{
			int x1 = Math.max(r.x1, s.x1);
			int y1 = Math.min(r.y1, s.y1);
			int x2 = Math.min(r.x2, s.x2);
			int y2 = Math.max(r.y2, s.y2);
			return new Rectangle(x1, y1, x2, y2);
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