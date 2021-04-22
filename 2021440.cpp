#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define f first
#define s second
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e5+1;

int n, m, ans, used[MV]; pii cows[MV]; queue<int> c[MV];
void process(int cereal, int cur)
{
    if(used[cur] == 0)
    {
        used[cur] = cereal; ans++;
    }
    else
    {
        if(used[cur] == cows[cur].f && !c[cereal].empty())
        {
            c[cereal].pop();
            if(!c[cereal].empty()) process(cereal, c[cereal].front());
        }
        else if(!c[cows[cur].s].empty())
        {
            c[cows[cur].s].pop(); used[cur] = cows[cur].f;
            if(!c[cows[cur].s].empty()) process(cows[cur].s, c[cows[cur].s].front());
        }
    }
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    for(int i = 1; i <= n; i++)
    {
        //if cow i can get the first preferred cereal, they will never get the second cereal
        //if cow i is blocked by a previous cow, then queue up this cow for cereals f and s;
        //take cereal s if it can
        scan(cows[i].f, cows[i].s); 
        if(c[cows[i].f].empty()) { used[i] = cows[i].f; c[cows[i].f].push(i); ans++; }
        else if(c[cows[i].s].empty()) { used[i] = cows[i].s; c[cows[i].f].push(i); c[cows[i].s].push(i); ans++; }
        else { c[cows[i].f].push(i); c[cows[i].s].push(i); }
    }
    for(int i = 1; i <= n; i++)
    {
        print(ans, nl);
        //used[i] represents the cereal taken by cow i
        //remove cow i's cereal selection if they selected anything and update
        //the remaining cows' cereal selections by removing cows from queues
        if(used[i] != 0 && !c[used[i]].empty())
        {
            c[used[i]].pop(); ans--;
            if(!c[used[i]].empty())
            {
                process(used[i], c[used[i]].front());
            }
            used[i] = 0;
        }
    }
}