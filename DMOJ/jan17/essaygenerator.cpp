#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("Ofast")
#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int w;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    sc(w); int cnt = 0;
    for(int i = 0; i < 26; i++)
    {
        if(cnt == w) return 0;
        char c = (char)(i+'a');
        pr(c, sp);
        cnt++;
    }
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(cnt == w) return 0;
            char c = (char)(i+'a'), d = (char)(j+'a');
            pr(c, d, sp);
            cnt++;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            for(int k = 0; k < 26; k++) {
                if (cnt == w) return 0;
                char c = (char) (i + 'a'), d = (char) (j + 'a'), e = (char)(k+'a');
                pr(c, d, e, sp);
                cnt++;
            }
        }
    }
}