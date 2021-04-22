#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, num, a[1000001], freq[1000001]; ll ans;
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    //time complexity: O(n)
    //sliding window with frequency map approach
    //frequency map shows the frequency of each number
    //if there is less than k distinct integers, increase r by 1
    //as soon as u hit k distinct integers, you know that ALL of the subarrays
    //after r (with l constant) will get another diverse subarray (# of distinct elements wont change)
    //thus add equal to (N - r) and finally increase l by 1
    //loop while r < N (last diverse array is when r = N-1 for when l cannot go up anymore)

    //you don't need to loop thru the freq array to get distinct numbers
    //u only need to update the # of disinct integers only when the window moves
    //if the new number adds to a freq[i] >= 1, it is not unique
    //otherwise it is unique (freq[i] == 1 -> add 1 to unique elements)
    //when a number is removed, if it makes freq[i] = 0, then subtract 1 from # of unique elements
    cin >> n >> k; for(int i = 0; i < n; i++) cin >> a[i];
    for(int l = 0, r = 0; r < n; r++)
    {
        if(freq[a[r]] == 0) num++; freq[a[r]]++;
        if(num < k) continue;
        while(num >= k)
        {
            ans += n-r; freq[a[l]]--; if(freq[a[l]] == 0) num--; l++;
        }
    }
    cout << ans << "\n";
}