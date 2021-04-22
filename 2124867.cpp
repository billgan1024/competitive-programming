#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int T, s, f;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(T);
    for(int t = 0; t < T; t++)
    {
        scan(s, f); int ans = 0;
        int a1 = s + (s % 2 == 0), a2 = f - (f % 2 == 0), c = (a2-a1)/2 + 1;
        ans |= c%2;
        for(int i = 1; i < 30; i++)
        {
            int ms = s % (1 << (i+1)), mf = f % (1 << (i+1));
            //s1 = how many 1s are before s in the block (not including position s)
            //s2 = how many 1s are after s in the block (including position s)
            int s2 = min(1 << i, (1 << (i+1)) - ms), f1 = max(0, mf - (1 << i));
            c = s2 + f1 + (mf >= (1 << i));
            ans |= (c%2) << i;
        }
        print(ans, nl);
    }
}