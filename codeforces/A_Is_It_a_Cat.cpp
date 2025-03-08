#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
     cin>>t;
    while(t--) {
        int n;
        string s;
        cin>>n>>s;

        string target = "meow";

        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });

        unordered_set<char> seen;
        string result;

        bool isE = false, isO = false, isW = false;

        for (char ch : s) {
            if(ch=='e') isE = true;
            if(ch=='o') isO = true;
            if(ch=='w') isW = true;

            if((ch=='m' && isE) || ((ch=='e' || ch=='m') && isO) || ((ch=='e' || ch=='m' || ch=='o') && isW)) {
                result+='z';
                break;
            }

            if (seen.find(ch) == seen.end()) {
                seen.insert(ch);
                result += ch;
            }
        }

        if(result == target) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}