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
const int MV = 1e5+1;

//r[i]: the # of the student with rank i
//use a disjoint set with path compression and union by rank
//path compression speeds up parent_find up to amortized constant time
//union by size of pbds limits the total number of nodes added to pbds to nlogn
int n, m, q, r[MV], p[MV]; pbds s[MV]; char cmd;
int parent_find(int i)
{
    if(p[i] != i) p[i] = parent_find(p[i]);
    return p[i];
}
void merge(int x, int y)
{
    int fx = parent_find(x), fy = parent_find(y);
    if(fx != fy)
    {
        if(sz(s[fx]) < sz(s[fy])) swap(fx, fy);
        p[fy] = fx;
        for(int i : s[fy]) s[fx].insert(i);
    }
}
int query(int x, int k)
{
    int fx = parent_find(x);
    if(k >= sz(s[fx])) return -1;
    else return r[*s[fx].find_by_order(k)];
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m);
    for(int i = 1, x; i <= n; i++)
    {
        sc(x); r[x] = i;
        p[i] = i; s[i].insert(x);
    }
    for(int i = 1, x, y; i <= m; i++)
    {
        sc(x, y); merge(x, y);
    }
    sc(q);
    for(int i = 1, x, y, k; i <= q; i++)
    {
        sc(cmd);
        if(cmd == 'B')
        {
            sc(x, y); merge(x, y);
        }
        else
        {
            sc(x, k); pr(query(x, k-1), nl);
        }
    }
}