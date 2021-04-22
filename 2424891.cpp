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
typedef pair<int, int> pii;
const int MV = 1e6+1;

int n, a[MV], ans[MV]; set<int> banks;
int main()
{
    //banks: the banks u still need to raid
    cin.sync_with_stdio(0); cin.tie(0); sc(n); bool valid = false;
    for(int i = 1; i <= n; i++) { banks.insert(i); sc(a[i]); if(i > 1 && a[i] != a[i-1]) valid = true; }
    if(!valid) { pr(-1); return 0; }

    for(int i = 1; i <= n; i++)
    {
        //bank[i]: what day you will attack bank i
        if(i > 1 && banks.find(a[i-1]) != banks.end() && a[i] != a[i-1])
        {
            banks.erase(a[i-1]); ans[i] = a[i-1];
        }
    }

    if(banks.find(a[n]) != banks.end() && a[1] != a[n])
    {
        banks.erase(a[n]); ans[1] = a[n];
    }
    for(int i = 1; i <= n; i++)
    {
        if(!ans[i])
        {
            ans[i] = *banks.begin(); banks.erase(banks.begin());
        }
        pr(ans[i], sp);
    }
}