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
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e5;

int N, l, a[60];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(N);
    for(int n = 0; n < N; n++)
    {
        scan(l); int ans = 0;
        for(int i = 0; i < l; i++) scan(a[i]);
        for(int i = l-1; i > 0; i--)
        {
            for(int j = 0; j < i; j++)
            {
                if(a[j] > a[j+1]) { ans++; swap(a[j], a[j+1]); }
            }
        }
        print(ans, nl);
    }
}