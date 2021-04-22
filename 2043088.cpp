#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, ans, maxDis = INT_MIN; string s; vector<int> dis;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, s); s += "1"; int p = -1;
    for(int i = 0; i <= n; i++)
    {
        if(s[i] == '1') { dis.pb(i-p); p = i; }
    }
    if(sz(dis) == 1) { print(n-1); return 0; }
    int start = dis[0], finish = dis[sz(dis)-1]; dis.erase(dis.begin()); dis.erase(dis.end()-1);
    sort(dis.begin(), dis.end());
    ans = dis[0]; maxDis = max((start-1)/2, (finish-1)/2);
    maxDis = max(maxDis, min(start-1, finish-1));
    if(sz(dis) >= 1) {
        maxDis = max(maxDis, dis[sz(dis)-1]/3);
        int m = max(start-1, finish-1);
        maxDis = max(maxDis, min(m, dis[sz(dis)-1]/2));
    }
    if(sz(dis) >= 2) maxDis = max(maxDis, min(dis[sz(dis)-1]/2, dis[sz(dis)-2]/2));
    ans = min(ans, maxDis);
    print(ans, nl);
}