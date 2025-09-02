#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int count4=0, count7=0;
    while(n%7!=0){
        if(n<0){
            cout << -1;
            return 0;
        }
        n-=4;
        count4+=1;
    }
    count7=n/7;

    for(int i=0; i<count4; i++){
        cout << '4';
    }
    for(int i=0; i<count7; i++){
        cout << '7';
    }
}