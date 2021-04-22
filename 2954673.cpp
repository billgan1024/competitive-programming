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

string s; int n; bool isVowel[100], L = false; char vowel[5] = {'A', 'E', 'I', 'O', 'U'};
ll ans, p[11], q[11], r[11];
bool v(char c) { return find(vowel, vowel+5, c) != vowel+5; }
int main()
{
    //there is probably at least one underscore(?)
    cin.sync_with_stdio(0); cin.tie(0); sc(s); p[0] = q[0] = r[0] = 1;
    for(int i = 1; i <= 10; i++) { p[i] = 5*p[i-1]; q[i] = 21*q[i-1]; r[i] = 20*r[i-1]; }
    for(int i = 0; i < sz(s); i++)
    {
        isVowel[i] = v(s[i]); L |= s[i] == 'L'; n += s[i] == '_';
    }
    for(int i = 0; i < (1 << n); i++)
    {
        int cur = 0, vc = 0, cc = 0; bool valid = true;
        for(int j = 0; j < sz(s); j++)
        {
            if(s[j] == '_')
            {
                isVowel[j] = i & (1 << cur);
                if(isVowel[j]) vc++; else cc++;
                cur++;
            }
            if(j >= 2 && isVowel[j] == isVowel[j-1] && isVowel[j] == isVowel[j-2]) { valid = false; break; }
        }
        if(valid)
        {
            ans += p[vc] * q[cc];
            if(!L) ans -= p[vc] * r[cc];
        }
    }
    pr(ans);
}