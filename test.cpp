#include <bits/stdc++.h>
using namespace std;


int findLongestConseqSubseq(int arr[], int n) {
    unordered_set<int> S;
    int ans = 0;
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
    // check each possible sequence from the start then update optimal length
    for (int i = 0; i < n; i++) {
        // if current element is the starting element of a sequence
        if (S.find(arr[i] - 1) == S.end()) {
            // Then check for next elements
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
            // update length if new length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

int main() {
    int n = 7;
    int arr[] = { 10,4,20,1,3,2 };
    cout << "Length of the Longest contiguous subsequence is :"
         << findLongestConseqSubseq(arr, n);
    return 0;
}
