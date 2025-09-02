#include<bits/stdc++.h>

using namespace std;

int main(){
    string a; cin >> a;
    string b; cin >> b;

    int s=a.size();
    int r=0;

    for(int i=0; i<s; i++){
        if(a[i]>'Z') a[i]-=25;
        if(b[i]>'Z') b[i]-=25;

        if(a[i]<b[i]){
            r=-1;
            break;
        }
        if(a[i]>b[i]){
            r=1;
            break;
        }
    }

    cout << r;
}