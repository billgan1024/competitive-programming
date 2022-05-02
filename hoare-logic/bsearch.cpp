#include <bits/stdc++.h>
using namespace std;
int lowsearch(int A[], int key, int n) {
    // A sorted ∧ A[0] ≤ key ≤ A[n-1]

    // A[-1] := -infinity, A[n] := infinity 

    int low = 0;
    int high = n - 1;
    int ans = n;
    // A sorted ∧ A[0] ≤ key ≤ A[n-1]

    // ans = high+1 ∧ A[low-1] < key <= A[high+1] 
    while (low <= high) {
        // low <= high ∧ ans = high+1 ∧ A[low-1] < key <= A[high+1]
        // ans = high+1 ∧ A[low-1] < key <= A[high+1]

        int mid = (low + high)/2;
        if (A[mid] >= key) {
            // A[mid] >= key ∧ ans = high+1 ∧ A[low-1] < key <= A[high+1]
            // mid = mid ∧ A[low-1] < key <= A[mid]

            // mid = mid ∧ A[low-1] < key <= A[mid] 
            ans = mid;
            // ans = mid ∧ A[low-1] < key <= A[mid] 
            high = mid-1;
            // ans = high+1 ∧ A[low-1] < key <= A[high+1] 
        } else {
            // A[mid] < key ∧ ans = high+1 ∧ A[low-1] < key <= A[high+1]
            // ans = high+1 ∧ A[mid] < key <= A[high+1]

            // ans = high+1 ∧ A[mid] < key <= A[high+1]
            low = mid+1;
            // ans = high+1 ∧ A[low-1] < key <= A[high+1] 
        }
        // ans = high+1 ∧ A[low-1] < key <= A[high+1]
    }

    // ans = high+1 ∧ A[low-1] < key <= A[high+1] ∧ low > high
    // ans = high+1 ∧ A[low-1] < key <= A[high+1] ∧ low >= high+1
    // ans = high+1 ∧ A[low-1] < key <= A[high+1] ∧ low-1 < high+1 ∧ low >= high+1
    // ans = high+1 ∧ A[low-1] < key <= A[high+1] ∧ low <= high+1 ∧ low >= high+1
    // ans = high+1 ∧ A[low-1] < key <= A[high+1] ∧ low = high+1
    // ans = high+1 ∧ A[high] < key <= A[high+1]
    // A[ans-1] < key <= A[ans]
    // ∀ i, 0 ≤ i ≤ ans-1 → A[i] < key ∧ ans ≤ i ≤ n → A[i] ≥ key
    return ans;
}

int main() {
    int a[] = {1, 5, 6, 7};
    printf("%d", lowsearch(a, 8, 4)); 
}