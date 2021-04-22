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
const int MV = 1e5+2;

int n, t; ll da[MV], db[MV], dc[MV];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, t);
    for(int i = 0, l, r; i < n; i++)
    {
        ll a, b, c, A, B, C; scan(l, r, a, b, c);
        A = a; B = b - 2*a*l; C = a*l*l - b*l + c;
        da[l] += A; da[r+1] -= A;
        db[l] += B; db[r+1] -= B;
        dc[l] += C; dc[r+1] -= C;
    }
    for(int i = 1; i <= t; i++)
    {
        da[i] += da[i-1]; db[i] += db[i-1]; dc[i] += dc[i-1];
        print(da[i]*i*i + db[i]*i + dc[i], sp);
    }
}