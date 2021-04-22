#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e6+1;

int n; vector<int> lis;
//note: to reconstruct the lis, keep a prev[] array for each element i (0 <= i < n)
//when you loop from the elements, after putting a[i] into the list, add the element
//that is directly before a[i] in the list to prev[i]
//finally, start with the last element in the list (keep track of the index of the last element in the list)
//and go backwards using prev
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0, x; i < n; i++)
    {
        scan(x);
        //no duplicates(x > lis.back())
        if(lis.empty() || x > lis.back()) lis.pb(x);
        else
        {
            //if x is already in the list, lower bound replaces it (no duplicates in strictly increasing subsequence)
            int pos = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
            lis[pos] = x;
        }
    }
    print(sz(lis));
}