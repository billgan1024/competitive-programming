#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define nl '\n'
#define ms(x) memset(x, 0, sizeof(x))
#define sz(a) sizeof(a)/sizeof(a[0])
void scan(){}template<class T, class...A> void scan(T&t, A&...a) { cin >> t, scan(a...); }
void print(){}template<class T, class...A> void print(T t, A...a) { cout << t, print(a...); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

double x1, yy1, x2, y2, x3, y3, x4, y4, m1, m2;
bool eq(double x5, double yy5, double x6, double yy6)
{
    return x5 == x6 && yy5 == yy6;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(x1, yy1, x2, y2, x3, y3, x4, y4);
    if(x2 != x1 && x4 != x3)
    {
        m1 = (y2-yy1)/(x2-x1); m2 = (y4-y3)/(x4-x3);
        if(m1 == m2)
        {
            if(eq(x1, yy1, x3, y3) || eq(x1, yy1, x4, y4) || eq(x2, y2, x3, y3) || eq(x2, y2, x4, y4)) print("coincident", nl);
            else
            {
                double m = (y3-yy1)/(x3-x1);
                if(m == m1) print("coincident", nl);
                else print("parallel", nl);
            }
        }
        else
        {
            double x = y3-m2*x3-yy1+m1*x1; x /= (m1-m2); double y = m1*x - m1*x1 + yy1;
            print(fixed, setprecision(6), x, sp, y, nl);
        }
    }
    else
    {
        if(x2 == x1 && x4 == x3)
        {
            if(x1 == x3) print("coincident", nl);
            else print("parallel", nl);
        }
        else
        {
            if(x2 == x1)
            {
                m2 = (y4-y3)/(x4-x3);
                double x = x1, y = m2*x - m2*x3 + y3; print(fixed, setprecision(6), x, sp, y, nl);
            }
            else if(x4 == x3)
            {
                m1 = (y2-yy1)/(x2-x1);
                double x = x3, y = m1*x - m1*x1 + yy1; print(fixed, setprecision(6), x, sp, y, nl);
            }
        }
    }
}