#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define fl() cout << flush
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<string, int> psi;

int n, q; psi v[500];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 0; i < n; i++) sc(v[i].first, v[i].second);
    sc(q);
    for(int i = 0, s, d; i < q; i++)
    {
        sc(s, d); int dis = INT_MAX; string person;
        for(auto p : v)
        {
            if(p.second >= s && p.second <= s+d)
            {
                if(p.second - s < dis)
                {
                    dis = p.second-s; person = p.first;
                }
            }
        }
        if(dis == INT_MAX) pr("No suitable teacher!", nl);
        else pr(person, nl);
    }
}