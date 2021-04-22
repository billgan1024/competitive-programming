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
const int MV = 1e5;

int n, cur[MV], nxt[MV], len[MV]; unordered_set<int> bruh[26]; string s; vector<char> ans; vector<int> pos[MV][26];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 0; i < n; i++)
    {
        sc(s); len[i] = sz(s); for(int j = 0; j < sz(s); j++) { pos[i][s[j]-'a'].pb(j); bruh[s[j]-'a'].insert(i); }
    }
    //scan from character 'z' to 'a', checking if every string has that character
    //then keep going, appending characters to the answer and updating cur (cur moves to the right because
    //subsequences need to maintain order)
    bool flag = true;
    for(int c = 25; c >= 0; c--)
    {
        if(sz(bruh[c]) != n) continue;
        int cnt = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            //nxt[i] = nxt index with element >= cur[i]
            //cur[i] = actual position you want to look for (you are searching an array of positions
            //using a position, and it returns an index)
            nxt[i] = lower_bound(pos[i][c].begin(), pos[i][c].end(), cur[i]) - pos[i][c].begin();
            cnt = min(cnt, sz(pos[i][c])-nxt[i]);
        }
        //cnt = max # of characters c that are in the lexicographically greatest string
        //then update cur only if necessary
        for(int i = 0; i < cnt; i++) ans.pb((char)(c+'a'));
        for(int i = 0; i < n; i++)
        for(int i = 0; i < n; i++)
        {
            if(cnt > 0 && nxt[i]+cnt-1 < sz(pos[i][c])) cur[i] = pos[i][c][nxt[i]+cnt-1]+1;
            if(cur[i] == len[i]) { flag = false; break; }
        }
        if(!flag) break;
    }
    if(ans.empty()) pr(-1);
    else { for(char ch : ans) pr(ch); }
    pr(nl);
}