#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;
const int MV = 5e5;

int n, q, a[MV+1], pm[MV+2], sm[MV+2], pc[MV+2], sc[MV+2];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, q);
    for(int i = 1; i <= n; i++)
    {
        scan(a[i]); pm[i] = max(a[i], pm[i-1]);
        if(a[i] > pm[i-1]) pc[i] = 1;
        else if(a[i] == pm[i-1]) pc[i] = pc[i-1] + 1;
        else pc[i] = pc[i-1];
    }
    for(int i = n; i > 0; i--)
    {
        sm[i] = max(a[i], sm[i+1]);
        if(a[i] > sm[i+1]) sc[i] = 1;
        else if(a[i] == sm[i+1]) sc[i] = sc[i+1]+1;
        else sc[i] = sc[i+1];
    }
    for(int i = 0, a, b; i < q; i++)
    {
        scan(a, b);
        if(pm[a-1] > sm[b+1]) print(pm[a-1], sp, pc[a-1], nl);
        else if(pm[a-1] < sm[b+1]) print(sm[b+1], sp, sc[b+1], nl);
        else print(pm[a-1], sp, pc[a-1] + sc[b+1], nl);
    }
}