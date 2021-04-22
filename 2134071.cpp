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

int m, ans[101], rep[101], s[101];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(m);
    char cmd;
    int n, t = 0;
    for(int i = 0; i < m; i++)
    {
        scan(cmd, n);
        if(cmd == 'S') { ans[n] += t - s[n]; rep[n] = 1; }
        else if(cmd == 'R') { rep[n] = -1; s[n] = t; }
        else t += n-2;
        t++;
    }
    for(int j = 0; j <= 100; j++)
    {
        if(rep[j] != 0)
        {
            if(rep[j] > 0) print(j, sp, ans[j], nl);
            else print(j, sp, rep[j], nl);
        }
    }
}