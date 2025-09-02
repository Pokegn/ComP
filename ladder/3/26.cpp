#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    int k=0;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    
    k=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]<=n) k+=1;
    }

    cout << n-k;
}