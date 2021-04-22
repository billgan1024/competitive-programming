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
typedef unsigned long long ll;
typedef pair<int, int> pii;
const int MV = 1e6+1;
const ll seed = 131;

//lls will never be more than k characters long
string s; int k, ans; ll h[MV], p[MV];
ll hsh(int l, int r) { return h[r]-h[l-1]*p[r-l+1]; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); sc(s, k); p[0] = 1;
    for(int i = 1; i <= sz(s); i++)
    {
        h[i] = h[i-1]*seed + s[i-1]; p[i] = p[i-1]*seed;
    }
    //use a rolling hash and compare adjacent substrings to return the least one (n*logk)
    ans = 1;
    for(int i = 2; i+k-1 <= sz(s); i++)
    {
        //hashes are s[ans...ans+k-1] and s[i...i+k-1] (1-indexed)
        int low = 0, high = k-1, idx = 0;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(hsh(ans, ans+mid) == hsh(i, i+mid)) low = mid+1;
            else
            {
                idx = mid; high = mid-1;
            }
        }
        //after binary search terminates, idx = first character mismatch between ans and i
        if(s[i+idx-1] < s[ans+idx-1]) ans = i;
    }
    pr(s.substr(ans-1, k));
}