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

int n, l; string s;
int f(int i) { return (i+l)%26; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, l); cin.ignore(); scln(s);
    for(char c : s)
    {
        if(c != ' ')
        {
            int x = f(c-'a');
            print((char)(x+'a'));
        }
        else print(sp);
    }
}