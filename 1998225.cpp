#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MV = 1e6+1;

string s; int n, sa[MV], sb[MV], sc[MV], ta, tb, tc, ans = INT_MAX;
int freq(int x[], int r, int l)
{
    return x[r]-x[l-1];
}
void check(int x[], int y[], int i)
{
    //checks the min swaps needed if x and y are contiguous blocks in [i-sx-sy+1, i] and updates ans
    //mx = mismatches in x's block, my = mismatches in y's block
    //xy = # of xs in y, yx = # of ys in x
    int tx = x[n], ty = y[n];
    int mx = tx - freq(x, i-ty, i-tx-ty+1), my = ty - freq(y, i, i-ty+1);
    int xy = freq(x, i, i-ty+1), yx = freq(y, i-ty, i-tx-ty+1);
    ans = min(ans, mx + my - min(xy, yx));
    mx = tx - freq(x, i, i-tx+1); my = ty - freq(y, i-tx, i-tx-ty+1);
    xy = freq(x, i-tx, i-tx-ty+1); yx = freq(y, i, i-tx+1);
    ans = min(ans, mx + my - min(xy, yx));
}
int main()
{
    //note: order matters in the final configuration because it evolves from the original configuration,
    //this is why we test all possible final configurations
    //also, swapping people is equivalent to removing a mismatch from a designated block of elements
    //because we can always find a particular element outside the block to swap the mismatch with,
    //therefore making progress towards completing the block of elements
    //finally, the best approach will save swaps when we can swap two corresponding mismatches
    //in the two designated blocks of elements (2 corrections for 1 swap instead of 1)
    //it will save min(# of x in y's block, # of y in x's block) because the mismatch AND the particular
    //element are put in their correct location, compared to before where only the particular element
    //was guaranteed to be put in the correct position after the swap
    cin.sync_with_stdio(0); cin.tie(0); scan(s); n = sz(s);
    for(int i = 1; i <= n; i++)
    {
        sa[i] = sa[i-1] + (s[i-1] == 'A');
        sb[i] = sb[i-1] + (s[i-1] == 'B');
        sc[i] = sc[i-1] + (s[i-1] == 'C');
    }
    int ta = sa[n], tb = sb[n], tc = sc[n];
    for(int i = ta+tb; i <= n; i++)
    {
        //check all configurations which have 'A' and 'B' in a contiguous block
        check(sa, sb, i);
    }
    for(int i = ta+tc; i <= n; i++)
    {
        //check all configurations which have 'A' and 'C' in a contiguous block
        check(sa, sc, i);
    }
    for(int i = tb+tc; i <= n; i++)
    {
        //check all configurations which have 'B' and 'C' in a contiguous block
        check(sb, sc, i);
    }
    print(ans);
}