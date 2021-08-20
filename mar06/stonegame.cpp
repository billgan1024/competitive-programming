#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define clz __builtin_clz
#define clzll __builtin_clzll
#define popcnt __builtin_popcount
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)

void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }

typedef long long ll;
typedef pair<int, int> pii;
const int maxN = 1e6+1;

int N; ll f[maxN], ans;
int main() {
    cin.sync_with_stdio(0); cin.tie(0); sc(N);
    for(int i = 1, x; i <= N; i++) {
        sc(x); f[x]++;
    }
    for(int i = 1; i < maxN; i++) f[i] += f[i-1];
    for(int i = 1; i < maxN; i++) {
        //edge case: if there is one odd frequency but the value is 1, then it's still possible if you remove 1
        //the conditions is whether or not we can make all positive a[]/i have even frequencies
        int freq = 0, cntOdd = 0, idx = 0; bool prevOdd = false;
        for(int j = 1; i*j < maxN; j++) {
            //number of elements in the array that have a[]/i = j
            int s = f[min(maxN-1, i*(j+1)-1)]-f[i*j-1];
            cntOdd += s%2;     
            if(prevOdd && s%2) freq = s;
            prevOdd = s%2;
        }
        if(cntOdd == 2) ans += freq;
        else if(cntOdd == 1) {
            int s = f[min(maxN-1, 2*i-1)]-f[i-1];
            if(s % 2) ans += s;
        }
    }
    pr(ans);
}
/* let's sort this array. then, observe that after a person takes x stones, the entire array is now described by how many 
groups of x stones are in every pile. this value is precisely a[i]/x (floordiv)
then since the # of stones taken must divide the previous number, you can simply take some number of groups of stones,
and the process is repeated
in particular, you can rephrase the game as follows: you have an array, and two players take turns choosing a positive element
in the array (a[i]) and some # of groups of stones to take (k), then performing a/=k (considering the groups of k stones now
and a[i]-- (removing one group of k stones). the first player who is unable to move loses (i.e. the array is all zero)
then, consider a sorted array representing # of groups of stones in each pile. if the array has exactly one maximum, then you win
because you can take the max # of groups of stones, and after a/=max(a), you can subtract one to get an array of zeroes. this logic
also applies for an array with an odd # of maximums, since if you remove the max # of groups, you will get an array consisting
of an even # of 1s (with no other piles), thereby securing a win due to symmetry. 

You can generalize: given any first move with x stones removed,
it is winning iff array/x has exactly 2 odd frequencies
which are consecutive numbers.
This is because after the first group of stones is removed, you're only dealing with groups of x stones now, hence the 
floordiv operation. Then, you need to remove one element from array/x, so the above condition
needs to be satisfied (a/x[i]-- will manifest itself as f[i]--, f[i-1]++) so that there are an even number of every element at the end of your turn, so you can use symmetry 
to always win. Otherwise, the other player can use symmetry to always win by taking the highest # of groups of stones
that has an odd frequency. Then, after you floor divide (simulating the fact that you're now only considering groups of groups of stones) and take 
the highest odd frequency, the entire frequency array is even, meaning that you lose via symmetry. (basically use the logic in the first
paragraph)

You can compute the frequency array by querying # of elements in the original array between [kx, (k+1)x) simply using a
prefix sum array on the frequency (we convert it into a prefix sum array), then if there are exactly two consecutive odd frequencies,
add cnt by the frequency of the higher value.
 */