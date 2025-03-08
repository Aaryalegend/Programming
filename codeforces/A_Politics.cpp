#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
     cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<string> v(n);
        for(int i=0; i<n; i++) {
            cin>>v[i];
        }

        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(v[0]==v[i]) cnt++;
        }

        cout<<cnt<<endl;
    }
}