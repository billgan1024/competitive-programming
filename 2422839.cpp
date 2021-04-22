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

int trueIdx = -1, falseIdx = -1, c;
int main()
{
    //-1 = doesn't exist
    cin.sync_with_stdio(0); cin.tie(0); sc(c);
    for(int i = 0; i < c; i++)
    {
        int cmd; string s; sc(cmd);
        if(cmd == 1)
        {
            sc(s); bool b = s == "true";
            if(b)
            {
                if(trueIdx != -1) pr("false", nl);
                else
                {
                    if(falseIdx == -1) trueIdx = 0;
                    else trueIdx = 1;
                    pr("true", nl);
                }
            }
            else
            {
                if(falseIdx != -1) pr("false", nl);
                else
                {
                    if(trueIdx == -1) falseIdx = 0;
                    else falseIdx = 1;
                    pr("true", nl);
                }
            }
        }
        else if(cmd == 2)
        {
            sc(s); bool b = s == "true";
            if(b)
            {
                if(trueIdx == -1) pr("false", nl);
                else
                {
                    trueIdx = -1; if(falseIdx == 1) falseIdx = 0;
                    pr("true", nl);
                }
            }
            else
            {
                if(falseIdx == -1) pr("false", nl);
                else
                {
                    falseIdx = -1; if(trueIdx == 1) trueIdx = 0;
                    pr("true", nl);
                }
            }
        }
        else if(cmd == 3)
        {
            sc(s); bool b = s == "true";
            if(b) pr(trueIdx, nl); else pr(falseIdx, nl);
        }
        else
        {
            if(falseIdx != -1) pr("false", sp);
            if(trueIdx != -1) pr("true", sp);
            pr(nl);
        }
    }
}