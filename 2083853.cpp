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

int N; string a, b; stack<int> ans;
int num(char c) { return c - '0'; }
int ch(int i) { return (char)(i+'0'); }
void take(int i)
{
    int v = num(a[i]);
    v--; if(v < 0) { v += 10; take(i-1); }
    a[i] = ch(v);
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(N);
    for(int n = 0; n < N; n++)
    {
        scan(a, b);
        bool an = a[0] == '-', bn = b[0] == '-', shouldswap = false, flip = false;
        if(sz(a)-an < sz(b)-bn) shouldswap = true;
        else if(sz(a)-an == sz(b)-bn)
        {
            int i = an, j = bn;
            while(i < sz(a))
            {
                if(num(a[i]) > num(b[j])) break;
                else if(num(a[i]) < num(b[j])) { shouldswap = true; break; }
                i++; j++;
            }
        }
        if(shouldswap) { swap(a, b); swap(an, bn); }
        if(an ^ bn)
        {
            flip = an;
            int i = sz(a)-1, j = sz(b)-1;
            while(i >= an)
            {
                int digit = num(a[i]); if(j >= bn) digit -= num(b[j]);
                if(digit < 0)
                {
                    digit += 10; take(i-1);
                }
                ans.push(digit); i--; j--;
            }
        }
        else
        {
            flip = an && bn;
            int i = sz(a)-1, j = sz(b)-1; bool regroup = false;
            while(i >= an)
            {
                int digit = regroup; regroup = false;
                digit += num(a[i]); if(j >= bn) digit += num(b[j]);
                if(digit >= 10) { digit -= 10; regroup = true; }
                ans.push(digit); i--; j--;
            }
            if(regroup) ans.push(1);
        }
        while(!ans.empty() && ans.top() == 0) ans.pop();
        if(ans.empty()) print(0);
        else
        {
            if(flip) print('-');
            while(!ans.empty()) { print(ans.top()); ans.pop(); }
        }
        print(nl);
    }
}