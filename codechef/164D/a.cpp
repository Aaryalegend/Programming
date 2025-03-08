#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n, p;
    cin>>n>>p;

    // If errors are present in at least half of the total lines, Ved will be labeled as a NEWBIENEWBIE.
    // Otherwise, he will be labeled as a PRO.

    if(p <= n/2) {
        cout<<"PRO"<<endl;
    } else {
        cout<<"NEWBIE"<<endl;
    }
}
