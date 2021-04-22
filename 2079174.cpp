#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int T, N, h, w; bool g[500][500];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(T);
    for(int t = 0; t < T; t++)
    {
        scan(N);
        for(int n = 0; n < N; n++)
        {
            scan(h, w); string s; int lft = 1000, rit = -1, top = 1000, bot = -1, width, height; ms(g, 0);
            for(int i = 0; i < h; i++)
            {
                scan(s);
                for(int j = 0; j < w; j++)
                {
                    g[i][j] = s[j] == '*';
                    if(s[j] == '*')
                    {
                        lft = min(lft, j); rit = max(rit, j);
                        top = min(top, i); bot = max(bot, i);
                    }
                }
            }
            width = rit-lft+1; height = bot-top+1;
            if(width == 1) print(1);
            else
            {
                int hl = width/2, vl = 0; bool found = false;
                for(int i = top; i <= bot; i++)
                {
                    if(g[i][rit])
                    {
                        if(!found) found = true; vl++;
                    }
                    else if(found) break;
                }
                //ideal width should be 2*hl + 1
                //ideal height should be 2*vl + 3
                if(width == 2*hl && height == 2*vl+3) print(3);
                else if(width == 2*hl+1 && height == 2*vl+1) print(4);
                else if(width == 2*hl && height == 2*vl+2) print(7);
                else
                {
                    string dat = "";
                    dat += g[top][lft+1] ? "1" : "0";
                    dat += g[top+1][lft] ? "1" : "0";
                    dat += g[top+1][rit] ? "1" : "0";
                    dat += g[top+vl+1][lft+1] ? "1" : "0";
                    dat += g[top+vl+2][lft] ? "1" : "0";
                    dat += g[top+vl+2][rit] ? "1" : "0";
                    dat += g[top+2*vl+2][lft+1] ? "1" : "0";

                    if(dat == "1011101") print(2);
                    else if(dat == "1011011") print(3);
                    else if(dat == "0111010") print(4);
                    else if(dat == "1101011") print(5);
                    else if(dat == "1101111") print(6);
                    else if(dat == "1010010") print(7);
                    else if(dat == "1111111") print(8);
                    else if(dat == "1111011") print(9);
                    else if(dat == "1110111") print(0);
                }
            }
        }
        print(nl);
    }
}