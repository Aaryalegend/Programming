#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        for(int z=0;z<=i;z++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}