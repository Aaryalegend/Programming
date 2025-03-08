#include <bits/stdc++.h>
using namespace std;

int maxSumBruteForce(vector<int>& arr, int k) {
    int maxSum = INT_MIN;

    for (int i = 0; i <= arr.size() - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += arr[j];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Max Sum (Brute Force): " << maxSumBruteForce(arr, k) << endl;
    return 0;
}
