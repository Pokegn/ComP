#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for(int j=0; j<n; j++){
            cin >> a[j];
            b[j]=n+1-a[j];
        }

        for(int j=0; j<n; j++){
            cout << b[j] << ' ';
        }
        cout << endl;
    }
}