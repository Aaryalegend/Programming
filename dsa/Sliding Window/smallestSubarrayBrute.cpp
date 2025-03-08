#include <bits/stdc++.h>
using namespace std;

int minSubArrayLenBruteForce(int S, vector<int>& arr) {
    int n = arr.size(), minLength = INT_MAX;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum >= S) {
                minLength = min(minLength, j - i + 1);
                break;
            }
        }
    }
    return (minLength == INT_MAX) ? 0 : minLength;
}

int main() {
    vector<int> arr = {2, 3, 1, 2, 4, 3};
    int S = 7;
    cout << "Min Length (Brute Force): " << minSubArrayLenBruteForce(S, arr) << endl;
    return 0;
}
