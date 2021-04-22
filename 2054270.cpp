#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define pb push_back
#define ms(x) memset(x, 0, sizeof(x))
#define sz(x) x.size()
#define scln(x) getline(cin, x)
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef pair<int, int> pii;

int N, st[10][10][1000][1000];
int Log2n(int n) 
{ 
    return (n > 1) ? 1 + Log2n(n / 2) : 0; 
} 
void init(vector<vector<int>> arr)
{
    N = sz(arr);
    //initialize the sparse table (start w/ a sparse table for each row)
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N; i++) st[0][0][i][k] = arr[k][i];
        for(int j = 1; (1<<j) <= N; j++)
        {
            for(int i = 0; i + (1<<j) <= N; i++)
            {
                st[j][0][i][k] = min(st[j-1][0][i][k], st[j-1][0][i+((1<<(j-1)))][k]);
            }
        }
    }

    //build the rest of the sparse table
    for(int l = 1; (1<<l) <= N; l++)
    {
        for(int k = 0; k + (1<<l) <= N; k++)
        {
            //initialize this sparse table
            for(int j = 0; j < N; j++)
            {
                st[0][l][j][k] = min(st[0][l-1][j][k], st[0][l-1][j][k+(1<<(l-1))]);
            }
            //complete this sparse table
            for(int j = 1; (1<<j) <= N; j++)
            {
                for(int i = 0; i + (1<<j) <= N; i++)
                {
                    st[j][l][i][k] = min(st[j-1][l][i][k], st[j-1][l][i+(1<<(j-1))][k]);
                }
            }
        }
    }
}

int query(int a, int b, int c, int d)
{
    int v = Log2n(b-a+1), h = Log2n(d-c+1);
    int m1 = st[h][v][c][a], m2 = st[h][v][c][b-(1<<v)+1];
    int m3 = st[h][v][d-(1<<h)+1][b-(1<<v)+1], m4 = st[h][v][d-(1<<h)+1][a];
    return min(min(min(m3, m4), m2), m1);
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); /*vector<vector<int>> a;
    a.pb({1, 2}); a.pb({3, 4}); init(a);
    print(query(0, 1, 0, 1), nl);
    print(query(1, 1, 0, 1), nl);
    print(query(0, 0, 1, 1), nl);*/
}