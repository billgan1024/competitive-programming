#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

pii pos[15]; int cnt, ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(cnt != 15) pos[cnt++] = {i, j};
        }
    }
    string s;
    for(int i = 0; i < 4; i++)
    {
        scan(s);
        for(int j = 0; j < 4; j++)
        {
            if(s[j] != '.')
            {
                int c = s[j] - 'A'; ans += abs(i-pos[c].first) + abs(j-pos[c].second);
            }
        }
    }
    print(ans);
}