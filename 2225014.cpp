#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define fl() cout << flush
#define scln(x) getline(cin, x)
void sc(){}template<class T, class...A> void sc(T&t, A&...a) { cin >> t, sc(a...); }
void pr(){}template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 1e6+1;

int n, q, a[MV]; ll f[MV], l, r; stack<int> s;
int main()
{
    //f[i]: how many subarrays have their minimum element = i
    //for a particular i, update every time u see an array element = i:
    //get number of subarrays with min = i and contains the middle element
    //calculate l[i]: position of left <= element and r[i]: position of right < element
    //avoids overcounting because in a section with multiple smallest elements,
    //each element will contribute all subarrays that contain this element and to the right
    //(never to the left)
    cin.sync_with_stdio(0); cin.tie(0); sc(n, q);
    for(int i = 1; i <= n; i++)
    {
        sc(a[i]);
        while(!s.empty() && a[i] < a[s.top()])
        {
            int idx = s.top(); s.pop(); r = i-idx;
            if(s.empty()) l = idx; else l = idx-s.top();
            f[a[idx]] += l*r;
        }
        s.push(i);
    }
    while(!s.empty())
    {
        int idx = s.top(); s.pop(); r = n-idx+1;
        if(s.empty()) l = idx; else l = idx-s.top();
        f[a[idx]] += l*r;
    }
    for(int i = 1; i < MV; i++) f[i] += f[i-1];
    for(int i = 1, x, y; i <= q; i++)
    {
        sc(x, y); pr(f[y]-f[x-1], nl);
    }
}