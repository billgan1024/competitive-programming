#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e5;

int n; string s; char op[5] = {'+', '-', '*', '/', '%'}; stack<int> terms;
bool isOperator(char c) { return find(op, op+5, c) != end(op); }
int operate(int a, int b, char c)
{
    int ret;
    switch(c)
    {
        case '+': ret = a+b; break;
        case '-': ret = a-b; break;
        case '*': ret = a*b; break;
        case '/': ret = a/b; break;
        case '%': ret = a%b; break;
    }
    return ret;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t = 0; t < 5; t++)
    {
        scln(s);
        //stack tracks numbers
        if(isOperator(s[0]))
        {
            //right to left for prefix notation
            for(int i = sz(s)-1; i >= 0; i--)
            {
                if(s[i] != ' ')
                {
                    if(isOperator(s[i]))
                    {
                        int a = terms.top(); terms.pop();
                        int b = terms.top(); terms.pop();
                        terms.push(operate(a, b, s[i]));
                    }
                    else terms.push(s[i]-'0');
                }
            }
        }
        else
        {
            //left to right for suffix notation
            for(int i = 0; i < sz(s); i++)
            {
                if(s[i] != ' ')
                {
                    if(isOperator(s[i]))
                    {
                        int b = terms.top(); terms.pop();
                        int a = terms.top(); terms.pop();
                        terms.push(operate(a, b, s[i]));
                    }
                    else terms.push(s[i]-'0');
                }
            }
        }
        pr(terms.top(), nl); terms.pop();
    }
}