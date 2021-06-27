#include <bits/stdc++.h>
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
//note that there are lots of items, but only 50 possible costs. this means that there are many items which cost the exact same,
//yet an item will have more value. this means that in any optimal solution, you would take that first before taking the one w/ less value
//generalizing, for all items of a particular cost, the optimal solution consists of taking a suffix of these items,
//when you sort them in increasing order of value
//furthermore, the suffix length you actually choose for any particular cost will be at most 50, since your knapsack capacity <= 50
//in any case, it suffices to do knapsack considering up to 50x50 items (i.e. the top 50 items by value for each cost)
//for every query, we find up to O(n) elements w/ log(n) extra time for sets and do knapsack, which costs O(50^3)
//thus, the upper bound on the # of operations is 3000(nlogn + 50^3) which is too slow
//to speed this up, we can use a data structure for the range queries and point updates
//in this case, maintain a segment tree to track f[l, r] = array of length 50 such that a[i] is a set representing up to the top 
//w/i values for all items of cost i in the range.
//total number of operations is about 3000(30000 + 50(1000 + 50^2)) since for every cost, the pointer cur moves 1000 times,
//and you do knapsack on the top 50 items which loops up to 50 times. Somehow this passes lmao
const int maxN = 3e4+1; 

int w, n, d, dp[51], f[51][1001], c[maxN], v[maxN];
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(w, n, d);
    //cout.setf(ios::unitbuf);
    for(int i = 1; i <= n; i++) sc(c[i], v[i]); 
    for(int t = 1, a, b, x, y; t <= d; t++) {
        sc(a, b, x, y); c[a] = b; ms(f, 0); ms(dp, 0);
        for(int i = x; i <= y; i++) f[c[i]][v[i]]++;
        for(int i = 1; i <= 50; i++) {
            int cur = 1000;
            for(int j = 0; j < 50; j++) {
                while(!f[i][cur] && cur >= 0) cur--; 
                if(cur == 0) break;
                //use (i, cur) as the object with cost i and value cur 
                for(int k = w; k >= i; k--) dp[k] = max(dp[k], cur+dp[k-i]);
                f[i][cur]--;
            } 
        }
        //find all the top items for each cost and do knapsack
        //do knapsack with O(w) memory
        pr(dp[w], nl);
    }
}