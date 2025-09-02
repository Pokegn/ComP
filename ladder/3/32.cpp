#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    vector<int> a{4, 7, 44, 47, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    bool x=false;
    for(int i : a){
        if(n%i==0) x=true;
    }

    if(x==true) cout << "YES";
    else cout << "NO";
}