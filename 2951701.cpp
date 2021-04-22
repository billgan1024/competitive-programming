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
unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
mt19937_64 gen(seed); uniform_int_distribution<ll> dis(1, 1e13);
const int MV = 1e5+1;

int n, m; unordered_map<ll, int> f; ll ans, sum, psa, w[MV];
int main()
{
    //hash the values from 1 to m to create a unique sum of random numbers w[1]+...+w[m], WITHOUT overflow
    //a subarray (probably) contains the same frequency of 1 to m if its hash is a multiple of w[1]+...+w[m]
    //(very low chance for a different distribution of numbers from 1 to m to be congruent mod sum)
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m);
    for(int i = 1; i <= m; i++) { w[i] = dis(gen); sum += w[i]; }
    //count # of pairs l < r such that s[r] = s[l] (mod sum)
    //freq map only contains n possible remainders even though there could be 'sum' different remainders
    f[0] = 1;
    for(int i = 1, a; i <= n; i++)
    {
        sc(a); psa = (psa + w[a]) % sum;
        ans += f[psa]; f[psa]++;
    }
    pr(ans);
}