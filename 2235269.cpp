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
const int MV = 1e5+1;

int n, k, r, a[MV], rit, ans; stack<int> s;
int main()
{
    //stack tracks empty spots
    cin.sync_with_stdio(0); cin.tie(0); sc(n, k, r);
    for(int i = 0, x; i < k; i++) { sc(x); a[x] = 1; }
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += a[i]; if(!a[i]) s.push(i);
        if(i >= r)
        {
            sum -= a[i-r];
            while(sum < 2)
            {
                a[s.top()] = 1; s.pop(); sum++; ans++;
            }
        }
    }
    pr(ans, nl);
}