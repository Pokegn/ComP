#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int s=0;
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        s+=x;
    }

    cout << double(s)/n;
}