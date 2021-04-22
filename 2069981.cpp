#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n; vector<int> cards, order;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++)
    {
        scan(n); cards.clear(); order.clear();
        for(int i = 1; i <= n; i++) cards.pb(i); bool v = true;
        for(int i = 0, x; i < n; i++)
        {
            scan(x); int pos = n-i-x-1;
            if(pos < 0) { v = false; break; }
            order.pb(cards[pos]); cards.erase(cards.begin()+pos);
        }
        if(v) { for(int i : order) print(i, sp); }
        else print("IMPOSSIBLE"); print(nl);
    }
}