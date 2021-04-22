#include <bits/stdc++.h>
using namespace std;
int pink, green, red, orange, sum, total, cnt, minc = INT_MAX;
void print(int p, int g, int r, int o)
{
    printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n", p, g, r, o);
}
int main()
{
    cin >> pink >> green >> red >> orange >> total;
    for(int p = 0; ; p++)
    {
        sum = p*pink; if(sum > total) break;
        for(int g = 0; ; g++)
        {
            sum = p*pink + g*green; if(sum > total) break;
            for(int r = 0; ; r++)
            {
                sum = p*pink + g*green + r*red; if(sum > total) break;
                for(int o = 0; ; o++)
                {
                    sum = p*pink + g*green + r*red + o*orange; if(sum > total) break;
                    if(sum == total)
                    {
                        print(p, g, r, o); cnt++; minc = min(minc, p+g+r+o);
                    }
                }
            }
        }
    }
    printf("Total combinations is %d.\nMinimum number of tickets to print is %d.\n", cnt, minc);
}