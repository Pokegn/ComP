#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
 
        int n;
        cin >> n;
        vector<int> nuevo(n-1);
        vector<int> original(n);
 
        for (int j=0; j<n-1; j++) cin >> nuevo[j];
 
        for (int j=0; j<n; j++){
            
            if (j == 0) original[j] = nuevo[0];
            if (j == n-1) original[j] = nuevo[n-2];
 
            if (j != 0 and j!= n-1) original[j] = min(nuevo[j], nuevo[j-1]);
        }
 
        for (int j=0; j<n; j++) cout << original[j] << ' ';
 
        cout << endl;
 
    }
        
}