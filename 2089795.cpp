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

int k; string s;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(k, s);
    for(int i = 0; i < sz(s); i++)
    {
        int idx = s[i] - 'A';
        for(int j = 0; j < 26; j++)
        {
            if((j + 3*(i+1) + k) % 26 == idx) { print((char)(j+'A')); break; }
        }
    }
}