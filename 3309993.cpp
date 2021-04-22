//
// Created by billg on 12/19/2020.
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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

void sc() {}

template<class T, class...A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }

void pr() {}

template<class T, class...A>
void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n; string s;
int main() {
	sc(n);
	for(int i = 0; i < n; i++)
	{
		sc(s); set<char> c;
		for(char ch : s) c.insert(ch);
		bool a = c.find('C') != c.end(), b = c.find('M') != c.end();
		if(a && b) pr("NEGATIVE MARKS", nl);
		else if(a || b) pr("FAIL", nl);
		else pr("PASS", nl);
	}
}