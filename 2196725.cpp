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

int n, psa[1302][652], psb[1302][652], a[MV], b[MV], rk[MV]; pii s[MV];
int S(int a[][652], int r1, int c1, int r2, int c2) { return a[r2][c2] - a[r1-1][c2] - a[r2][c1-1] + a[r1-1][c1-1]; }
int main()
{
    //psa[i][j] stores the number of people who scored a total of i points with the first round score
    //less than or equal to j (same thing with psb)
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        scan(a[i], b[i]); int sum = a[i]+b[i]; s[i] = {sum, i};
        psa[sum+1][a[i]+1]++; psb[sum+1][b[i]+1]++;
    }
    sort(s, s+n); int pos = 1; rk[s[n-1].second] = pos;
    for(int i = n-2; i >= 0; i--)
    {
        if(s[i].first < s[i+1].first) pos = n-i;
        rk[s[i].second] = pos;
    }
    //integrate the 2d prefix sum array
    for(int i = 1; i <= 1301; i++)
    {
        for(int j = 1; j <= 651; j++)
        {
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
            psb[i][j] += psb[i-1][j] + psb[i][j-1] - psb[i-1][j-1];
        }
    }
    for(int i = 0; i < n; i++)
    {
        int cur = a[i] + b[i], x = rk[i];
        //lowest (best) pos u can get = x - number of people who didn't beat u in the range x+1 to x+650
        //this equals the rectangle sum (row = cur+1 to min(1300, cur+650), col = 0 to a[i]) before shifting everything by 1
        //get same sum from psb because people who didn't beat u and scored higher than u will have
        //exactly one of their a-score and b-score less than or equal to yours

        int sa = S(psa, cur+2, 1, min(1300, cur+650)+1, a[i]+1);
        int sb = S(psb, cur+2, 1, min(1300, cur+650)+1, b[i]+1);
        print(x-sa-sb, sp);

        //highest (worst) pos u can get = x + number of people who you didnt beat in the range x-649 to x
        //= rectangle sum (row = max(0, cur-649) to cur-1, col = a[i] to 650) + bonus

        sa = S(psa, max(0, cur-649)+1, a[i]+1, cur, 651);
        sb = S(psb, max(0, cur-649)+1, b[i]+1, cur, 651);
        int bonus = S(psa, cur+1, 1, cur+1, 651) - 1;
        print(x+sa+sb+bonus, nl);
    }
}