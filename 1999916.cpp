#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(a) sizeof(a)/sizeof(a[0])
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MV = 1e6+1;

//store the possible plane values landing at each gate, then scan from highest gate to lowest gate because higher gate planes
//can land at lower gates
vector<int> planes[MV]; int g, p, ans; priority_queue<int> pq;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(g, p);
    //for(int i = 1; i <= g; i++) remaining.insert(i);
    for(int i = 1, g0, v0; i <= p; i++)
    {
        scan(g0, v0); planes[g0].push_back(v0);
    }
    for(int i = g; i > 0; i--)
    {
        for(int v : planes[i]) pq.push(v);
        if(!pq.empty()) { ans += pq.top(); pq.pop(); }
    }
    print(ans);
}