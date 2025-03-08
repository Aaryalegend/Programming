#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int rows=n; rows>=1; rows--) {
        for(int cols=1; cols<=rows; cols++) {
            cout<<cols<<" ";
        }
        cout<<endl;
    }
    return 0;
}