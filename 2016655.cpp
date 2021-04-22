#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int n, cnt; vector<int> ans;

void recur(int sum)
{
    if(sum == n)
    {
        cnt++; string s = to_string(n) + "=";
        for(int i : ans) s += to_string(i) + "+"; s.erase(sz(s)-1);
        print(s, nl);
    }
    else
    {
        for(int i = ans[sz(ans)-1]; i <= n-sum; i++)
        {
            ans.push_back(i); recur(sum+i); ans.erase(ans.end()-1);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n/2; i++)
    {
        ans.push_back(i); recur(i); ans.erase(ans.end()-1);
    }
    print("total=", cnt);
}