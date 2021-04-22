#include <bits/stdc++.h>
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
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n; vector<double> streams;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n); streams.pb(0);
    for(int i = 0, x; i < n; i++)
    {
        scan(x); streams.pb(x);
    }
    while(true)
    {
        int cmd, x; double p;
        scan(cmd); if(cmd == 77) break;
        if(cmd == 99)
        {
            scan(x, p); double l = streams[x]*p/100, r = streams[x]-l;
            streams[x] = r; streams.insert(streams.begin()+x, l);
        }
        else if(cmd == 88)
        {
            scan(x); double sum = streams[x]+streams[x+1];
            streams.erase(streams.begin()+x); streams[x] = sum;
        }
    }
    for(int i = 1; i < sz(streams); i++) print((int)round(streams[i]), sp);
}