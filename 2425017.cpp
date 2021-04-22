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

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    while(true)
    {
        string s; scln(s); if(s == "0") return 0; stack<string> ans;
        for(int i = sz(s)-1; i >= 0; i--)
        {
            char c = s[i]; if(c == ' ') continue;
            if(c == '-' || c == '+')
            {
                string a = ans.top(); ans.pop();
                string b = ans.top(); ans.pop();
                string next = a+b+c;
                ans.push(next);
            }
            else
            {
                string t(1, c);
                ans.push(t);
            }
        }
        string t = ans.top();
        for(char c : t) pr(c, sp); pr(nl);
    }
}