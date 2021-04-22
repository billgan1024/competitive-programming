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
const int MV = 4e5;

int n; stack<ll> s; stack<int> f; ll a[MV], ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    //nonincreasing stack tracks all people who can currently see to their right
    //update the stack by checking for each position i, all people that person i can see to their left
    for(int i = 0; i < n; i++)
    {
        sc(a[i]); int cnt = 1;
        while(!s.empty())
        {
            if(s.top() < a[i])
            {
                ans += f.top(); s.pop(); f.pop();
            }
            else if(s.top() == a[i])
            {
                ans += f.top(); cnt = f.top()+1; s.pop(); f.pop();
            }
            else
            {
                ans++; break;
            }
        }
        s.push(a[i]); f.push(cnt);
    }
    pr(ans);
}