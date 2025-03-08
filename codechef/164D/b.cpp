#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--) {
        int n,k,p;
        cin>>n>>k>>p;
        vector<int> v(n);
        for(int i=0; i<n; i++) {
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        int tallest = v.back();

        int ved = k+tallest;

        //sum of vector
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += v[i];
        }
        int varun = (p+sum)-tallest;

        if(ved>varun) {
            cout<<"Ved"<<endl;
        } 
        else if(ved<varun) {
            cout<<"Varun"<<endl;
        }
        else {
            cout<<"Equal"<<endl;
        }
    }
}
