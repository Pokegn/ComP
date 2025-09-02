#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, x; cin >> n >> x;
    double k, sum=0;

    for(int i=0; i<n; i++){
        cin >> k;
        sum+=k;
    }
        
    cout << ceil(abs(sum)/(double) x);
}