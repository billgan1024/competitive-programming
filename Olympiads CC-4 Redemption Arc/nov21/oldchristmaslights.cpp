#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("Ofast")
#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
template<typename T, class cmp = less<T>> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
const int maxN = 1e5+1, LOG = 17;

int n, k, q, a[maxN], f[maxN], st[maxN][LOG], idx[maxN][LOG]; deque<int> mn, mx;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::unitbuf);
    sc(n, k); for(int i = 1; i <= n; i++) sc(a[i]);
    //calculate f[i]: the max length of a valid subarray with its left endpoint at index i
    //you can easily do this in O(n) time with two sliding windows going from right to left
    for(int l = n, r = n; l > 0; l--) {
        //add a[l] to the deque (remember that deque tracks indices)
        while(!mn.empty() && a[l] <= a[mn.front()]) mn.pop_front();
        while(!mx.empty() && a[l] >= a[mx.front()]) mx.pop_front();
        mn.push_front(l); mx.push_front(l);
        //min = a[mn.back()], max = a[mx.back()]
        while(a[mx.back()]-a[mn.back()] > k) {
            if(mx.back() == r) mx.pop_back();
            if(mn.back() == r) mn.pop_back(); 
            r--;
        }
        st[i][0] = r-l+1; idx[i][0] = i; 
    }
    //then, push all values of f[l] into a sparse table and perform queries like this:
    //we are trying to find max(min(f[i], r-i+1)) as i ranges between l and r (with tiebreakers applied)
    //we can't use any data structure only once to query the max value with min values easily
    //observation: there can only exist one index such that for this index and beyond,
    //min(f[i], r-i+1) = r-i+1 (the optimal array would touch the right endpoint)
    //binary search for this index and find the max one, make sure to break ties with lowest index
    //use two nlogn tables to break ties (idx[i][j] = left endpoint with length equal to the value described by st[i][j])

}