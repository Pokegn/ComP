#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string s;

    for(int i=0; i<n; i++){
        cin >> s;
        int r=s.size();
        if(r>10){
            cout << s[0] << r-2 << s[r-1];
        }
        else{
            cout << s;
        }
        cout << endl;
    }
}