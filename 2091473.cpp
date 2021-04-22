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

string s, t; unordered_set<string> c;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(t, s);
    c.insert(s);
    for(int i = 1; i < sz(s); i++)
    {
        char ch = s[0]; s.erase(0, 1); s += ch; c.insert(s);
    }
    for(int i = 0; i+sz(s) <= sz(t); i++)
    {
        if(c.find(t.substr(i, sz(s))) != c.end()) { print("yes"); return 0; }
    }
    print("no");
}