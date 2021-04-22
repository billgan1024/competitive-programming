#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e6+1;

string s; int q, freq[MV][26];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scln(s); scan(q);
    for(int i = 1; i <= sz(s); i++)
    {
        for(int j = 0; j < 26; j++) freq[i][j] = freq[i-1][j];
        if(s[i-1] != ' ') freq[i][s[i-1]-'a']++;
    }
    for(int i = 0; i < q; i++)
    {
        int l, r; char c; scan(l, r, c);
        print(freq[r][c-'a']-freq[l-1][c-'a'], nl);
    }
}