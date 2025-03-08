#include <bits/stdc++.h>
using namespace std;

int maxSumSlidingWindow(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;

    int windowSum = 0, maxSum = 0;

    // Compute the sum of first window
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k]; // Add new element, remove old element
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Max Sum (Sliding Window): " << maxSumSlidingWindow(arr, k) << endl;
    return 0;
}
