#include <bits/stdc++.h>
using namespace std;
string ones[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
string tens[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); string in; cin >> in;
    for(int i = 1; i < 100; i++)
    {
        int a = i/10, b = i%10; string s = in, t = tens[a] + ones[b], ans = t;
        sort(s.begin(), s.end()); sort(t.begin(), t.end());
        if(s == t) { cout << ans; break; }
    }
}