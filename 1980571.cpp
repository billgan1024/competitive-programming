#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MV = 3e5+1;

int n, m, arr[MV], freq[MV][21], bit[MV][21];
int main()
{
    //get the prefix frequency, then
    //construct a binary indexed tree to get the frequency of numbers in the range [l, r]
    //then you can get the goodness of the cth best item by looking at the frequency range and determining
    //the goodness that it falls under
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 1, g; i <= n; i++)
    {
        copy(begin(freq[i-1]), end(freq[i-1]), begin(freq[i]));
        scan(g); arr[i] = g; freq[i][g]++;
        int k = i&-i, l = i-k+1, r = i;
        for(int j = 0; j <= 20; j++)
        {
            bit[i][j] = freq[r][j]-freq[l-1][j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        int cmd, a, b, l, r, c; scan(cmd);
        if(cmd == 1)
        {
            scan(a, b); int o = arr[a]; arr[a] = b;
            //update bit
            for(int j = a; j <= n; j += j&-j)
            {
                bit[j][o]--; bit[j][b]++;
            }
        }
        else
        {
            scan(l, r, c); int lfreq[21], rfreq[21], range[21]; ms(lfreq); ms(rfreq); ms(range);
            for(int j = r; j > 0; j -= j&-j)
            {
                for(int k = 0; k <= 20; k++) rfreq[k] += bit[j][k];
            }
            for(int j = l-1; j > 0; j -= j&-j)
            {
                for(int k = 0; k <= 20; k++) lfreq[k] += bit[j][k];
            }
            for(int j = 0; j <= 20; j++) range[j] = rfreq[j] - lfreq[j];
            for(int k = 20, cnt = 0; k >= 0; k--)
            {
                cnt += range[k]; if(cnt >= c) { print(k, nl); break; }
            }
        }
    }
}