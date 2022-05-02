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
const int MN = 5e5+1;

int N, M; multiset<int> s;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N, M);
    //take the smallest one, then the highest one
    for(int i = 1, x; i <= N; i++) { sc(x); s.insert(x); }
    int x = -1;
    vector<int> ans;
    while(!s.empty()) {
        //take the first element greedily to construct an array such that 
        //every pair has sum >= M
        if(x == -1) {
            auto c = s.begin();
            ans.pb(*c); x = *c; s.erase(c); 
        } else {
            auto c = s.lower_bound(M-x);
            if(c == s.end()) { pr(-1); return 0; }
            ans.pb(*c); s.erase(c);
            x = -1;
        }
    }
    for(int x : ans) pr(x, sp);
}
