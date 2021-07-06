#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;

//first idea: separate positive intervals from negative intervals, then for every positive interval, find the position 
//which incurs the least cost when the negative intervals are also applied at that point, or don't choose this interval if the cost is greater
//than the value of the positive interval
//however, you have no good way of deleting used negative intervals in less than O(n) time, so this won't work
//alternate idea: consider the recursive algorithm f(i) that finds the best valued string of length i using all of the intervals.
// if the last character is a 0, then the answer is equal to f(i-1)
// if the last character is a 1, then the answer is equal to f(i-1) + value of all 'unused' segments intersecting position i
//however, there's no way we can maintain information about what segments were already chosen between recursive calls in optimal complexity
//(we need to upgrade the state to store previously taken segments to avoid taking them again)
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
}