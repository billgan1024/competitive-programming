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
const int MV = 5e5+1;

int n, a[MV], cnt, L, R, ans; vector<int> f, c[2*MV-1];
int main()
{
    //c[i]: a vector storing the positions of cards which have the centre at i (centre is multiplied by 2)
    //when you rotate, you increase delta by the # of elements in that subarray range in c[i]
    //however, you need to decrease delta by the # of elements which were originally fixed points
    //and are now displaced (# of elements in that subarray range in f)
    //note that if an element is at the centre of a rotation, the +delta and -delta will cancel out
    //there are a total of n elements in the array of centre vectors so it is nlogn
    cin.sync_with_stdio(0); cin.tie(0); sc(n);
    for(int i = 1; i <= n; i++)
    {
        sc(a[i]); if(a[i] == i) { cnt++; f.pb(i); } c[i + a[i]].pb(i);
    }
    for(int cen = 2; cen <= 2*n; cen++)
    {
        for(int i : c[cen])
        {
            int l = i, r = cen-i; if(l > r) swap(l, r);
            int d = upper_bound(c[cen].begin(), c[cen].end(), r) - lower_bound(c[cen].begin(), c[cen].end(), l);
            d -= upper_bound(f.begin(), f.end(), r) - lower_bound(f.begin(), f.end(), l);
            if(ans < cnt+d)
            {
                ans = cnt+d; L = a[l]; R = a[r];
            }
        }
    }
    pr(L, sp, R, nl);
}