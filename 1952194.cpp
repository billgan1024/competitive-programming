#include <bits/stdc++.h>
using namespace std;
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }

int n, ans, pi, pj; unordered_map<int, int> freq;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(n); int arr[n];
    for(int i = 0, a; i < n; i++)
    {
        scan(a); arr[i] = a; freq[a]++;
    }
    sort(arr, arr+n);
    for(int i = n-1; i >= 2; i--)
    {
        if(arr[i] == pi) continue;
        pj = -1;
        if(arr[i]%2 == 0)
        {
            for(int j = 0; j < i; j++)
            {
                if(arr[j] >= arr[i]/2) break; if(arr[j] == pj) continue;
                if(freq[arr[i]-arr[j]] >= 1) ans++;
                pj = arr[j];
            }
            if(freq[arr[i]/2] >= 2) ans++;
        }
        else
        {
            for(int j = 0; j < i; j++)
            {
                if(arr[j] > arr[i]/2) break; if(arr[j] == pj) continue;
                if(freq[arr[i]-arr[j]] >= 1) ans++;
                pj = arr[j];
            }
        }
        pi = arr[i];
    }
    if(ans == 0) print(-1);
    else print(ans);
}