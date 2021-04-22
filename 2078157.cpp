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
const int MV = 1e6;

int n, a[MV], tmp[MV], m = INF, st;
int s(int i) { return (i+st+n)%n; }
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        scan(a[i]); if(a[i] < m) { m = a[i]; st = i; }
    }
    //brute force giving person st and person st-1 0 to a[st] dishes.
    for(int i = 0; i <= a[st]; i++)
    {
        //temp array for this simulation
        for(int j = 0; j < n; j++) tmp[j] = a[j];
        tmp[s(0)] -= i; tmp[s(-1)] -= i; 

        bool found = true; int cnt = i;
        vector<pii> moves; moves.pb({0, i});
        for(int j = 0; j < n-1; j++)
        {
            if(tmp[s(j+1)] < tmp[s(j)]) { found = false; break; }
            cnt += tmp[s(j)]; moves.pb({j+1, tmp[s(j)]});
            tmp[s(j+1)] -= tmp[s(j)]; tmp[s(j)] = 0;
        }
        if(found && tmp[s(n-1)] == 0)
        {
            //success
            print("YES", nl, cnt, nl);
            for(pii p : moves)
            {
                for(int j = 0; j < p.second; j++) print(s(p.first-1), sp, s(p.first), nl);
            }
            return 0;
        }
    }
    print("NO", nl);
}