#include <bits/stdc++.h>
using namespace std;

vector<int> f(int n, vector<int> &dp) {
    // base case
    dp[0] = 0;
    if(n>=1) {
        dp[1] = 1;
    }

    // if(dp[n] != -1) {
    //     return dp;
    // }

    // recursive call
    for(int i=2; i<=n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp;
    
}

int main() {
    // Your code here
    int n; cin>>n;
    vector<int> dp(n+1, -1);
    // Get the Fibonacci series up to n
    vector<int> fib_series = f(n, dp);

    // Print the Fibonacci series
    for(int i = 0; i <= n; ++i) {
        cout << fib_series[i] << " ";
    }
    cout << endl;
    return 0;
}
