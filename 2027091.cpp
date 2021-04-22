#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (short)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const short MV = 8193;

short n, arr[MV], f[MV][MV], bit[MV][MV]; int q;
short getSum(short r1, short c1, short r2, short c2)
{
    return f[r2][c2] - f[r1-1][c2] - f[r2][c1-1] + f[r1-1][c1-1];
}

short bitSum(short r, short c)
{
    short sum = 0;
    for(short r0 = r; r0 > 0; r0 -= r0&-r0)
    {
        for(short c0 = c; c0 > 0; c0 -= c0&-c0) sum += bit[r0][c0];
    }
    return sum;
}

void updateSub(short r, short c)
{
    for(short r0 = r; r0 <= n; r0 += r0&-r0)
    {
        for(short c0 = c; c0 <= n; c0 += c0&-c0) bit[r0][c0]--;
    }
}

void updateAdd(short r, short c)
{
    for(short r0 = r; r0 <= n; r0 += r0&-r0)
    {
        for(short c0 = c; c0 <= n; c0 += c0&-c0) bit[r0][c0]++;
    }
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(short i = 1; i <= n; i++) { scan(arr[i]); arr[i]++; }
    for(short i = 1; i <= n; i++)
    {
        for(short j = 1; j <= n; j++)
        {
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1];
            if(arr[j] == i) f[i][j]++;
            short ki = i&-i, kj = j&-j;
            bit[i][j] = getSum(i-ki+1, j-kj+1, i, j);
        }
    }

    scan(q);
    for(int i = 0; i < q; i++)
    {
        short cmd, l, r, a, b, x, h; scan(cmd);
        if(cmd == 1)
        {
            scan(l, r, a, b); l++; r++; a++; b++; 
            print(bitSum(b, r) - bitSum(a-1, r) - bitSum(b, l-1) + bitSum(a-1, l-1), nl);
        }
        else
        {
            scan(x, h); x++; h++; short old = arr[x]; arr[x] = h;
            updateSub(old, x); updateAdd(h, x);
        }
    }
}