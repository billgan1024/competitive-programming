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
const int MV = 2e5+1;

struct query { int l, r, k, id; ll ans; };
bool cmp(query x, query y) { return x.id < y.id; }
bool cmpl(query x, query y) { return x.l < y.l; }
bool cmpr(query x, query y) { return x.r < y.r; }
int N, Q, a[MV], f[MV]; ll bit[MV]; query q[MV];
void upd(int idx, int val)
{
    for(int i = idx; i < MV; i += i&-i) bit[i] += val;
}
ll sum(int idx)
{
    ll ret = 0;
    for(int i = idx; i > 0; i -= i&-i) ret += bit[i];
    return ret;
}
int main()
{
    //upper complexity is O(nlogn)
    cin.sync_with_stdio(0); cin.tie(0); sc(N, Q);
    for(int i = 1; i <= N; i++)
    {
        sc(a[i]); f[i] = a[i];
    }
    //f: rank -> element (ranks are in the range 1 to 2e5)
    //f-1: element -> rank can be obtained with binary search
    sort(f+1, f+N+1);
    for(int i = 1; i <= Q; i++) { sc(q[i].l, q[i].r, q[i].k); q[i].id = i; }
    //sort these queries by a particular attribute so you can easily compute the value of each query.
    //the value of each query = element sum >= k in 1 to r - element sum < k in 1 to r - element sum >= k in
    //1 to l-1 + element sum < k in 1 to l-1
    //thus, the bit tracks the "element sum" i.e. the index stores the type of element,
    //the value stores the total sum of that element (element * count)
    sort(q+1, q+Q+1, cmpr); auto it = q+1;
    bool ended = false;
    for(int i = 1; i <= N && !ended; i++)
    {
        int rk = lower_bound(f+1, f+N+1, a[i]) - f; upd(rk, a[i]);
        //update the queries if necessary here (pointer call by reference is pog)
        while(it->r == i)
        {
            int queryRank = lower_bound(f+1, f+N+1, it->k) - f;
            it->ans += sum(MV-1) - 2*sum(queryRank-1);
            it++; if(it == q+Q+1) { ended = true; break; }
        }
    }
    ended = false; sort(q+1, q+Q+1, cmpl); it = q+1;
    ms(bit, 0);
    for(int i = 1; i < N && !ended; i++)
    {
        int rk = lower_bound(f+1, f+N+1, a[i]) - f; upd(rk, a[i]);
        while(it->l <= i+1)
        {
            if(it->l == i+1)
            {
                int queryRank = lower_bound(f+1, f+N+1, it->k) - f;
                it->ans -= sum(MV-1) - 2*sum(queryRank-1);
            }
            it++; if(it == q+Q+1) { ended = true; break; }
        }
    }
    sort(q+1, q+Q+1, cmp);
    for(int i = 1; i <= Q; i++) pr(q[i].ans, nl);
}