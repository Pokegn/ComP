#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<char> a(26,0);

    string x; cin >> x;
    for(int i=0; i<x.size(); i++){
        a[(x[i]-'A')]+=1;
    }
    string y; cin >> y;
    for(int i=0; i<y.size(); i++){
        a[(y[i]-'A')]+=1;
    }
    string z; cin >> z;
    for(int i=0; i<z.size(); i++){
        a[(z[i]-'A')]-=1;
    }
    string b="YES";
    for(int i=0; i<26; i++){
        if(a[i]!=0) b="NO";
    }

    cout << b;

}