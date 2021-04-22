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
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, st; unordered_map<int, int> dis; unordered_map<int, bool> vis; queue<int> q;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, x; i < n; i++) { scan(x); st += x << i; }
    vis[st] = true; dis[st] = 0; q.push(st);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int i = 0; i < n; i++)
        {
            if(!(cur & (1 << i)))
            {
                int nxt = cur | (1 << i), cnt = 0;
                for(int j = 0; j < n; j++)
                {
                    if(nxt & (1 << j)) cnt++;
                    else
                    {
                        if(cnt >= 4)
                        {
                            //set this current block to zero
                            int mask = ((1 << cnt) - 1) << (j-cnt); nxt ^= mask;
                        }
                        cnt = 0;
                    }
                }
                if(cnt >= 4)
                {
                    int mask = ((1 << cnt) - 1) << (n-cnt); nxt ^= mask;
                }
                if(vis[nxt]) continue;
                vis[nxt] = true; dis[nxt] = dis[cur] + 1; q.push(nxt);
                if(!nxt) { print(dis[nxt]); return 0; }
            }
        }
        dis.erase(cur);
    }
}