#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    scanf("%d %d %d", &a, &b, &c);
    cout << "The 1-3-sum is " << (91 + a + c + 3*b);
}