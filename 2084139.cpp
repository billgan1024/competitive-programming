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

int a, b, c, d, carbon, hydrogen;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0); scan(a, b, c, d);
    //first, you must connect all the carbons together using all the carbon to carbon bonds
    //this is because C-H bonds cannot connect the graph if it is unconnected
    //furthermore, all connected carbon arrangements can be collapsed into a line by flattening all junctions
    //since any 2 edges at a junction will add up to something less than 4 anyway
    //it also does not matter what the line order is, you will need a constant amount of C-H bonds
    //to make the whole hydrocarbon valid cuz the total missing outdegrees of the carbons renains the same
    carbon = a+b+c+1;
    if(a < c-1) print("invalid");
    else if(a == c-1)
    {
        if(b > 0) print("invalid");
        else
        {
            if(d == 2) print("C", carbon, "H", 2);
            else print("invalid");
        }
    }
    else
    {
        //the carbons can definitely be connected
        int target = 4*carbon - 2*(a+2*b+3*c);
        if(d == target) print("C", carbon, "H", target);
        else print("invalid");
    }
}