#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 8193;

int n, q, arr[MV], bit[MV][MV];

int sum(int r, int c)
{
    int sum = 0;
    for(int r0 = r; r0 > 0; r0 -= r0&-r0)
    {
        for(int c0 = c; c0 > 0; c0 -= c0&-c0) sum += bit[r0][c0];
    }
    return sum;
}

void update(int r, int c, int v)
{
    for(int r0 = r; r0 <= n; r0 += r0&-r0)
    {
        for(int c0 = c; c0 <= n; c0 += c0&-c0) bit[r0][c0] += v;
    }
}

int main()
{
    //implicit base array means that base[i][j] = 1 exactly when arr[j] = i
    //then this is the quantity that you are summing up in the BIT in 2 dimensions to get
    //the number of elements in the range 1...j with a value <= i, so add 1 to the cell (arr[i], i)
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++)
    {
        scan(arr[i]); arr[i]++;
        update(arr[i], i, 1);
    }

    scan(q);
    for(int i = 0; i < q; i++)
    {
        int cmd, l, r, a, b, x, h; scan(cmd);
        if(cmd == 1)
        {
            scan(l, r, a, b); l++; r++; a++; b++;
            print(sum(b, r) - sum(a-1, r) - sum(b, l-1) + sum(a-1, l-1), nl);
        }
        else
        {
            scan(x, h); x++; h++; int old = arr[x]; arr[x] = h;
            update(old, x, -1); update(h, x, 1);
        }
    }
}