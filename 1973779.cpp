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
const int MV = 100000;

ll n, m, a[MV+1], bit[MV+1], pre[MV+1], freq[MV+1], fpre[MV+1], fbit[MV+1]; char c;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    //i&-i represents the largest power of 2 that divides i (e.g. 6&-6 = 2, 8&-8 = 8, 7&-7 = 1)
    //note: binary indexed tree for elements has size n, binary indexed tree for frequencies has size 100000
    for(int i = 1; i <= n; i++)
    {
        scan(a[i]); pre[i] = pre[i-1] + a[i]; freq[a[i]]++; int k = i&-i;
        int l = i-k+1, r = i; bit[i] = pre[r]-pre[l-1];
    }
    for(int i = 1; i <= MV; i++)
    {
        fpre[i] = fpre[i-1] + freq[i]; int k = i&-i;
        int l = i-k+1, r = i; fbit[i] = fpre[r]-fpre[l-1];
    }

    for(int i = 0; i < m; i++)
    {
        scan(c); int x, v, l, r;
        if(c == 'C')
        {
            scan(x, v);
            //update binary indexed trees for the sum of elements and sum of frequencies
            int d = v-a[x];
            for(int j = x; j <= n; j += j&-j) bit[j] += d;
            for(int j = a[x]; j <= MV; j += j&-j) fbit[j]--;
            //finally, update the array value
            a[x] = v;
            for(int j = a[x]; j <= MV; j += j&-j) fbit[j]++;
        }
        else if(c == 'S')
        {
            scan(l, r); l--; ll lsum = 0, rsum = 0;
            for(int j = r; j >= 1; j -= j&-j) rsum += bit[j];
            for(int j = l; j >= 1; j -= j&-j) lsum += bit[j];
            print(rsum-lsum, nl);
        }
        else if(c == 'Q')
        {
            scan(v); int cnt = 0;
            for(int j = v; j >= 1; j -= j&-j) cnt += fbit[j];
            print(cnt, nl);
        }
    }
}