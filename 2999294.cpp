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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int MV = 5e5+1;

int n, bit[MV]; ll ans;
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
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1, x; i <= n; i++)
    {
        //put each element on the left or right based on how many new inversions they would contribute
        //note that each element's inversion contribution does not depend on previous elements' inversion count,
        //nor does it get influenced by future elements' inversions
        //each time, you are adding inversions from a new element to an old element, even if a new element means
        //an old element has a new inversion, that pair would go to the new element -> old element so we don't overcount
        //thus each element is independent, we take the minimum of the choices
        sc(x); upd(x, 1); ans += min(sum(MV-1) - sum(x), sum(x-1));
    }
    pr(ans);
}