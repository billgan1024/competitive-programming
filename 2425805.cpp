#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define fl() cout << flush
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 2e5+1;

int n, m, k, t[5], a[5], s[MV]; double inc[5];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n, m, k);
    for(int i = 0; i < k; i++) sc(t[i], a[i]);
    for(int i = 0, st, len, x; i < m; i++)
    {
        sc(st, len, x); s[st] += x; s[st+len] -= x;
    }
    double hp = n;
    for(int i = 1; i < MV; i++) s[i] += s[i-1];
    for(int i = 0; i < MV; i++)
    {
        double dmg = s[i];
        for(int j = 0; j < 5; j++) dmg = min(dmg, max(s[i]-t[j], 0)*(100-a[j])/100.0);
        hp -= dmg;
    }

    if(hp <= 0) pr("Act Like A Cactus.");
    else printf("%.2f", hp);
}