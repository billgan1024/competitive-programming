#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    vector<int> v = {1, 2, 3};
    for(int x : v) {
        x++;
    }
    vector<pii> w = {{1, 2}, {3, 4}};
    for(auto [x, y] : w) {
        x++; y++;
    }
    for(auto x : w) pr(x.first, sp, x.second, nl);
}