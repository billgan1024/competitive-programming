import java.util.*;
import java.io.*;

public class ContestOfficial3 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static class Box
	{
		int l, w, h;
		long vol;
		public Box(int l, int w, int h)
		{
			this.l = l; this.w = w; this.h = h;
			vol = (long)l * (long) w * (long) h;
		}
	}

	public static void main(String[] args) throws IOException {
		
		int n = readInt();
		Box[] boxes = new Box[n];
		for(int i = 0; i < n; i++)
		{
			int[] a = new int[3];
			for(int j = 0; j < 3; j++)
			{
				a[j] = readInt();
			}
			Arrays.sort(a);
			boxes[i] = new Box(a[0], a[1], a[2]);
		}
		Comparator<Box> comp = new Comparator<Box>()
		{
			@Override
			public int compare(Box o1, Box o2) {
				// TODO Auto-generated method stub
				return (int) (o1.vol - o2.vol);
			}
		};
		Arrays.sort(boxes, comp);
		
		int m = readInt();
		for(int i = 0; i < m; i++)
		{
			int[] a = new int[3];
			for(int j = 0; j < 3; j++)
			{
				a[j] = readInt();
			}
			Arrays.sort(a);
			
			boolean found = false;
			for(int j = 0; j < n; j++)
			{
				if(boxes[j].l >= a[0] && boxes[j].w >= a[1] && boxes[j].h >= a[2])
				{
					System.out.println(boxes[j].vol);
					found = true;
					break;
				}
			}
			if(!found) System.out.println("Item does not fit.");
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