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
const int MV = 1e5+1, MM = 2e4+1;

struct query
{
    int l, r, k, id;
};
//bit tracks mass sums (i.e. the total mass sum of trees with mass in a certain range)
int N, Q, a[MV], bit[MM], ans[MV]; query q[MV];
bool cmpl(query x, query y) { return x.l < y.l; }
bool cmpr(query x, query y) { return x.r < y.r; }
void upd(int idx, int val)
{
    if(idx == 0) return;
    for(int i = idx; i < MM; i += i&-i) bit[i] += val;
}
int sum(int idx)
{
    int ret = 0;
    for(int i = idx; i > 0; i -= i&-i) ret += bit[i];
    return ret;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    for(int i = 1; i <= N; i++) sc(a[i]);
    sc(Q);
    for(int i = 1; i <= Q; i++) { sc(q[i].l, q[i].r, q[i].k);  q[i].l++; q[i].r++; q[i].id = i; }
    sort(q+1, q+Q+1, cmpr);
    auto it = q+1; bool ended = false;
    for(int i = 1; i <= N && !ended; i++)
    {
        upd(a[i], a[i]);
        while(it->r == i)
        {
            ans[it->id] += sum(MM-1) - sum(it->k-1); it++;
            if(it == q+Q+1) { ended = true; break; }
        }
    }
    ms(bit, 0); sort(q+1, q+Q+1, cmpl); ended = false; it = q+1;
    for(int i = 0; i < N && !ended; i++)
    {
        upd(a[i], a[i]);
        while(it->l == i+1)
        {
            ans[it->id] -= sum(MM-1) - sum(it->k-1); it++;
            if(it == q+Q+1) { ended = true; break; }
        }
    }
    for(int i = 1; i <= Q; i++) pr(ans[i], nl);
}