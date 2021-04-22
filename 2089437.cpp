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

int b, n; deque<char> c = {'A', 'B', 'C', 'D', 'E'};
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    while(true)
    {
        scan(b, n);
        if(b == 4)
        {
            for(char ch : c) print(ch, sp); return 0;
        }
        else if(b == 1)
        {
            for(int i = 0; i < n; i++) { char ch = c.front(); c.pop_front(); c.pb(ch); }
        }
        else if(b == 2)
        {
            for(int i = 0; i < n; i++) { char ch = c.back(); c.pop_back(); c.push_front(ch); }
        }
        else if(b == 3)
        {
            if(n % 2 == 1)
            {
                char c0 = c.front(); c.pop_front(); char c1 = c.front(); c.pop_front();
                c.push_front(c0); c.push_front(c1);
            }
        }
    }
}