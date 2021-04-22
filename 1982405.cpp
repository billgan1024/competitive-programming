#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 1e5;

bool cmp(pii x, pii y) { return x.first-x.second > y.first-y.second; }
int n, p, ans, cnt = 1; vector<pii> planets; priority_queue<pii, vector<pii>, greater<pii>> pq;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, p); p--;
    for(int i = 0, a, b; i < n; i++)
    {
        scan(a, b); planets.push_back({a, b});
    }
    ans = planets[p].first; planets.erase(planets.begin()+p);
    sort(planets.begin(), planets.end(), cmp);
    for(int i = 0; i < sz(planets); i++)
    {
        //pq sorts pending planets by least fuel required
        int gain = planets[i].first-planets[i].second;
        if(gain >= 0)
        {
            if(ans >= planets[i].second)
            {
                ans += gain; cnt++;
                while(!pq.empty())
                {
                    int req = pq.top().first, id = pq.top().second;
                    if(ans >= req)
                    {
                        ans += planets[id].first-req;
                        cnt++; pq.pop();
                    }
                    else break;
                }
            }
            else pq.push({planets[i].second, i});
        }
    }
    print(ans, nl, cnt, nl);
}