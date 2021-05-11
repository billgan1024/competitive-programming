#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f
#define sp ' '
#define nl '\n'
#define pb push_back
#define clz __builtin_clz
#define popcnt __builtin_popcount
#define fl() cout << flush
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc()
{
}
template <class T, class... A>
void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {}
template <class T, class... A>
void pr(T t, A... a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int a[100];

int partition(int l, int r)
{
    //note that arrays are called by reference
    int pivot = a[r]; // pivot
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        // If current element is smaller than the pivot
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(int l, int r)
{
    if (l < r)
    {
        //get the partition index from the quickSort function
        int p = partition(l, r);
        //quicksort the two halves if there was a valid pivot position
        quickSort(l, p - 1);
        quickSort(p + 1, r);
    }
}
int main()
{
    for (int i = 0; i < 100; i++)
        a[i] = rand() % 100;
    quickSort(0, 99);
    for (int i : a)
        pr(i, sp);
}
