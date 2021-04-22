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

int t, s[MV], bit[MV], f[MV]; double ans;
void upd(int idx, int v)
{
    for(int i = idx; i < MV; i += i&-i) bit[i] += v;
}
int sum(int idx)
{
    int ret = 0;
    for(int i = idx; i > 0; i -= i&-i) ret += bit[i];
    return ret;
}
int main()
{
    //f serves to compress indices so that each person has a score from 1 to 100000,
    //it preserves order of scores since lower scores are assigned a lower value.
    //then you can maintain a freqbit that can answer how many people have a score >= val
    cin.sync_with_stdio(0); cin.tie(0); sc(t);
    for(int i = 1; i <= t; i++)
    {
        sc(s[i]); f[i] = s[i];
    }
    sort(f+1, f+t+1);
    for(int i = 1; i <= t; i++)
    {
        //you can get the rank (i.e. actual score relative to other people) by bsearching 
        int actualScore = lower_bound(f+1, f+t+1, s[i]) - f; upd(actualScore, 1);
        ans += sum(MV-1) - sum(actualScore) + 1;
    }
    pr(fixed, setprecision(2), ans/t);
}