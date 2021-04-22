import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class SecretSanta {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	//arraylist to keep track of the total stress over all the permutations of trips
	static ArrayList<Integer> totalWeights = new ArrayList<Integer>();
	
	public static void calcAllWeights(int l, int currentWeight, ArrayList<Integer> remainingFloors, ArrayList<Integer> remainingWeights)
	{
		//BASE CASE (if there is only one remaining floor
		if(remainingFloors.size() == 1)
		{
			//add the last weight needed to complete the run
			int distance = Math.abs(l - remainingFloors.get(0));
			int weights = remainingWeights.get(0);
			currentWeight += (distance + 1) * weights;
			//add the total weight to the global list
			totalWeights.add(currentWeight);
			
		}
		else
		{
			//simulate going thru all of them (when we still have more than 1 to choose from)
			for(int x = 0; x < remainingFloors.size(); x++)
			{
				//move to this floor and add up weights
				int distance = Math.abs(l - remainingFloors.get(x));
				int weights = 0;
				//sum up weights
				for(int y = 0; y < remainingWeights.size(); y++)
				{
					weights += remainingWeights.get(y);
				}
				//call this method again using updated currentweight, updated location
				
				//add this extra weight that is caused by moving to this theoretical floor
				currentWeight += (distance + 1) * weights;
				//remove this floor and weight from subsequent calls
				int f = remainingFloors.get(x);
				int w = remainingWeights.get(x);
				remainingFloors.remove(x);
				remainingWeights.remove(x);
				//update location
				int original = l;
				l = f;
				
				//recursive call
				calcAllWeights(l, currentWeight, remainingFloors, remainingWeights);
				
				//RESET variables that we changed (because we are testing all possible conditions from the same start condition)
				currentWeight -= (distance + 1) * weights;
				remainingFloors.add(x, f);
				remainingWeights.add(x, w);
				l = original;
			}
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		int count = readInt();
		
		int location = 101; //current location of banta
		ArrayList<Integer> floors = new ArrayList<Integer>();
		ArrayList<Integer> weights = new ArrayList<Integer>();
		for(int x = 0; x < count; x++)
		{
			floors.add(readInt());
			weights.add(readInt());
		}
		calcAllWeights(location, 0, floors, weights);
		//calculate min weight
		int minWeight = Integer.MAX_VALUE;
		for(int x = 0; x < totalWeights.size(); x++)
		{
			minWeight = Math.min(minWeight, totalWeights.get(x));
		}
		System.out.println(minWeight);
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