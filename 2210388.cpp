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
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int K, n, m, r[1001][1001], len[1001]; char g[1001][1001]; deque<int> q;

void update(int i, int j)
{
    while(!q.empty() && r[i][j] < r[q.back()][j])
    {
        len[q.back()] += abs(i-q.back()); q.pop_back();
    }
    q.pb(i);
}

void finishUpdate(bool fromEnd)
{
    while(!q.empty())
    {
        if(fromEnd) len[q.back()] += n+1-q.back(); else len[q.back()] += q.back();
        q.pop_back();
    }
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(K);
    for(int k = 0; k < K; k++)
    {
        sc(n, m); int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                sc(g[i][j]); r[i][j] = g[i][j] == 'F' ? r[i][j-1] + 1 : 0;
            }
        }
        for(int j = 1; j <= m; j++)
        {
            ms(len, 0);

            for(int i = 1; i <= n; i++) update(i, j);
            finishUpdate(true);

            for(int i = n; i > 0; i--) update(i, j);
            finishUpdate(false);

            for(int i = 1; i <= n; i++) ans = max(ans, r[i][j]*(len[i]-1));
        }
        pr(3*ans, nl);
    }
}