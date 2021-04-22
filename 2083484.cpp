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

int n; string s;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        scan(s);
        for(char c : s)
        {
            if(c == 'a' || c == 'A') print("Hi!", sp);
            else if(c == 'e' || c == 'E') print("Bye!", sp);
            else if(c == 'i' || c == 'I') print("How are you?", sp);
            else if(c == 'o' || c == 'O') print("Follow me!", sp);
            else if(c == 'u' || c == 'U') print("Help!", sp);
            else if(isdigit(c)) print("Yes!", sp);
        }
        print(nl);
    }
}