#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    int i; for (i=0; i<t; i++){
        string x="YES";
        int n; cin >> n;
        int a[100];
        int j; for (j=0; j<n; j++){
            cin >> a[j];
            int k; for (k=0; k<j; k++){
                if (a[j]==a[k]) x="NO";
            }
        }
        cout << x << endl;
    }
}