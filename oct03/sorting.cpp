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
#define flush cout << flush
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<ll, int> pii;
template<typename T, typename X, class cmp = less<T>> using ordered_set = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;
//since we know a[k] = x, we know that there exists a subarray with all elements = x touching position k
//we thus need to find f[x] = f[i] and make a subarray of f[x] elements all with value x touching position k
//such that x-1 frequencies sum to the number of cells in the left space and
//n-x frequencies sum to the number of cells in the right space
//observation: we can assign f[x] to be the maximum frequency of any element. assume we find a valid configuration
//where f[x] is not maximal; then you can always f[x] with the maximal frequency such that the subarray of x's still
//covers position k. (find the position of the segment of one element with the maximum length, then swap these two subarray positions,
//then swap the elements in the subarrays so that you now have an x-subarray of maximal length)

//sort the frequencies
//track the minimum left and maximum right position of the x-subarray (let's call that the range)
//min left -> max left = left range
//if the range touches the ends of the original array of m elements (let's say it touches the left end),
//this is easy because we only need to check if the minimum sum of x-1 frequencies touches the left range
//otherwise, we know that the left range has a span equal to the maximal length
//this means that starting from the minimum sum of x-1 frequencies, we can shift the prefix sum upwards
//(sliding window sum) and it is guaranteed to eventually land inside the left range since we're only increasing
//the sum by x-y where x-y < length of the left range

const int maxN = 2e5+1;
ll n, x, k, m; pii f[maxN]; int ans[maxN];
int main() {
	//f[i].second = original index of this element in the frequency array
	cin.sync_with_stdio(0); cin.tie(0); sc(n, m, k, x); for(int i = 1; i <= n; i++) { sc(f[i].first); f[i].second = i; }
	sort(f+1, f+n+1); ll len = f[n].first, minLeft = max(1LL, k-len+1), maxRight = min(m, k+len-1);
	ll maxLeft = maxRight-len+1, minRight = minLeft+len-1;
	ll sum = 0;
	if(maxRight == m) {
		//edge case: check this array in reverse (check if the n-x smallest frequencies fall in the range)
		//this is the only case that the left range is smaller than normal while not being a prefix, but using our observation
		//above, we know that since the right range is a suffix, putting f[x+1]+f[x+2]+...+f[n] elements at the end must not
		//displace the x-subarray such that it doesn't touch the minimum right position
		for(int i = 1; i <= n-x; i++) sum += f[i].first;
		if(m-sum+1 > minRight) {
			//assign the first n-x smallest frequencies to the end elements x+1, x+2, ..., n
			int cnt = 1;
			for (int j = 1; j <= n; j++) {
				if (j <= n-x) ans[f[j].second] = j+x;
				else if (j == n) ans[f[j].second] = x;
				else ans[f[j].second] = cnt++;
			}
			for (int j = 1; j <= n; j++) pr(ans[j], sp);
			return 0;
		}
	} else {
		for(int i = 0; i < n; i++) {
			sum += f[i].first;
			if(i >= x-1) {
				//subtract to update sliding window (i=x-1 is accounted for in this loop)
				sum -= f[i - x + 1].first;
				//check if this point intersects the left range (note the off by one check since (minLeft, maxLeft) =
				//min, max left position of the subarray
				//note that the left boundary edge case is accounted for in this setup
				if (sum >= minLeft - 1 && sum < maxLeft) {
					//assign the x-1 frequencies to 1, 2, ... x-1
					int cnt = x+1;
					for (int j = 1; j <= n; j++) {
						if (j > i-x+1 && j <= i) ans[f[j].second] = j-i+x-1;
						else if (j == n) ans[f[j].second] = x;
						else ans[f[j].second] = cnt++;
					}
					for (int j = 1; j <= n; j++) pr(ans[j], sp);
					return 0;
				}
			}
		}
	}
	pr(-1, nl);
}