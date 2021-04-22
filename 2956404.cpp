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
const int MV = 1e6;

string msg, s, k = "HAILHYDRA"; int idx[7] = {0, 1, 2, 3, 5, 6, 7}, n, ans = 1e5; char f[MV][26];
unordered_set<char> cnt; bool found = false;
bool valid(int i, int j)
{
    bool ret = true;
    for(int x : idx)
    {
        ret &= f[j][msg[i+x]-'A'] == k[x];
    }
    return ret;
}
int main()
{
    //f[i] = inverse function of the encryptor function (i.e. decryptor function)
    //take advantage of the fact that the string is randomly generated
    //i.e. there will not be many substrings where 'hailhydra' can potentially appear
    cin.sync_with_stdio(0); cin.tie(0); sc(msg, n);
    for(int i = 0; i < n; i++)
    {
        sc(s); for(int j = 0; j < 26; j++) f[i][s[j]-'A'] = (char)(j+'A');
    }
    for(int i = 0; i+8 < sz(msg); i++)
    {
        //check if hailhydra can lie here (can optimize here later)
        cnt.clear(); for(int j : idx) cnt.insert(msg[i+j]);
        if(sz(cnt) == 7 && msg[i] == msg[i+4] && msg[i+1] == msg[i+8])
        {
            for(int j = 0; j < n; j++)
            {
                if(valid(i, j)) { ans = j; found = true; break; }
            }
        }
        if(found) break;
    }
    if(ans == 1e5) pr("KeyNotFoundError");
    else
    {
        for(char c : msg) pr(f[ans][c-'A']);
    }
}