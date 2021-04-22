#include <bits/stdc++.h>

using namespace std;

int ans[101], rep[101], sent[101];
int main()
{
    int m; scanf("%d", &m);
    char cmd;
    int n, t = 0;
    for(int i = 0; i < m; ++i)
    {
        cin >> cmd >> n;
        if(cmd == 'S') { ans[n] += t - sent[n]; rep[n] = 1; }
        else if(cmd == 'R') { rep[n] = -1; sent[n] = t; }
        else t += n-2;
        t++;
    }
    for(int j = 0; j < 101; j++)
    {
        if(rep[j])
        {
            if(rep[j] > 0)
                printf("%d %d\n", j, ans[j]);
            else printf("%d %d\n", j, rep[j]);
        }
    }
    return 0;
}