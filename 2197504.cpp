#include <bits/stdc++.h>
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
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 5e5;

int n, a[MV], b[MV], s[652][652];
int sum(int r1, int c1, int r2, int c2) { return s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1]; }
int main()
{
    //scores are in the range [1, 651]
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        scan(a[i], b[i]); a[i]++; b[i]++; s[a[i]][b[i]]++;
    }
    for(int i = 1; i <= 651; i++)
    {
        for(int j = 1; j <= 651; j++) s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    }
    for(int i = 0; i < n; i++)
    {
        //best score: you can increase position to get to position 1+(# of people who beat you)
        //even if you "tied" with someone you can always get to their rank or better
        //worst score: everyone who you didn't beat can surpass you
        //only exception is if you scored perfect in x rounds cuz then there are some people
        //who you didn't beat, but they also can't surpass you so you will be at least as good as those ppl
        int hi = sum(a[i]+1, b[i]+1, 651, 651); print(hi+1, sp);
        int lo = sum(1, 1, a[i]-1, b[i]-1);
        if(a[i] == 651) lo += sum(1, b[i], 1, b[i]);
        if(b[i] == 651) lo += sum(a[i], 1, a[i], 1);
        print(n-lo, nl);
    }
}