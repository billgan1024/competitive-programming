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
#define popcnt __builtin_popcount
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<ll, int> pii;
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

//the expected value in a range is simply the sum of probabilities which fall in the range,
//regardless of whether they depend on the same event
//to calculate the aggregate chance, note that the expression can be derived from (p1-1)(p2-1)...(pk-1)
//where pi are the probabilities which lie in the range
//to account for dependent probabilities of the same event, note that if one key lies in the range,
//simply account for that using pi-1; but if both lie in the range, the probability that this event contributed
//one key needs to be p1+p2-1 (chance is p1+p2 now)
//to do this, use two BITs for storing the standard pucts of individual probabilities (p1-1)(p2-1)...(pk-1)
//and storing pair expressions which are (p1+p2-1)/((p1-1)(p2-1))
//you can thus query a range puct; one for the individual probabilities and one for ranges that lie
//completely in the query
//account for zero division by processing zeroes separately
//time complexity: QlogX where X is the max amount of keys pressed
const int maxN = 5e4;
//bit[i][0]: tracks sum (for EV)
//bit[i][1]: tracks left (p1+p2-1)/((p1-1)(p2-1))
//bit[i][2]: tracks right (p1+p2-1)/((p1-1)(p2-1))
//bit[i][3]: tracks product of pi-1
//bit[i][4]: tracks # of zeroes in the product (pi-1)
//bit[i][5]: tracks # of zeroes in the left (p1+p2-1)/((p1-1)(p2-1))
//bit[i][6]: tracks # of zeroes in the right (p1+p2-1)/((p1-1)(p2-1))
ll n; int q, m; set<ll> cmp; ll idx[2*maxN+1]; double bit[2*maxN+1][7];

ordered_set<pii, null_type> lft, rit, tot; hash_map<ll, int> lftID, ritID, totID;
struct event {
    char cmd; int m; ll l, r; double x, y;
} ev[maxN];
void upd(int id, double v, int b) {
    for(int i = id; i <= m; i += i&-i) bit[i][b] += v;
}
void upd2(int id, double v, int b) {
    for(int i = id; i <= m; i += i&-i) bit[i][b] *= v;
}
double query(int id, int b) {
    double ret = 0;
    for(int i = id; i > 0; i -= i&-i) ret += bit[i][b];
    return ret;
}
double query2(int id, int b) {
    double ret = 1;
    for(int i = id; i > 0; i -= i&-i) ret *= bit[i][b];
    return ret;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(n, q);
    for(int i = 1; i <= 2*maxN; i++) { bit[i][1] = bit[i][2] = bit[i][3] = 1; }
    //process queries offline to use index compression when building the binary indexed trees
    for(int i = 0; i < q; i++) {
        sc(ev[i].cmd);
        if(ev[i].cmd == 'P') {
            sc(ev[i].m);
            sc(ev[i].l); if(ev[i].m == 2) sc(ev[i].r); else ev[i].r = ev[i].l;
            sc(ev[i].x); ev[i].x /= 100; if(ev[i].m == 2) { sc(ev[i].y); ev[i].y /= 100; }
            //add the points to the set to compress the indices
            cmp.insert(ev[i].l); cmp.insert(ev[i].r);
        } else if(ev[i].cmd == 'E' || ev[i].cmd == 'W') sc(ev[i].l, ev[i].r);
        else if(ev[i].cmd == 'C') { sc(ev[i].l); ev[i].r = ev[i].l; }
    }
    for(ll i : cmp) { idx[++m] = i; }
    //idx stores the compressed array of points, c is used for ez access to indices
    for(int i = 0; i < q; i++) {
        event e = ev[i];
        if(e.cmd == 'P') {
            int l = lower_bound(idx+1, idx+m+1, e.l)-idx;
            int r = lower_bound(idx+1, idx+m+1, e.r)-idx;
            //note: if there's only one key pressed, the other endpoint is equal to the original endpoint
            //and the probability is zero so we treat single key pressed as 2 key pressed
            upd(l, e.x, 0); upd(r, e.y, 0);

            //consider zeroes separately by maintaining a bit tracking # of zero factors in any prefix
            double x = 1, zero = 0;
            if(1-(e.x+e.y) == 0) zero; else x *= 1-(e.x+e.y);
            if(1-e.x == 0) zero--; else x /= 1-e.x;
            if(1-e.y == 0) zero--; else x /= 1-e.y;
            x = sqrt(x); zero /= 2;
            upd2(l, x, 1); upd2(r, x, 2);
            upd(l, zero, 5); upd(r, zero, 6);

            if(1-e.x == 0) upd(l, 1, 4); else upd2(l, 1-e.x, 3);
            if(1-e.y == 0) upd(r, 1, 4); else upd2(r, 1-e.y, 3);

        } else if(e.cmd == 'E') {
            int l = lower_bound(idx+1, idx+m+1, e.l)-idx-1, r = upper_bound(idx+1, idx+m+1, e.r)-idx-1;
            //query sum for the range [e.l, e.r]
            double sum = 0;
            if(r != 0) sum += query(r, 0); if(l != 0) sum -= query(l, 0);
            pr(sum, nl);
        } else {
            int l = lower_bound(idx+1, idx+m+1, e.l)-idx-1, r = upper_bound(idx+1, idx+m+1, e.r)-idx-1;
            pr(l, sp, r, nl);
            //query aggregate chance for the range [e.l, e.r]
            double p = 1; int zero = 0;
            //2 = (p1+p2-1)/((p1-1)(p2-1)), 3 = product of pi-1
            //p = (p1-1)(p2-1)...(pn-1), q = (p1+p2-1)(p3+p4-1)... / ((p1-1)(p2-1)(p3-1)...)
            //account for zeroes
            if(r != 0) {
                p *= query2(r, 3); zero += query(r, 4);
                p *= query2(r, 2); zero += query(r, 6);
            }
            if(l != 0) {
                p /= query2(l, 3); zero -= query(l, 4);
                p /= query2(l, 1); zero -= query(l, 5);
            }
            if(zero > 0) p = 0; //(there won't be more zeroes in the denominator since (p1+p2-1)/(...) always cancels pi-1 in the numerator
            pr(1-p, nl);
        }
    }
}