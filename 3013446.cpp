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
const int MV = 1e5;

int n, pre[MV]; pii p[MV]; vector<pii> seq, ans;
bool cmp(pii x, pii y) { return x.first < y.first || (x.first == y.first && x.second > y.second); }
bool cmp2(pii x, pii y) { return x.first > y.first; }
int main()
{
    //longest non-increasing subsequence according to right boundary in the sorted intervals = answer
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 0; i < n; i++) sc(p[i].first, p[i].second);
    sort(p, p+n, cmp);
    //maintain a chain that represents a "potential" non-increasing subsequence as well as keeping track
    //of the best one, then backtrack using the prev array on the best one to pick last.
    //dp[i] = longest non-increasing subsequence ending at interval i
    for(int i = 0; i < n; i++)
    {
        //maintain the chain + pre[] to track the previous element to take in
        //one of the longest non-increasing subsequence ending at interval i
        int idx = upper_bound(seq.begin(), seq.end(), make_pair(p[i].second, i), cmp2) - seq.begin();
        if(idx == sz(seq)) {
            if(idx != 0){ pre[i] = seq.back().second; } else pre[i] = -1;
            seq.pb({p[i].second, i});
        }
        else
        {
            seq[idx] = {p[i].second, i};
            if(idx != 0) pre[i] = seq[idx-1].second; else pre[i] = -1;
        }
    }
    pr(sz(seq), nl);
    //last element in this chain is the element with the maximum dp[] value
    for(int i = seq.back().second; i != -1; i = pre[i]) ans.pb({p[i].first, p[i].second});
    for(int i = sz(ans)-1; i >= 0; i--) pr(ans[i].first, sp, ans[i].second, nl);
}