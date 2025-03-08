#include<iostream>
using namespace std;

int main() {
    int n; cin>>n;
    for(int rows=1; rows<=n; rows++) {
        for(int cols=n; cols>=1; cols--) {
            if(rows>=cols) {
                cout<<"* ";
            } else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}