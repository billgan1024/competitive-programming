#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
//string hash example
//keep characters by their numerical value
//this is similar to a prefix sum array (compute hashes of substrings in constant time)
//just check whether two hashes are equal when comparing two strings
//(check whether two strings are equal) in constant time
string s1, s2; ull hash1[1000001], hash2[1000001], p[1000001]; int base = 131, ans;
ull getHash(int l, int r, int s)
{
    if(s == 1) return hash1[r] - hash1[l-1]*p[r-l+1];
    else if(s == 2) return hash2[r] - hash2[l-1]*p[r-l+1];
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cin >> s1 >> s2; p[0] = 1;
    //one-indexed hashing
    for(int i = 1; i <= s1.size(); i++)
    {
        hash1[i] = hash1[i-1]*base + s1[i-1]; p[i] = p[i-1]*base;
    }
    for(int i = 1; i <= s2.size(); i++)
    {
        hash2[i] = hash2[i-1]*base + s2[i-1];
    }
    for(int i = 1; i <= min(s1.size(), s2.size()); i++)
    {
        ull h1 = getHash(s1.size()-i+1, s1.size(), 1), h2 = getHash(1, i, 2);
        if(h1 == h2) ans = i;
    }
    cout << s1.substr(0, s1.size()-ans) << s2;
}