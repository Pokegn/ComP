#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(2*n+1);
        vector<int> d(2*n+1);

        for(int j=0; j<n; j++){
            cin >> a[j];
            if(j!=0 && a[j]==a[j-1]){
                c[a[j]]+=1;
            }
            else c[a[j]]=0;
        }
        for(int j=0; j<n; j++){
            cin >> b[j];
            if(j!=0 && b[j]==b[j-1]){
                d[b[j]]+=1;
            }
            else d[b[j]]=0;
        }

        for(int j=0; j<2*n+1; j++){
            c[j]+=d[j];
        }

        int max=0;
        for(int j=0; j<2*n+1; j++){
            if(c[j]>max) max=c[j];
        }

        cout << max << endl;
    }
}