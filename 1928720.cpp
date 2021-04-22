#include <bits/stdc++.h>
using namespace std;
bool f(int N)
{
    for(int i = 2; i <= sqrt(N); i++)
    {
        if(N%i == 0) return false;
    }
    return true;
}
int main()
{
    return 0;
}