#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define x first
#define y second
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e5;

int n, ans = 1, low[MV], high[MV]; vector<pii> p;

bool cmp(pii a, pii b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, xi, yi; i < n; i++)
    {
        scan(xi, yi); p.pb({xi, yi});
    }
    sort(p.begin(), p.end(), cmp);
    //across the array, components move progressively towards the right
    //low stores the lowest y-value of the nodes from left to right, bottom to top
    //high stores the highest y-value of the nodes from left to right, bottom to top
    low[0] = p[0].y; for(int i = 1; i < n; i++) low[i] = min(low[i-1], p[i].y);
    high[n-1] = p[n-1].y; for(int i = n-2; i >= 0; i--) high[i] = max(high[i+1], p[i].y);
    //basically, node i is always connected to the node with the min y level on the left, and node i+1
    //is always connected to the node with the max y level on its right
    //the min node and the max node are already sorted in the x, so if they are sorted in the y,
    //node i and i+1 lie in the same connected component
    //otherwise they lie in diff components (ans++, counts components)
    for(int i = 0; i < n-1; i++)
    {
        if(low[i] > high[i+1]) ans++;
    }
    print(ans, nl);
}