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

int n, m, a[MV], b[MV], c[MV]; vector<int> lis; unordered_map<int, int> f;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 1; i <= n; i++)
    {
        //f: get index of an element in a (1-indexed) (a[i] -> i)
        scan(a[i]); f[a[i]] = i;
    }
    scan(m);
    //c[i] = position of a[i] in b (0 if not found), then get LIS since c[i] automatically keeps a[i] in order so
    //the lis in c gives the LCS corresponding to A and B (longest row of mappings from a[i] to b[i])
    for(int i = 1; i <= m; i++)
    {
        scan(b[i]);
        if(f[b[i]] != 0) c[f[b[i]]] = i;
    }
    //get lis in c (note that c[i] may equal 0 if a[i] is not found in b)
    //also no two c[i] are equal
    for(int i = 1; i <= n; i++)
    {
        if(c[i] == 0) continue;
        if(lis.empty() || c[i] > lis.back()) lis.pb(c[i]);
        else
        {
            int pos = lower_bound(lis.begin(), lis.end(), c[i]) - lis.begin();
            lis[pos] = c[i];
        }
    }
    print(sz(lis));
}