#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n; string ans; vector<char> chars;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n);
    for(int i = 0; i < n; i++)
    {
        char c; scan(c); chars.push_back(c);
    }
    while(chars.size() > 1)
    {
        if(chars[0] < chars[chars.size()-1])
        {
            ans += chars[0]; chars.erase(chars.begin());
        }
        else if(chars[chars.size()-1] < chars[0])
        {
            ans += chars[chars.size()-1]; chars.erase(chars.end()-1);
        }
        else
        {
            int l = 1, r = chars.size()-2; bool found = false;
            while(l < r)
            {
                if(chars[l] < chars[r])
                {
                    ans += chars[0]; chars.erase(chars.begin()); found = true; break;
                }
                else if(chars[r] < chars[l])
                {
                    ans += chars[chars.size()-1]; chars.erase(chars.end()-1); found = true; break;
                }
                l++; r--;
            }
            if(!found)
            {
                ans += chars[0]; chars.erase(chars.begin());
            }
        }
    }
    print(ans, chars[0]);
}