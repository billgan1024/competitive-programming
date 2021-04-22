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
const int MV = 2e5+1;

int n, m, s[MV]; unordered_map<int, int> f; ll ans;
int main()
{
    //count # of pairs of elements which are equal in prefix sum mod m
    //for each entry, count # of pairs (i, j) (i < j) which can be made, j is that entry 
    //use a hashmap cuz total number of distinct remainders is only O(n) and not O(m)
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m); f[0]++;
    for(int i = 1; i <= n; i++)
    {
        sc(s[i]); s[i] = (s[i] + s[i-1]) % m;
        ans += f[s[i]]; f[s[i]]++;
    }
    pr(ans);
}