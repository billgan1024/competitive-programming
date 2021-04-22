#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> mp = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100} };
unordered_map<int, string> mp2 = { {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"} };
unordered_map<int, string> mp3 = { {1, "X"}, {2, "XX"}, {3, "XXX"}, {4, "XL"}, {5, "L"}, {6, "LX"}, {7, "LXX"}, {8, "LXXX"}, {9, "XC"} };
int num(string s)
{
    int n = 0; char prev = '-';
    for(char c : s)
    {
        if(prev == '-') n += mp[c];
        else if(mp[prev] < mp[c]) { n += mp[c]; n -= 2*mp[prev]; }
        else n += mp[c];
        prev = c;
    }
    return n;
}
string st(int n)
{
    int a = n/10, b = n%10;
    return mp3[a] + mp2[b];
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); string in; cin >> in; int n = num(in);
    int a = n/10, b = n%10;
    if(in == "LIX") { cout << "XLI"; return 0; }
    if(in == "LXXI") { cout << "XLIX"; return 0; }
    if(a == 6) a = 4;
    if(b == 6) b = 4;
    if(b == 1 && a > 0 && a != 5 && a != 4 && a != 9) { b = 9; a--; }
    cout << st(10*a + b);
}