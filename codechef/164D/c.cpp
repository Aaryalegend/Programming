#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s, t;

        cin>>n>>s>>t;
        int count_ones_s = count(s.begin(), s.end(), '1');
        int count_zeros_s = count(s.begin(), s.end(), '0');

        int count_ones_t = count(t.begin(), t.end(), '1');
        int count_zeros_t = count(t.begin(), t.end(), '0');

        int cnt_1 = count_ones_s + count_ones_t;
        int cnt_0 = count_zeros_s + count_zeros_t;

        if(cnt_1 == cnt_0 || count_ones_s == count_ones_t || count_zeros_s == count_zeros_t) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}
