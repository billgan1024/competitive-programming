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

int n, ac, wa, tle, ir; string arr[1000];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 0; i < n; i++)
    {
        string s; sc(s); arr[i] = s;
        if(s == "AC") ac++;
        else if(s == "WA") wa++;
        else if(s == "TLE") tle++;
        else ir++;
    }
    wa = (int)(0.3*wa);
    int w = 0, i = 0;
    for(int t = 0; t < n; t++)
    {
        string s = arr[t];
        if(s == "AC") pr("AC", nl);
        else if(s == "WA")
        {
            if(w < wa) pr("AC", nl); else pr("WA", nl);
            w++;
        }
        else if(s == "TLE") pr("WA", nl);
        else
        {
            if(i < 10) pr("AC", nl);
            else if(i < 20) pr("WA", nl);
            else pr("IR", nl);
            i++;
        }
    }
}