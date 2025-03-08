#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int S, vector<int>& arr) {
    int left = 0, sum = 0, minLength = INT_MAX;

    for (int right = 0; right < arr.size(); right++) {
        sum += arr[right]; // Expand window

        while (sum >= S) { // Contract window if condition met
            minLength = min(minLength, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }

    return (minLength == INT_MAX) ? 0 : minLength;
}

int main() {
    vector<int> arr = {2, 3, 1, 2, 4, 3};
    int S = 7;
    cout << "Min Length (Sliding Window): " << minSubArrayLen(S, arr) << endl;
    return 0;
}
