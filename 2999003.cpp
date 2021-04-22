#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e5+1;

int n, s, q, d[MV]; unordered_set<int> stand[MV]; set<pii> candies[100]; char c;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, s);
    for(int i = 1; i <= n; i++) sc(d[i]);
    for(int i = 1, si, ai; i <= s; i++)
    {
         sc(si, ai); stand[si].insert(ai); candies[ai].insert({d[si], si});
    }
    sc(q);
    for(int i = 1, x, k; i <= q; i++)
    {
        sc(c);
        if(c == 'A')
        {
            sc(x, k); stand[x].insert(k); candies[k].insert({d[x], x});
        }
        else if(c == 'S')
        {
            sc(x, k); stand[x].erase(k); candies[k].erase({d[x], x});
        }
        else if(c == 'E')
        {
            sc(x, k);
            for(int st : stand[x]) candies[st].erase({d[x], x});
            d[x] = k; stand[x].clear();
        }
        else
        {
            sc(k);
            if(candies[k].empty()) pr(-1, nl);
            else pr(candies[k].begin()->second, nl);
        }
    }
}