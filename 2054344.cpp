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

int N, st[1000][10][1000][10];
int log2n(int n) 
{ 
    return (n > 1) ? 1 + log2n(n / 2) : 0; 
} 
void init(vector<vector<int>> arr)
{
    N = sz(arr);
    //initialize the sparse table (start w/ a sparse table for each row)
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N; i++) st[k][0][i][0] = arr[k][i];
        for(int j = 1; (1<<j) <= N; j++)
        {
            for(int i = 0; i + (1<<j) <= N; i++)
            {
                st[k][0][i][j] = min(st[k][0][i][j-1], st[k][0][i+((1<<(j-1)))][j-1]);
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
                st[k][l][j][0] = min(st[k][l-1][j][0], st[k+(1<<(l-1))][l-1][j][0]);
            }
            //complete this sparse table
            for(int j = 1; (1<<j) <= N; j++)
            {
                for(int i = 0; i + (1<<j) <= N; i++)
                {
                    st[k][l][i][j] = min(st[k][l][i][j-1], st[k][l][i+(1<<(j-1))][j-1]);
                }
            }
        }
    }
}

int query(int a, int b, int c, int d)
{
    int v = log2n(b-a+1), h = log2n(d-c+1);
    int m1 = st[a][v][c][h], m2 = st[b-(1<<v)+1][v][c][h];
    int m3 = st[b-(1<<v)+1][v][d-(1<<h)+1][h], m4 = st[a][v][d-(1<<h)+1][h];
    return min(min(min(m3, m4), m2), m1);
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
}