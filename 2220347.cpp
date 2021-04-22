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
const int MV = 1e3+1;

int r, s, p[MV][MV], a[MV][MV], c[MV][MV], ans; stack<int> st;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(r, s);
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= s; j++)
        {
            sc(p[i][j]); a[i][j] = p[i][j] - p[i-1][j] - p[i][j-1] + p[i-1][j-1];
        }
    }
    //find the largest rectangle that only contains integers <= 0
    //note that you are maximizing (l+1)*(w+1) because of the prefix sum array
    for(int j = 2; j <= s; j++)
    {
        for(int i = 2; i <= r; i++) c[i][j] = a[i][j] <= 0 ? c[i-1][j] + 1 : 0;
    }
    for(int i = 2; i <= r; i++)
    {
        for(int j = 2; j <= s; j++)
        {
            while(!st.empty() && c[i][j] < c[i][st.top()])
            {
                int h = c[i][st.top()] + 1; st.pop();
                if(!st.empty()) ans = max(ans, (j - st.top()) * h);
                else ans = max(ans, (j - 1) * h);
            }
            st.push(j);
        }
        while(!st.empty())
        {
            int h = c[i][st.top()] + 1; st.pop();
            if(!st.empty()) ans = max(ans, (s - st.top() + 1) * h);
            else ans = max(ans, s * h);
        }
    }
    pr(ans);
}