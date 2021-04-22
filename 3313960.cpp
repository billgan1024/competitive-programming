#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n; ll psa[3001], dp[3001][3001];
int main()
{
    //dp[i][j] = maximum value obtainable by the player who goes first in the range [i, j]
    //this can apply to both players taro and jiro (i.e. dp state when taro goes first relies
    //on the same previous states when jiro goes first; it is the same dp cell)
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
	for(int i=1; i<=n; i++) {
		scan(psa[i]); dp[i][i] = psa[i];
		psa[i] += psa[i-1];
	}
	for(int len=2; len<=n; len++) {
		for(int lft=1; lft+len-1<=n; lft++) {
			int rit = lft + len - 1; 
			dp[lft][rit] = psa[rit] - psa[lft-1] - min(dp[lft+1][rit], dp[lft][rit-1]);
		}
	}
	print(2*dp[1][n] - psa[n]);
}