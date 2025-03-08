#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--) {
        long long n, l, r;
        cin>>n>>l>>r;
        vector<int> v(n);
        for(int i=0; i<n; i++) {
            cin>>v[i];
        }

        // product of XOR of elements of the array
        long long product = 1;
        const long long MOD = 1e9 + 7;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                product *= (v[i]^v[j]);
                if(product>r || product==0) {
                    break;
                }
            }
            if(product>r || product==0) {
                break;
            }
        }

        // if product lies between l and r
        if(product>=l && product<=r) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}