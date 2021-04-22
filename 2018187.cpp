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

int n, k, f[26]; string a; vector<char> b; vector<int> indices[26];
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n, k, a);
    if(k > n) { print("WRONGANSWER"); return 0; }
    else if(k == n) { print(a); return 0; }
    else
    {
        for(int i = 0; i < n; i++)
        {
            f[a[i]-'a']++; indices[a[i]-'a'].push_back(i);
        }
        for(int i = 0; i < 26; i++)
        {
            int cnt = sz(indices[i]);
            if(k >= cnt)
            {
                //found a character to use as the base of the remainder of string b
                if(cnt == 0)
                {
                    for(int j = 0; j < k; j++) b.push_back(a[j]);
                    while(sz(b) < n) b.push_back((char)(i+'a'));
                    for(char c : b) print(c);
                }
                else if(cnt == 1)
                {
                    int r = min(n-1, indices[i][0] + k - 1), rlen = r-indices[i][0] + 1;
                    int rem = k - rlen, l = indices[i][0] - rem;
                    for(int j = l; j <= r; j++) b.push_back(a[j]);
                    while(sz(b) < n) b.push_back((char)(i+'a'));
                    for(char c : b) print(c);
                }
                else
                {
                    for(int j = 0; j < cnt; j++) b.push_back((char)(i+'a')); int extra = 0;
                    int insertPos = 0;
                    for(int j = 0; j < n; j++)
                    {
                        if(a[j] != (char)(i+'a'))
                        {
                            b.insert(b.begin()+insertPos, a[j]); extra++;
                        }
                        insertPos++;
                        if(extra == k-cnt) break;
                    }
                    while(sz(b) < n) b.push_back((char)(i+'a'));
                    for(char c : b) print(c);
                }
                return 0;
            }
        }
        print("WRONGANSWER");
    }
}