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
const int N = 131072;

int n, m, segMin[2*N], segGCD[2*N], segCount[2*N];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, m);
    //original array is 0-indexed (0 to N-1), segment trees are 1-indexed (1 to 2N-1)
    //segMin: segment tree tracking the minimum of a range
    //segGCD: segment tree tracking the GCD of a range
    //segCount: segment tree tracking the # of numbers equal to the GCD of a range
    for(int i = 0, a; i < N; i++)
    {
        if(i < n) scan(a); else a = 0;
        int p = i+N; segMin[p] = a; segGCD[p] = a; segCount[p] = 1;
        while(p % 2 == 1 && p != 1)
        {
            segMin[p/2] = min(segMin[p], segMin[p-1]); int g = __gcd(segGCD[p], segGCD[p-1]);
            segGCD[p/2] = g;
            if(g == segGCD[p] && g == segGCD[p-1]) segCount[p/2] = segCount[p] + segCount[p-1];
            else if(g == segGCD[p]) segCount[p/2] = segCount[p];
            else if(g == segGCD[p-1]) segCount[p/2] = segCount[p-1];
            p /= 2;
        }
    }

    for(int i = 0; i < m; i++)
    {
        char cmd; int x, v, l, r; scan(cmd);
        if(cmd == 'C')
        {
            scan(x, v); x += N-1; segMin[x] = v; segGCD[x] = v;
            while(x != 1)
            {
                //propagate the updated values upwards in the segment trees
                if(x % 2 == 0)
                {
                    segMin[x/2] = min(segMin[x], segMin[x+1]); int g = __gcd(segGCD[x], segGCD[x+1]);
                    segGCD[x/2] = g;
                    if(g == segGCD[x] && g == segGCD[x+1]) segCount[x/2] = segCount[x] + segCount[x+1];
                    else if(g == segGCD[x]) segCount[x/2] = segCount[x];
                    else if(g == segGCD[x+1]) segCount[x/2] = segCount[x+1];
                    else segCount[x/2] = 0;
                }
                else
                {
                    segMin[x/2] = min(segMin[x], segMin[x-1]); int g = __gcd(segGCD[x], segGCD[x-1]);
                    segGCD[x/2] = g;
                    if(g == segGCD[x] && g == segGCD[x-1]) segCount[x/2] = segCount[x] + segCount[x-1];
                    else if(g == segGCD[x]) segCount[x/2] = segCount[x];
                    else if(g == segGCD[x-1]) segCount[x/2] = segCount[x-1];
                    else segCount[x/2] = 0;
                }
                x /= 2;
            }
        }
        else if(cmd == 'M')
        {
            scan(l, r); l += N-1; r += N-1; int ans = INT_MAX;
            while(l <= r)
            {
                if(l % 2 == 1) { ans = min(ans, segMin[l]); l++; }
                if(r % 2 == 0) { ans = min(ans, segMin[r]); r--; }
                l /= 2; r /= 2;
            }
            print(ans, nl);
        }
        else
        {
            //query GCD and count segtree
            //while gathering the range, update answer and count, which stores the gcd and
            //# of elements which are the gcd in the current range
            scan(l, r); l += N-1; r += N-1; int ans = 0, cnt = 0;
            while(l <= r)
            {
                if(l % 2 == 1)
                {
                    int g = __gcd(ans, segGCD[l]);
                    if(g == ans && g == segGCD[l]) cnt += segCount[l];
                    else if(g == segGCD[l]) cnt = segCount[l];
                    else if(g != ans) cnt = 0;
                    ans = g; l++;
                }
                if(r % 2 == 0)
                {
                    int g = __gcd(ans, segGCD[r]);
                    if(g == ans && g == segGCD[r]) cnt += segCount[r];
                    else if(g == segGCD[r]) cnt = segCount[r];
                    else if(g != ans) cnt = 0;
                    ans = g; r--;
                }
                l /= 2; r /= 2;
            }
            if(cmd == 'G') print(ans, nl);
            else print(cnt, nl);
        }
    }
}