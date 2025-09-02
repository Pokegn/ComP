#include<bits/stdc++.h>

using namespace std;

int main(){
    string a;
    cin >> a;
    int s = a.length();
    int cs=0;
    int cf=0;
    string b;

    for (int i=0; i<s; i++){
        if(a[i]=='.'){
            if(cs==1) cout << 1;
            else cout << 0;
            cs=0;
        }
        else{
            if(cs==1){
                cout << 2;
                cs=0;
            }
            else cs=1;
        }
    }
}