import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ShipDefense {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException
	{
		double health = readInt();
		int defenseCount = readInt(), enemyCount = readInt();
		int[][] defenseModes = new int[defenseCount][2]; //armour is first, then shield
		int[] incDamageDif = new int[1002]; //difference array to store incoming damage
		//array is 0-501 but put an extra element slot for the last difference
		for(int i = 0; i < defenseCount; i++)
		{
			defenseModes[i][0] = readInt(); //armour
			defenseModes[i][1] = readInt(); //shield
		}
		
		for(int i = 0; i < enemyCount; i++)
		{
			int start = readInt(), duration = readInt(), dmg = readInt();
			incDamageDif[start] += dmg;
			incDamageDif[start+duration] -= dmg;
		}
		
		//take the sum array and take the min damage each time
		int total = 0;
		int incDamage = total + incDamageDif[0];
		double dmgReceived = Integer.MAX_VALUE;
		for(int i = 0; i < defenseCount; i++)
		{
			//get minimum dmg to take (subtract shield from dmg, apply multiplier from armour)
			double r = ((double)Math.max(incDamage-defenseModes[i][1], 0))*(((double)100-(double)defenseModes[i][0])/(double)100);
			if(dmgReceived > r)
			{
				dmgReceived = r;
			}
		}
		//if there are no shields
		if(dmgReceived == Integer.MAX_VALUE) dmgReceived = incDamage;
		health -= dmgReceived;
		total += incDamageDif[0];
		
		for(int i = 1; i < incDamageDif.length-1; i++)
		{
			int inc = total + incDamageDif[i];
			
			double received = Integer.MAX_VALUE;
			for(int j = 0; j < defenseCount; j++)
			{
				//get minimum dmg to take (subtract shield from dmg, apply multiplier from armour)
				double r = ((double)Math.max(inc-defenseModes[j][1], 0))*(((double)100-(double)defenseModes[j][0])/(double)100);
				if(received > r)
				{
					received = r;
				}
			}
			if(received == Integer.MAX_VALUE) received = inc;
			
			health -= received;
			
			total += incDamageDif[i];
		}
		
		if(health <= 0) System.out.println("DO A BARREL ROLL!");
		else 
		{
			System.out.println(String.format("%.2f", health));
		}
		
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
	static String readLine () throws IOException {
	    return br.readLine().trim();
	}

}